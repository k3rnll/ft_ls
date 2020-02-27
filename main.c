#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include "libft/libft.h"
#include <time.h>
#include <pwd.h>
#include <grp.h>

#include "ft_ls.h"

int 	main(int ac, char **av)
/* open file, stat to struct
{
	int fd;
	struct stat buff;
	if (!(fd = open("test", O_RDONLY)))
	{
		printf("cannot open\n");
		exit(1);
	}
	stat("test", &buff);
	close (fd);
}
*/
{
	int 	fd;
	DIR		*dir;
	char 	*str;
	char 	*str2;
	struct dirent *entry;
	struct stat		buff;

	str = "/Users/tmarkita/";
	dir = opendir(str);
	if (!dir)
	{
		perror("diropen");
		exit(1);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		fd = open(entry->d_name, O_RDONLY);
		str2 = ft_strjoin(str, entry->d_name);
		stat(str2, &buff);
		close(fd);
		printf("%s ", mode2str(buff.st_mode));
		printf("%4d\t", buff.st_nlink);
		printf("%s  ", (getpwuid(buff.st_uid)->pw_name));
		printf("%s", (getgrgid(buff.st_gid)->gr_name));
		printf("%15lld\t\t", buff.st_size);
		printf("%ld ", buff.st_ctimespec.tv_sec);
		printf("%s\n", entry->d_name);

//		write(1, "a\n", 2);
	}
	closedir(dir);
}