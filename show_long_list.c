#include <dirent.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>

#include "libft/libft.h"
#include "include/ft_ls.h"

void	show_long(DIR *dir, char *source, struct col_len *maxclen)
{
	struct stat		*buff;
	struct dirent	*entry;
	char			*file;
	char			*total_str;

	buff = (struct stat *)malloc(sizeof(struct stat));
	total_str = ft_itoa(maxclen->total);
	write(1, "total ", 6);
	ft_putstr(total_str);
	write(1, "\n", 1);
	free(total_str);
	while ((entry = readdir(dir)) != NULL)
	{
		if(g_flags.a == 0 && *(entry->d_name) == '.')
			continue;
		file = ft_strjoin(source, entry->d_name);
		stat(file, buff);
		free(file);
		first_colon(buff, maxclen);
		second_colon(buff, maxclen, entry->d_name);
	}
	free(buff);
}

void	check_maxlen(struct stat *buff, struct col_len *maxclen)
{
	if (buff->st_nlink > maxclen->links)
		maxclen->links = buff->st_nlink;
	if ((int)ft_strlen(getpwuid(buff->st_uid)->pw_name) >
		maxclen->username)
		maxclen->username = ft_strlen(
				getpwuid(buff->st_uid)->pw_name);
	if ((int)ft_strlen(getgrgid(buff->st_gid)->gr_name) >
		maxclen->group)
		maxclen->group = ft_strlen(getgrgid(buff->st_gid)->gr_name);
	if (buff->st_size > maxclen->f_size)
		maxclen->f_size = buff->st_size;
	maj_min_len(buff, maxclen);
	maxclen->total += buff->st_blocks;
}

void	parse_source(DIR *dir, char *source, struct col_len *maxclen)
{
	struct stat		*buff;
	struct dirent	*entry;
	char			*file;

	buff = (struct stat*)malloc(sizeof(struct stat));
	while ((entry = readdir(dir)) != NULL)
	{
		if(g_flags.a == 0 && *(entry->d_name) == '.')
			continue;
		file = ft_strjoin(source, entry->d_name);
		stat(file, buff);
		free(file);
		check_maxlen(buff, maxclen);
	}
	maxclen->links = ft_numlen(maxclen->links);
	maxclen->f_size = ft_numlen(maxclen->f_size);
	if (maxclen->f_size < maxclen->maj_len + maxclen->min_len)
		maxclen->f_size = maxclen->maj_len + maxclen->min_len + 2;
	free(buff);
}

void	flush_maxclen(col_len *maxclen)
{
	maxclen->links = 0;
	maxclen->username = 0;
	maxclen->f_size = 0;
	maxclen->group = 0;
	maxclen->maj_len = 0;
	maxclen->min_len = 0;
	maxclen->total = 0;
}

int		show_long_list(char *av)
{
	char			*source;
	DIR				*dir;
	struct col_len	*maxclen;

	maxclen = (struct col_len*)malloc(sizeof(struct col_len));
	flush_maxclen(maxclen);
	source = get_source(av);
	dir = opendir(source);
	if (!dir)
	{
		write(1, "ft_ls: ", 7);
		perror(av);
		return (0);
	}
	parse_source(dir, source, maxclen);
	closedir(dir);
	dir = opendir(source);
	show_long(dir, source, maxclen);
	closedir(dir);
	free(maxclen);
	free(source);
	return (1);
}
