#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


#include "libft/libft.h"
#include "include/ft_ls.h"


void	ft_recur(char *file, struct dirent *entry)
{
	if (ft_strcmp(entry->d_name, ".") && \
			ft_strcmp(entry->d_name, ".."))
	{
		if (entry->d_type == 4)
			ft_ls(file);
	}
}

int	ft_ls(char *av)
{
	DIR				*dir;
	int 			total;
	int 			i;
	char 			*total_str;
	char 			*source;
	char 			*file;
	struct dirent 	*entry;
	struct stat		*buff;
	struct col_len	*maxlen;
	i = 0;
	total = 0;
	source = NULL;
	buff = (struct stat*)malloc(sizeof(struct stat));
	maxlen = (struct col_len*)malloc(sizeof(struct col_len));


	total = 0;
	source = get_source(av);
	dir = opendir(source);
	if (!dir)
	{
		write(1, "ft_ls: ", 7);
		perror(av);
		return (0);
	}
	if (g_flags.l == 0)
	{
		while ((entry = readdir(dir)) != NULL)
		{
			if (g_flags.a == 0 && *(entry->d_name) == '.')
				continue;
			file = ft_strjoin(source, entry->d_name);
			if(g_flags.R == 1)
				ft_recur(file, entry);
			ft_putstr(entry->d_name);
			write(1, "\t", 1);
		}
		write(1, "\n", 1);
	}
	else
	{
		maxlen->links = 0;
		maxlen->username = 0;
		maxlen->f_size = 0;
		maxlen->group = 0;
		maxlen->maj_len = 0;
		maxlen->min_len = 0;
		while ((entry = readdir(dir)) != NULL)
		{
			if(g_flags.a == 0 && *(entry->d_name) == '.')
				continue;
			file = ft_strjoin(source, entry->d_name);
			stat(file, buff);
			if(g_flags.R == 1)
				ft_recur(file, entry);
			free(file);
			if (buff->st_nlink > maxlen->links)
				maxlen->links = buff->st_nlink;
			if ((int) ft_strlen(getpwuid(buff->st_uid)->pw_name) >
				maxlen->username)
				maxlen->username = ft_strlen(
						getpwuid(buff->st_uid)->pw_name);
			if ((int) ft_strlen(getgrgid(buff->st_gid)->gr_name) >
				maxlen->group)
				maxlen->group = ft_strlen(getgrgid(buff->st_gid)->gr_name);
			if (buff->st_size > maxlen->f_size)
				maxlen->f_size = buff->st_size;
			maj_min_len(buff, maxlen);
			total += buff->st_blocks;
		}
		total_str = ft_itoa(total);
		write(1, av, ft_strlen(av));
		write(1, ":\n", 2);
		write(1, "total ", 6);
		write(1, total_str, ft_strlen(total_str));
		write(1, "\n", 1);
		free(total_str);

		maxlen->links = ft_numlen(maxlen->links);
		maxlen->f_size = ft_numlen(maxlen->f_size);
		if (maxlen->f_size < maxlen->maj_len + maxlen->min_len)
			maxlen->f_size = maxlen->maj_len + maxlen->min_len + 2;
		closedir(dir);

		dir = opendir(source);
		while ((entry = readdir(dir)) != NULL)
		{
			if(g_flags.a == 0 && *(entry->d_name) == '.')
				continue;
			file = ft_strjoin(source, entry->d_name);
			stat(file, buff);
			free(file);

			first_colon(buff, maxlen);
			second_colon(buff, maxlen, entry->d_name);
		}
		closedir(dir);
		free(source);
		free(buff);
		free(maxlen);
	}
	return (1);
}

int 	main(int ac, char **av)
{
	int 			i;

	i = 0;
	if (ac == 1)
		ft_ls(get_root(av[i]));
	if (ac == 2 && check_flags(av[1]))
	{
		ft_ls(get_root(av[i]));
	}
	else
	{
		i++;
		while (i < ac)
		{
			if(check_flags(av[i]))
			{
				i++;
				if(i == ac)
					ft_ls(get_root(av[0]));
				continue;
			}
			if (i < ac - 1)
			{
				ft_putstr(av[i]);
				write(1, ":\n", 2);
			}
			ft_ls(av[i]);
			i++;
			if(i != ac)
				write(1, "\n", 1);
		}
	}
	return (0);
}