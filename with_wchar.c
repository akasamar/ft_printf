/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_wcha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:41:56 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/28 13:41:58 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	read_wchar(t_p *new, wchar_t k)
{
	int i;

	i = 0;
	if (k <= 255)
		i++;
	else if (k <= 2048)
		i += 2;
	else if (k <= 65535)
		i += 3;
	else
		i += 4;
	new->width -= i;
	if (new->width > 1 && new->flag_minus != 1)
	{
		while ((new->width)-- && new->width >= 0)
			new->flag_zero ? ft_putchar('0', new) : ft_putchar(' ', new);
	}
	ft_wputchar(k, new);
	if (new->width > 1 && new->flag_minus == 1)
	{
		while ((new->width)-- && new->width >= 0)
			ft_putchar(' ', new);
	}
}
