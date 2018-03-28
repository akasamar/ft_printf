/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_unint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:38:28 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:38:29 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	rigor_unint(int count, t_p *new, int num)
{
	if (new->rigor >= new->width)
	{
		new->width = 0;
		new->rigor -= count;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
	}
	else if (new->width > new->rigor)
	{
		if (new->rigor > count)
			new->width = new->width - (new->rigor - count) - count;
		else
			new->width -= count;
		while (new->flag_minus == 0 && new->width-- && new->width >= 0)
			ft_putchar(' ', new);
		new->rigor -= count;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
	}
	ft_putnbr_unint(num, new);
	if (new->flag_minus == 1)
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
	return ;
}

static void	changemod(unsigned long long *num, t_p *new, va_list *va)
{
	if (new->type == 'U')
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

void		show_unint(t_p *new, va_list *va)
{
	unsigned long long	num;
	int					count;

	changemod(&num, new, va);
	count = un_countof(num);
	if (new->rigor > 0)
	{
		rigor_unint(count, new, num);
		return ;
	}
	new->checkzero == 1 && num == 0 ? new->width += count : count;
	new->width -= count;
	if (new->width > 0 && new->flag_minus == 0)
		while (new->width-- && new->width >= 0)
			new->flag_zero && num ? ft_putchar('0', new) : ft_putchar(' ', new);
	new->checkzero && !num ? 0 : ft_putnbr_unint(num, new);
	if (new->width > 0 && new->flag_minus == 1)
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
}

void		showinteger3(t_p *new, int neg_num, long long num)
{
	new->flag_plus == 1 ? ft_putchar('+', new) : 0;
	neg_num && new->flag_zero ? ft_putchar('-', new) : 0;
	new->checkzero == 1 && num == 0 ? 0 : ft_putnbr_ll(num, new);
}
