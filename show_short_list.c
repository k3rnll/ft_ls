#include <dirent.h>
#include <stdio.h>

#include "libft/libft.h"
#include "include/ft_ls.h"

void	rec_short_list(char *source, struct dirent *entry)
{
	if (ft_strcmp(entry->d_name, ".") && \
			ft_strcmp(entry->d_name, ".."))
	{
		if (entry->d_type == 4)
		{
			write(1, "\n", 1);
			ft_putstr(source);
			write(1, ":\n", 2);
			show_short_list(source);
		}
	}
}

void	show_short(DIR *dir)
{
//	char 			*file;
	struct dirent	*entry;

	while ((entry = readdir(dir)) != NULL)
	{
		if(g_flags.a == 0 && *(entry->d_name) == '.')
			continue;
		ft_putstr(entry->d_name);
		write(1, "\t", 1);
	}
	write(1, "\n", 1);
}

void	parse_short(DIR *dir, char *source)
{
	struct dirent	*entry;
	char			*file;

	while ((entry = readdir(dir)) != NULL)
	{
		if(g_flags.a == 0 && *(entry->d_name) == '.')
			continue;
		file = ft_strjoin(source, entry->d_name);
		if(g_flags.R == 1)
			rec_short_list(file, entry);
		free(file);
	}
}

int		show_short_list(char *av)
{
	char			*source;
	DIR				*dir;

	source = get_source(av);
	dir = opendir(source);
	if (!dir)
	{
		write(1, "ft_ls: ", 7);
		perror(av);
		return (0);
	}
	show_short(dir);
	closedir(dir);
	dir = opendir(source);
	parse_short(dir, source);
	closedir(dir);
	free(source);
	return (1);
}
