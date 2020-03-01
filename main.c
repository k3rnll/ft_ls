#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


#include "libft/libft.h"
#include "ft_ls.h"

int 	main(int ac, char **av)
{
	DIR				*dir;
	char 			*source;
	char 			*file;
	struct dirent 	*entry;
	struct stat		buff;
	struct col_len	maxlen;

	source = "/dev/";
	dir = opendir(source);
	if (!dir)
	{
		perror("diropen");
		exit(1);
	}
	maxlen.links = 0;
	maxlen.username = 0;
	maxlen.f_size = 0;
	maxlen.group = 0;
	maxlen.maj_len = 0;
	maxlen.min_len = 0;
	while ((entry = readdir(dir)) != NULL)
	{
//		file = ft_strjoin(source, "stdout");
		file = ft_strjoin(source, entry->d_name);
		stat(file, &buff);
		free(file);
		if (buff.st_nlink > maxlen.links)
			maxlen.links = buff.st_nlink;
		if (ft_strlen(getpwuid(buff.st_uid)->pw_name) > maxlen.username)
			maxlen.username = ft_strlen(getpwuid(buff.st_uid)->pw_name);
		if (ft_strlen(getgrgid(buff.st_gid)->gr_name) > maxlen.group)
			maxlen.group = ft_strlen(getgrgid(buff.st_gid)->gr_name);
		if (buff.st_size > maxlen.f_size)
			maxlen.f_size = buff.st_size;
		maj_min_len(&buff, &maxlen);
	}
	maxlen.links = ft_numlen(maxlen.links);
	maxlen.f_size = ft_numlen(maxlen.f_size);
	if(maxlen.f_size < maxlen.maj_len + maxlen.min_len)
		maxlen.f_size = maxlen.maj_len + maxlen.min_len + 2;
	closedir(dir);

	dir = opendir(source);
	while ((entry = readdir(dir)) != NULL)
	{
//		file = ft_strjoin(source, "stdout");
		file = ft_strjoin(source, entry->d_name);
		stat(file, &buff);
		free(file);

		first_colon(&buff, &maxlen);
		second_colon(&buff, &maxlen, entry->d_name);
	}
	closedir(dir);
}