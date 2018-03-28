/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:57:53 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/21 19:05:09 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *s, t_p *new)
{
	if (s)
	{
		while (*s)
		{
			write(1, s++, 1);
			new->printflength++;
		}
	}
}

void	ft_wputstr(wchar_t *s, t_p *new)
{
	while (*s)
	{
		ft_wputchar(*s, new);
		s++;
	}
}
