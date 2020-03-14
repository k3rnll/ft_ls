#include <sys/stat.h>
#include <grp.h>

#include "libft/libft.h"
#include "include/ft_ls.h"

void	second_colon(struct stat *buff, struct col_len *maxlen, char *source)
{
	char 			*group;
	char			*size;
	char 			*time;
	unsigned long 	len;
	char 			*maj;
	char 			*min;

	group = getgrgid(buff->st_gid)->gr_name;
	size = (char*)ft_itoa_ll(buff->st_size);
	time = time2str(&buff->st_ctimespec.tv_sec);

	len = maxlen->group - ft_strlen(group);
	ft_putstr(group);
	while (len--)
		write(1, " ", 1);
	write(1, "  ", 2);




	if (S_ISCHR(buff->st_mode) || S_ISBLK(buff->st_mode))
	{
		maj = ft_itoa(major(buff->st_rdev));
		min = ft_itoa(minor(buff->st_rdev));
		len = maxlen->f_size - maxlen->min_len - 2 - ft_strlen(maj);
		while (len--)
			write(1, " ", 1);
		ft_putstr(maj);
		write(1, ", ", 2);
		len = maxlen->min_len - ft_strlen(min);
		while (len--)
			write(1, " ", 1);
		ft_putstr(min);
	}
	else
	{
		len = maxlen->f_size - ft_strlen(size);
		while (len--)
			write(1, " ", 1);
		ft_putstr(size);
	}
	write(1, " ", 1);


	ft_putstr(time + 4);
	write(1, " ", 1);
	ft_putstr(source);
	write(1, "\n", 1);

	free(size);
}