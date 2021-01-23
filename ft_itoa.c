/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:24:43 by forsili           #+#    #+#             */
/*   Updated: 2021/01/14 15:24:45 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	getlen(int n)
{
	int i;

	i = 1;
	if (n < 0)
		n *= -1;
	while (i < 10)
	{
		if (ft_isdigit(n + 48))
			break ;
		n = n / 10;
		i++;
	}
	return (i);
}

static void	convert(char *a, int n, int len)
{
	if (n >= 0)
	{
		while (len-- > 0)
		{
			a[len] = (n % 10) + 48;
			n /= 10;
		}
	}
	else
	{
		n *= -1;
		a[0] = '-';
		while (len-- > 1)
		{
			a[len] = (n % 10) + 48;
			n /= 10;
		}
	}
}

char		*ft_itoa(int n)
{
	char	*a;
	int		len;

	len = getlen(n);
	if (n < 0)
		len++;
	if (n == MIN_INT)
		return (ft_strdup("-2147483648"));
	if (!(a = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	a[len] = '\0';
	convert(a, n, len);
	return (a);
}
