#include "libft/libft.h"
#include "include/ft_ls.h"

int 	check_flags(char *str)
{
	if (!str)
		return (0);
	if (ft_strlen(str) > 1 && *str == '-')
	{
		while (*str++)
		{
			if (*str != 'l' && *str != 'a' && *str != 'R' && *str != '\0')
				put_error(*str);
			if (*str == 'l')
				g_flags.l = 1;
			if (*str == 'a')
				g_flags.a = 1;
			if (*str == 'R')
				g_flags.R = 1;
//			str++;
		}
		return (1);
	}
	return (0);
}

int 	parse_input(int ac, char **av)
{
	int 	i;

	i = ac;
	if(!check_flags(av[1]))
		return(0);
	return(1);
}