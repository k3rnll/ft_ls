
#ifndef FT_LS_FT_LS_H
#define FT_LS_FT_LS_H

#include <sys/stat.h>
typedef struct		col_len
{
	int				links;
	int 			username;
	long long  		f_size;
	int 			group;
	int 			maj_len;
	int 			min_len;
	int 			total;
}			col_len;

int			ft_ls(char *av);
char 		*get_source(char *str);
char 		*get_root(char *str);
int 		check_flags(char *str);
int		parse_input(int ac, char **av);
char 		*mode2str(int mode);
char 		*time2str(const time_t *time);
void		show_list(char *file);
void		put_error(char flag);
int 		show_long_list(char *av);
int			show_short_list(char *av);

long long	ft_numlen(long long n);
long long	ft_itoa_ll(long long n);
int 		major(long long major);
int 		minor(long long minor);
void 		maj_min_len(struct stat *buff, col_len *maxlen);
void		first_colon(struct stat *buff, col_len *maxlen);
void		second_colon(struct stat *buff, col_len *maxlen, char *source);

typedef struct		flags
{
	int 	l;
	int 	R;
	int 	a;
	int 	r;
	int 	t;
}			flags;


flags	g_flags;
#endif //FT_LS_FT_LS_H
