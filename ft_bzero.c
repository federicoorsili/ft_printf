/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:36:50 by forsili           #+#    #+#             */
/*   Updated: 2021/01/11 17:36:54 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, unsigned long long n)
{
	unsigned long long int i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)0;
		i++;
	}
}
