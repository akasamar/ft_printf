/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_swchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:38:00 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:38:01 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	stringrigor(t_p *new, wchar_t *s)
{
	int i;
	int dif;

	i = -1;
	dif = 0;
	if (ft_wstrlen(s) > new->rigor)
		dif = ft_wstrlen(s) - new->rigor;
	new->width = new->width - ft_wstrlen(s) + dif;
	if (new->width > 0 && new->flag_minus == 0)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
	if (new->rigor > 0)
		while (*s && new->rigor--)
		{
			ft_wputchar(*s, new);
			s++;
		}
	else
		ft_wputstr(s, new);
	if (new->width > 0 && new->flag_minus == 1)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
}

void		read_swchar(t_p *new, wchar_t *s)
{
	s == NULL ? s = L"(null)" : 0;
	if (new->rigor > 0)
	{
		stringrigor(new, s);
		return ;
	}
	new->checkzero == 1 ? new->width += ft_wstrlen(s) : 0;
	new->width = new->width - ft_wstrlen(s);
	if (new->width > 0 && new->flag_minus == 0)
		while ((new->width)-- && new->width > -1)
			new->flag_zero ? ft_putchar('0', new) : ft_putchar(' ', new);
	new->checkzero != 1 ? ft_wputstr(s, new) : 0;
	if (new->width > 0 && new->flag_minus == 1)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
}
