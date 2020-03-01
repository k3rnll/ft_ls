#include <sys/stat.h>
#include <pwd.h>

#include "libft/libft.h"
#include "ft_ls.h"

// 11 chars for attr
// any chars for links 16-32
// any chars for username 20 - 32 char

void	first_colon(struct stat *buff, struct col_len *maxlen)
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