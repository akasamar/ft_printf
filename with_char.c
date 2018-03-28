/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:33:15 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:33:17 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		showchar(t_p *new, va_list *va)
{
	char c;

	c = va_arg(*va, int);
	if (new->width > 1 && new->flag_minus != 1)
	{
		new->width -= 1;
		while ((new->width)-- && new->width >= 0)
			new->flag_zero ? ft_putchar('0', new) : ft_putchar(' ', new);
	}
	ft_putchar(c, new);
	if (new->width > 1 && new->flag_minus == 1)
	{
		new->width -= 1;
		while ((new->width)-- && new->width >= 0)
			ft_putchar(' ', new);
	}
}
