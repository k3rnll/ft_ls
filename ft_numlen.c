#include "libft/libft.h"

long long	ft_numlen(unsigned long long n)
{
	int		len;

	len = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char		*ft_itoa_ll(long long n)
{
	long long	len;
	char		*str;

	len = ft_numlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (n / 10 != 0)
	{
		str[len - 1] = (signed char)((n % 10) + 48);
		n = n / 10;
		len--;
	}
	str[len - 1] = (signed char)((n % 10) + 48);
	return (str);
}