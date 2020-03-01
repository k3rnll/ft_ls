#include "libft/libft.h"
#include <time.h>

char 	*time2str(const time_t *time)
{
	char	*str;

	str = ctime(time);
	str[16] = '\0';
	return (str);
}