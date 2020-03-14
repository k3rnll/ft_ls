#include "libft/libft.h"

char 	*get_root(char *str)
{
	char 	*source;
	int 	i;

	i = ft_strlen(str);
	source = ft_strnew(i);
	source = ft_strcpy(source, str);

	while (source[--i] != '/')
		source[i] = '\0';
	return (source);
}

char 	*get_source(char *str)
{
	char 	*source;
	int 	i;

	i = ft_strlen(str);
	source = ft_strnew(i+1);
	source = ft_strcpy(source, str);

	if (source[i-1] == '/')
		return (source);
	source[i] = '/';
	return (source);
}