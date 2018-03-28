/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_oct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:35:18 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:35:19 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	oct_rigor(int count, t_p *new, long long num)
{
	if (new->rigor >= new->width)
	{
		new->width = 0;
		new->rigor = new->rigor - count - new->flag_diez;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
	}
	else if (new->width > new->rigor)
	{
		if (new->rigor > count)
			new->width -= (new->rigor - count) + count + new->flag_diez;
		else
			new->width -= count;
		while (new->flag_minus == 0 && new->width-- && new->width >= 0)
			ft_putchar(' ', new);
		new->rigor = new->rigor - count - new->flag_diez;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
	}
	if (new->flag_diez && num)
		ft_putchar('0', new);
	ft_hex(num, 8, 0, new);
	if (new->flag_minus == 1)
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
}

static void	changemod(unsigned long long *num, t_p *new, va_list *va)
{
	if (new->type == 'O')
		new->mod_l = 1;
	if (new->mod_z == 1)
		*num = (ssize_t)va_arg(*va, unsigned long long);
	else if (new->mod_j == 1)
		*num = (uintmax_t)va_arg(*va, unsigned long long);
	else if (new->mod_ll == 1)
		*num = va_arg(*va, unsigned long long);
	else if (new->mod_l == 1)
		*num = (unsigned long)va_arg(*va, unsigned long long);
	else if (new->mod_h == 1)
		*num = (unsigned short)va_arg(*va, unsigned long long);
	else if (new->mod_hh == 1)
		*num = (unsigned char)va_arg(*va, unsigned long long);
	else
		*num = (unsigned int)va_arg(*va, unsigned long long);
}

void		showoct(t_p *new, va_list *va)
{
	int					count;
	unsigned long long	num;

	changemod(&num, new, va);
	count = countofhex(num, 8);
	if (new->rigor > 0)
	{
		oct_rigor(count, new, num);
		return ;
	}
	(num == 0 && new->checkzero == 1) ? count = 0 : count;
	new->width = new->width - count - new->flag_diez;
	if (new->width > 0 && new->flag_minus == 0)
		while (new->width--)
			new->flag_zero == 1 ? ft_putchar('0', new) : ft_putchar(' ', new);
	if (new->flag_diez && num)
		ft_putchar('0', new);
	if (!(new->checkzero == 1 && num == 0))
		ft_hex(num, 8, 0, new);
	else if (new->checkzero == 1 && num == 0 && new->flag_diez == 1)
		ft_hex(num, 8, 0, new);
	if (new->width > 0 && new->flag_minus == 1)
		while (new->width--)
			ft_putchar(' ', new);
}
