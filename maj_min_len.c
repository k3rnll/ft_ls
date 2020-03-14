#include <sys/stat.h>
#include "include/ft_ls.h"

void 	maj_min_len(struct stat *buff, struct col_len *maxlen)
{

	if (S_ISCHR(buff->st_mode) || S_ISBLK(buff->st_mode))
	{
		if (ft_numlen(major(buff->st_rdev)) > maxlen->maj_len)
			maxlen->maj_len = ft_numlen(major(buff->st_rdev));
		if (ft_numlen(minor(buff->st_rdev)) > maxlen->min_len)
			maxlen->min_len = ft_numlen(minor(buff->st_rdev));
	//	if (maxlen->f_size < maxlen->maj_len + maxlen->min_len)
	//		maxlen->f_size = maxlen->maj_len + maxlen->min_len + 2;
	}
}