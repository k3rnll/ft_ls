#include <sys/stat.h>
#include <pwd.h>

#include "libft/libft.h"
#include "include/ft_ls.h"

void	first_colon(struct stat *buff, col_len *maxlen)
{
	char 	*attr;
	char	*links;
	char 	*username;
	int 	len;

	attr = mode2str(buff->st_mode);
	links = ft_itoa(buff->st_nlink);
	username = getpwuid(buff->st_uid)->pw_name;


	ft_putstr(attr);
	write(1, " ", 1);

	len = maxlen->links - ft_strlen(links);
	while(len--)
		write(1, " ", 1);
	ft_putstr(links);
	write(1, " ", 1);

	len = maxlen->username - ft_strlen(username);
	ft_putstr(username);
	while (len--)
		write(1, " ", 1);
	write(1, "  ", 2);

	free(attr);
	free(links);
}