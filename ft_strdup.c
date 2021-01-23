/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:52:59 by forsili           #+#    #+#             */
/*   Updated: 2021/01/13 14:53:02 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	char					*out;
	size_t					i;

	i = 0;
	if (!(out = malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	while (i < ft_strlen(s1))
	{
		out[i] = s1[i];
		i++;
	}
	out[i] = 0;
	return (out);
}
