/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:58:25 by forsili           #+#    #+#             */
/*   Updated: 2021/01/13 13:58:27 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' ||
		c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

static int		ft_atoi_appoggio(const char *str, int is_minus,
							long long int result)
{
	int					index;

	index = 0;
	while (is_space(str[index]))
		index++;
	if (str[index] == '-')
	{
		is_minus *= -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
	{
		result = result * 10 + (str[index++] - '0');
		if (result > 2147483648)
			break ;
	}
	if ((result == 2147483648 && is_minus == -1) || result <= 2147483648)
		return (is_minus * (int)result);
	return (is_minus == 1 ? -1 : 0);
}

int		ft_atoi(const char *str)
{
	int					is_minus;
	long long int		result;

	result = 0;
	is_minus = 1;
	return (ft_atoi_appoggio(str, is_minus, result));
}
