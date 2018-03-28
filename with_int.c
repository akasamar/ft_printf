/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:55:48 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:34:22 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	showint_rigor2(t_p *new, int count, int *rigor, int neg_num)
{
	if (new->rigor >= new->width)
		new->rigor > count ? new->rigor -= count : 0;
	if (*rigor > count)
		new->width = new->width - (*rigor - count) - count;
	if (*rigor > count)
		new->width -= new->flag_plus + new->flag_space + neg_num;
	else
		new->width -= count + neg_num + new->flag_space + new->flag_plus;
	*rigor -= count;
	if (new->width >= *rigor && !new->flag_minus)
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
}

static void	showint_rigor(t_p *new, long long num, int count, int neg_num)
{
	int rigor;
	int width;

	rigor = new->rigor;
	width = new->width;
	new->flag_plus ? new->flag_space = 0 : 0;
	showint_rigor2(new, count, &rigor, neg_num);
	if (neg_num)
	{
		ft_putchar('-', new);
		num *= -1;
	}
	if (new->flag_plus)
		ft_putchar('+', new);
	while (rigor-- && rigor >= 0)
		ft_putchar('0', new);
	ft_putnbr_ll(num, new);
	if (new->width >= rigor && new->flag_minus)
	{
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
	}
}

static void	changemod(long long *num, t_p *new, va_list *va)
{
	if (new->type == 'D')
		new->mod_l = 1;
	if (new->mod_z == 1)
		*num = (size_t)va_arg(*va, long long);
	else if (new->mod_j == 1)
		*num = (intmax_t)va_arg(*va, long long);
	else if (new->mod_ll == 1)
		*num = va_arg(*va, long long);
	else if (new->mod_l == 1)
		*num = (long)va_arg(*va, long long);
	else if (new->mod_h == 1)
		*num = (short)va_arg(*va, long long);
	else if (new->mod_hh == 1)
		*num = (char)va_arg(*va, long long);
	else
		*num = (int)va_arg(*va, long long);
}

void		showinteger2(t_p *new, int count, int neg_num, long long num)
{
	if (new->width > 0 && new->flag_minus == 1)
	{
		new->width -= count + new->flag_plus + neg_num + new->flag_space;
		new->flag_plus ? ft_putchar('+', new) : 0;
		new->checkzero == 1 && num == 0 ? 0 : ft_putnbr_ll(num, new);
		while (new->width-- && new->width > -1)
			ft_putchar(' ', new);
	}
	else if (new->width > 0 && new->flag_minus == 0)
	{
		new->width -= count + new->flag_plus + neg_num + new->flag_space;
		if (new->flag_plus == 1)
			ft_putchar('+', new);
		else if (neg_num && new->flag_zero == 1)
			ft_putchar('-', new);
		while (new->width-- && new->width > -1)
			new->flag_zero ? ft_putchar('0', new) : ft_putchar(' ', new);
		new->checkzero == 1 && num == 0 ? 0 : ft_putnbr_ll(num, new);
	}
	else
		showinteger3(new, neg_num, num);
}

void		showinteger(t_p *new, va_list *va)
{
	long long	num;
	int			count;
	int			neg_num;

	changemod(&num, new, va);
	count = countof(num);
	neg_num = 0;
	if (num < 0)
	{
		new->flag_plus = 0;
		new->flag_space = 0;
		neg_num = 1;
	}
	if (new->flag_space && !new->flag_plus && !neg_num)
		ft_putchar(' ', new);
	if (new->rigor != 0)
	{
		showint_rigor(new, num, count, neg_num);
		return ;
	}
	new->checkzero == 1 && num == 0 ? count = 0 : count;
	showinteger2(new, count, neg_num, num);
}
