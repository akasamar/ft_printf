/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:36:28 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:36:29 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		six_rigor2(t_p *new, int count, int num)
{
	new->width = 0;
	new->rigor -= count;
	if (new->flag_diez && num)
		new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
	while (new->rigor-- && new->rigor >= 0)
		ft_putchar('0', new);
}

static	void	six_rigor(int count, t_p *new, int num)
{
	int rigor;

	rigor = new->rigor;
	new->flag_diez *= 2;
	if (new->rigor >= new->width)
		six_rigor2(new, count, num);
	else if (new->width > new->rigor)
	{
		if (new->rigor > count)
			new->width -= count + (new->rigor - count) + new->flag_diez;
		else
			new->width = new->width - count - new->flag_diez;
		while (new->flag_minus == 0 && new->width-- && new->width >= 0)
			ft_putchar(' ', new);
		if (new->flag_diez && num)
			new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
		new->rigor -= count;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
	}
	new->type == 'X' ? ft_hex(num, 16, 1, new) : ft_hex(num, 16, 0, new);
	if (new->flag_minus == 1)
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
}

static void		changemod(unsigned long long *num, t_p *new, va_list *va)
{
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

static	void	showhex2(t_p *new, int num)
{
	if (new->width > 0 && new->flag_minus == 0)
		if (new->width > 0 && new->flag_minus == 0)
			while (new->width--)
				new->flag_zero ? ft_putchar('0', new) : ft_putchar(' ', new);
	if (new->flag_diez && num && !new->flag_zero)
		new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
}

void			showhex(t_p *new, va_list *va)
{
	int					count;
	unsigned long long	num;

	changemod(&num, new, va);
	count = countofhex(num, 16);
	if (new->checkzero == 1 && num == 0)
	{
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
		return ;
	}
	if (new->rigor > 0)
	{
		six_rigor(count, new, num);
		return ;
	}
	if (new->flag_diez && num && new->flag_zero)
		new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
	new->width = new->width - count - (new->flag_diez * 2);
	showhex2(new, num);
	new->type == 'X' ? ft_hex(num, 16, 1, new) : ft_hex(num, 16, 0, new);
	if (new->width > 0 && new->flag_minus == 1)
		while (new->width--)
			ft_putchar(' ', new);
}
