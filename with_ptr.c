/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:35:54 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:35:55 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ptr_rigor(long long num, int count, t_p *new)
{
	int def;

	def = new->rigor > count ? 2 + (new->rigor - count) + count : count + 2;
	if (new->rigor >= new->width)
	{
		new->width = 0;
		ft_putstr("0x", new);
		new->rigor -= count;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
		ft_hex(num, 16, 0, new);
	}
	else if (new->width > new->rigor)
	{
		new->width -= def;
		new->rigor -= count;
		while (new->width >= 0 && new->flag_minus == 0 && new->width--)
			ft_putchar(' ', new);
		ft_putstr("0x", new);
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
		ft_hex(num, 16, 0, new);
		while (new->width-- && new->width >= 0 && new->flag_minus == 1)
			ft_putchar(' ', new);
	}
}

static	void	showptr2(t_p *new, int count)
{
	if (new->width > 0 && new->flag_minus == 1)
	{
		new->width = new->width - count - 2;
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
	}
}

void			showptr(t_p *new, va_list *va)
{
	long long	num;
	int			count;

	num = va_arg(*va, long long);
	count = countofhex(num, 16);
	if (new->rigor > 0)
	{
		ptr_rigor(num, count, new);
		return ;
	}
	num == 0 && new->checkzero == 1 ? new->width += count : 0;
	if (new->width > 0 && new->flag_minus == 0)
	{
		new->width = new->width - count - 2;
		while (!new->flag_zero && new->width-- && new->width >= 0)
			ft_putchar(' ', new);
	}
	ft_putstr("0x", new);
	if (new->flag_zero && !new->flag_minus)
		while (new->width-- && new->width >= 0)
			ft_putchar('0', new);
	if (new->checkzero == 0)
		ft_hex(num, 16, 0, new);
	showptr2(new, count);
}
