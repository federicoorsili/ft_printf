#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void put_n_chr(const char c, int n, t_format *var)
{
    int i;

    i = 0;
    while (i < n)
    {
        write(1, &c, 1);
        var->counter += 1;
        i++;
    }
}

static void put_str(const char *s, int len, t_format *var)
{
    int i;

    i = 0;
    while (i < len && s[i])
    {
        write(1, &s[i], 1);
        var->counter += 1;
        i++;
    }
}

void width_print(t_format *var, int valore)
{
    if (var->width > var->prec && var->prec > valore && var->type != 's' && var->type != 'c')
        put_n_chr(' ', (var->width - (var->prec - valore)) - valore, &(*var));
    else
        put_n_chr(' ', var->width - valore, &(*var));
}

t_format *check_star(t_format *var)
{
    if (var->star_width)
        var->width = va_arg(var->arg_lst, int);
    if (var->star_prec)
        var->prec = va_arg(var->arg_lst, int);
    return(var);
}

void check_all_digit(t_format *var, int valore)
{
    if (var->flag == 0 && var->width > valore)
        width_print(&(*var), valore);
    if (var->flag == '0' && var->width > valore && (var->prec >= 0 && var->prec >= valore))
        put_n_chr(' ', var->width - var->prec, &(*var));
    if (var->flag == '0' && var->width > valore && (var->prec >= 0 && var->prec < valore))
        put_n_chr(' ', var->width - valore, &(*var));
    if (var->prec >= 0)
        if (var->prec > 0 && var->prec > valore)
            put_n_chr('0', var->prec - valore, &(*var));
    if (var->flag == '0' && var->width > valore && (var->prec < 0))
        put_n_chr('0', var->width - valore, &(*var));        
}

void stampa_int(t_format *var)
{
    int valore;
    char *str_valore;

    var = check_star(&(*var));
    valore = va_arg(var->arg_lst, int);
    str_valore = ft_itoa(valore);
    valore = ft_strlen(str_valore);
    check_all_digit(&(*var), valore);
    put_str(str_valore, valore, &(*var));
    if (var->flag == '-' && var->width > valore)
        width_print(&(*var), valore);
}

void stampa_str(t_format *var)
{
    char *str;
    int  len;

    var = check_star(&(*var));
    str = va_arg(var->arg_lst, char *);
    len = ft_strlen(str);
    if (var->prec >= 0 && var->prec <= len)
        len = var->prec;
    if ((var->flag == 0 || var->flag == '0') && var->width > len)
        put_n_chr(' ', (var->width - len), &(*var));
    put_str(str, len, &(*var));
    if (var->flag == '-' && var->width > len)
        width_print(&(*var), len);
}

void stampa_chr(t_format *var)
{
    int chr;
    int  len;

    var = check_star(&(*var));
    chr = va_arg(var->arg_lst, int);
    len = 1;
    if ((var->flag == 0 || var->flag == '0') && var->width > len)
        put_n_chr(' ', (var->width - len), &(*var)); 
    put_n_chr(chr, len, &(*var));
    if (var->flag == '-' && var->width > len)
        width_print(&(*var), len);
}

char *inverter(char **str)
{
    char *appoggio;
    int i;
    int j;

    if (!(appoggio = malloc(30)))
        return (0);
    i = ft_strlen(*str) - 1;
    j = 0;
    while(i >= 0)
    {
        appoggio[j] = (*str)[i];
        i--;
        j++;
    }
    appoggio[j] = 0;
    free(*str);
    return (appoggio);
}

char *base_mausic(int caps)
{
    char *output;
    if (!caps)
    {
        output = ft_strdup("0123456789abcdef\0");
        return (output);
    }
    output = ft_strdup("0123456789ABCDEF\0");
    return (output);
}

char *esadec_converter(unsigned int numero, int caps)
{
    char  *base;
    char   *str;
    unsigned int n;
    int i;

    i = 0;
    n = 0;
    if (!(str = malloc(30)))
        return (0);
    ft_bzero(str, 30);
    base = base_mausic(caps);
    if (!n)
        n = numero;
    while (n != 0)
    {
        str[i] = base[n % 16];
        n = n / 16;
        i++;
    }
    str[i] = 0;
    free(base);
    return(inverter(&str));
}

void stampa_esa(t_format *var)
{
    int valore;
    char *str_valore;

    var = check_star(&(*var));
    valore = va_arg(var->arg_lst, int);
    str_valore = esadec_converter((unsigned int)valore, 0);
    valore = ft_strlen(str_valore);
    check_all_digit(&(*var), valore);
    put_str(str_valore, valore, &(*var));
    free(str_valore);
    if (var->flag == '-' && var->width > valore)
        width_print(&(*var), valore);
}

void stampa_esamausic(t_format *var)
{
    int valore;
    char *str_valore;

    var = check_star(&(*var));
    valore = va_arg(var->arg_lst, int);
    str_valore = esadec_converter((unsigned int)valore, 1);
    valore = ft_strlen(str_valore);
    check_all_digit(&(*var), valore);
    put_str(str_valore, valore, &(*var));
    free(str_valore);
    if (var->flag == '-' && var->width > valore)
        width_print(&(*var), valore);
}

char *pointer_converter(unsigned long int numero, int caps)
{
    char  *base;
    char   *str;
    unsigned long int n;
    int i;

    i = 0;
    n = 0;
    if (!(str = malloc(30)))
        return (0);
    ft_bzero(str, 30);
    base = base_mausic(caps);
    if (!n)
        n = numero;
    while (n != 0)
    {
        str[i] = base[n % 16];
        n = n / 16;
        i++;
    }
    str[i] = 0;
    free(base);
    return(inverter(&str));
}

void stampa_point(t_format *var)
{
    unsigned long int          val;
    int             valore;
    void            *p;
    char            *str_valore;

    var = check_star(&(*var));
    p = va_arg(var->arg_lst, void *);
    val = (unsigned long int)p;
    str_valore = pointer_converter(val, 0);
    valore = ft_strlen(str_valore) + 2;
    check_all_digit(&(*var), valore);
    put_str("0x", 2, &(*var));
    put_str(str_valore, valore, &(*var));
    free(str_valore);
    if (var->flag == '-' && var->width > valore)
        width_print(&(*var), valore);
}



void stampa_unint(t_format *var)
{
    unsigned int val;
    char *str_valore;
    int  valore;

    var = check_star(&(*var));
    val = va_arg(var->arg_lst,unsigned int);
    str_valore = ft_uns_itoa(val);
    valore = ft_strlen(str_valore);
    check_all_digit(&(*var), valore);
    put_str(str_valore, valore, &(*var));
    if (var->flag == '-' && var->width > valore)
        width_print(&(*var), valore);
}