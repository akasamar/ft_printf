/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:37:04 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:37:10 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	stringrigor(t_p *new, char *s)
{
	int i;
	int dif;

	i = -1;
	dif = 0;
	if (ft_strlen(s) > new->rigor)
		dif = ft_strlen(s) - new->rigor;
	new->width = new->width - ft_strlen(s) + dif;
	if (new->width > 0 && new->flag_minus == 0)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
	if (new->rigor > 0)
		while (*s && new->rigor--)
		{
			ft_putchar(*s, new);
			s++;
		}
	else
		ft_putstr(s, new);
	if (new->width > 0 && new->flag_minus == 1)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
}

void		showstring(t_p *new, va_list *va)
{
	char *s;

	s = va_arg(*va, char *);
	s == NULL ? s = "(null)" : 0;
	if (new->rigor > 0)
	{
		stringrigor(new, s);
		return ;
	}
	new->checkzero == 1 ? new->width += ft_strlen(s) : 0;
	new->width = new->width - ft_strlen(s);
	if (new->width > 0 && new->flag_minus == 0)
		while ((new->width)-- && new->width > -1)
			new->flag_zero ? ft_putchar('0', new) : ft_putchar(' ', new);
	new->checkzero != 1 ? ft_putstr(s, new) : 0;
	if (new->width > 0 && new->flag_minus == 1)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
}
