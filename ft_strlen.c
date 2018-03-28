/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:51:13 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/07 16:58:01 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_wstrlen(wchar_t *s)
{
	size_t i;

	i = 0;
	while (*s)
	{
		if (*s <= 255)
			i++;
		else if (*s <= 2048)
			i += 2;
		else if (*s <= 65535)
			i += 3;
		else
			i += 4;
		s++;
	}
	return (i);
}
