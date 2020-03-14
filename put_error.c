#include "libft/libft.h"

void	put_error(char flag)
{
	write(1, "ft_ls: illegal option -- ", 25);
	write(1, &flag, 1);
	write(1, "\n", 1);
	write(1, "usage: ft_ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 65);
	exit(1);
}