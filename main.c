#include "ft_printf.h"

int main()
{
	//char *s = "%c\n";
    char *p;
    int ret;
    p = malloc(1000);
    //"ioe%-102.33foiiowop iwejioje%010.100ddlako"

    //ret = ft_printf("%3.s", NULL);
    ft_printf("\n%d\n", ret);
    ret = printf("%3.s", NULL);
    printf("\n%d\n", ret);
    free(p);

}