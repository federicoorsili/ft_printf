#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_format{
	char	flag;
	int		width;
    int     star_width;
	int		prec;
    int     star_prec;
	char	type;
	int		i_start;
	int	    counter;
    va_list arg_lst;
}				t_format;

# ifndef MIN_INT
#  define MIN_INT -2147483648
# endif
# define EXA_MAX "0123456789ABCDEF"
# define EXA_MIN "0123456789abcdef"
# define DECA "0123456789"

int 		ft_printf(const char *s, ...);
int		    ft_atoi(const char *str);
void        stampa_int(t_format *var);
void        stampa_str(t_format *var);
void        stampa_chr(t_format *var);
void        stampa_esa(t_format *var);
void        stampa_esamausic(t_format *var);
void        stampa_point(t_format *var);
int	        ft_atoi(const char *str);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
int			ft_isdigit(int c);
void		ft_putnbr_base(int nbr, char *base, char **str);
void		ft_bzero(void *s, unsigned long long n);
void 		stampa_unint(t_format *var);
char        *ft_uns_itoa(unsigned int n);

#endif