
#ifndef FT_LS_FT_LS_H
#define FT_LS_FT_LS_H
struct		col_len
{
	nlink_t			links;
	int 			username;
	unsigned long long  	f_size;
	int 			group;
	int 			maj_len;
	int 			min_len;
};


char 			*mode2str(int mode);
char 			*time2str(const time_t *time);
void			first_colon(struct stat *buff, struct col_len *maxlen);
void			second_colon(struct stat *buff, struct col_len *maxlen, char *source);
unsigned long long	ft_numlen(unsigned  long long n);
unsigned long long	ft_itoa_ll(unsigned long long n);
int 				major(unsigned long major);
int 				minor(unsigned long minor);
void 	maj_min_len(struct stat *buff, struct col_len *maxlen);

#endif //FT_LS_FT_LS_H
