#include "ft_printf.h"

int is_a_flag(const char *s, int i, t_format *var)
{
	if ((s[i] == '0' || s[i] == '-') && (i == (var->i_start + 1)))
		return (1);
	return (0);
}

int 	is_a_type(const char c)
{
	if (c == 'd' || c == 's' || c == 'c' || c == 'p' ||
		c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void struct_init(t_format *var)
{
	var->flag = 0;
	var->width = 0;
	var->prec = -1;
	var->type = 0;
    var->star_prec = 0;
    var->star_width = 0;
	var->i_start = 0;
}

int struct_null(t_format *var)
{
	if (var->type == 0)
		return (1);
	return (0);
}

void smista(t_format *var)
{
	if (var->type == 'd')
		stampa_int(&*var);
	else if (var->type == 's')
		stampa_str(&(*var));
    else if (var->type == 'c')
        stampa_chr(&(*var));
    else if (var->type == 'p')
        stampa_point(&(*var));
    else if (var->type == 'i')
        stampa_int(&(*var));
    else if (var->type == 'u')
        stampa_unint(&(*var));
    else if (var->type == 'x')
        stampa_esa(&(*var));
    else if (var->type == 'X')
        stampa_esamausic(&(*var));
}

static int		is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int define(const char *s, int i, t_format *var)
{
	char appoggio[100000];
	int j;

	var->i_start = i;
	i++;
		while (is_space(s[i]))
			i++;
		if (is_a_flag(s, i, &(*var)))
		{
			var->flag = s[i];
			i++;
		}
		if ((!is_a_flag(s, i, &*var) && s[i] >= '0' && s[i] <= '9') ||
			(!is_a_flag(s, i, &*var) && s[i] == '*'))
		{
			j = 0;
            if (s[i] == '*')
            {
                var->star_width = 1;
                i++;
            }
            else
            {
			    while(s[i] >= '0' && s[i] <= '9')
			    {
				    appoggio[j] = s[i];
				    j++;
				    i++;
			    }
            }
			appoggio[j] = 0;
			if (appoggio[0] == 0)
				var->width = 0;
			else
				var->width = ft_atoi(appoggio);
		}
		if (s[i] == '.')
		{
			i++;
			j = 0;
            if (s[i] == '*')
            {
                var->star_prec = 1;
                i++;
            }
            else
            {
			    while(s[i] >= '0' && s[i] <= '9')
			    {
				    appoggio[j] = s[i];
				    j++;
				    i++;
			    }
            }
			appoggio[j] = 0;
			if (appoggio[0] == 0)
				var->prec = 0;
			else
				var->prec = ft_atoi(appoggio);
		}
		if (!is_a_flag(s, i, &*var) && is_a_type(s[i]))
        {
			var->type = s[i];
            i++;
        }
	if (struct_null(&*var))
		return (var->i_start);
	//printf("\nFLAG: %c | WIDTH: %d | PREC: %d | TYPE: %c \n", var->flag, var->width, var->prec, var->type );
	smista(&*var);
    //printf("%ld\n", var->counter);
	return (i);
}

int scroller(const char *s, t_format *var)
{
	int 		i;

	i = 0;
	struct_init(&*var);
	while(s[i])
	{
		if (s[i] == '%' && s[i + 1] != '%')
        {
			i = define(s, i, &*var);
            struct_init(&*var);
        }
		else if (s[i] == '%' && s[i + 1] == '%')
			i++;
        if (s[i] != '%' && s[i])
        {
		    write(1, &s[i], 1);
            var->counter += 1;
		    i++;
        }
	}
	return (1);
}

int ft_printf(const char *s, ...)
{
    t_format 	var;

    var.counter = 0;
    va_start(var.arg_lst, s);
    scroller(s, &var);
    va_end(var.arg_lst);
    return (var.counter);
}
