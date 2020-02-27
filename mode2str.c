#include "libft/libft.h"

char 	*mode2str(int mode)
{
	char	*str;

	str = ft_strnew(16);
	mode & 16384 ? (str[0] = 'd') : (str[0] = '-');
	mode & 256 ? (str[1] = 'r') : (str[1] = '-');
	mode & 128 ? (str[2] = 'w') : (str[2] = '-');
	mode & 64 ? (str[3] = 'x') : (str[3] = '-');
	mode & 32 ? (str[4] = 'r') : (str[4] = '-');
	mode & 16 ? (str[5] = 'w') : (str[5] = '-');
	mode & 8 ? (str[6] = 'x') : (str[6] = '-');
	mode & 4 ? (str[7] = 'r') : (str[7] = '-');
	mode & 2 ? (str[8] = 'w') : (str[8] = '-');
	mode & 1 ? (str[9] = 'x') : (str[9] = '-');
//	mode & 512 ? (str[9] = 't') : 0;
	return (str);
}