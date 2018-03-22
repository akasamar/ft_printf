/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:55:48 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/05 20:31:46 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	showint_rigor(pfdata *new, long long num, int count, int neg_num)
{
	int rigor;
	int dif;

	rigor = new->rigor; 
	dif = new->width - count - new->flag_space - neg_num;
	if (new->width > rigor && new->flag_minus != 1)
	{
		rigor = new->width - rigor - new->flag_plus - neg_num - new->flag_space;
		while (rigor-- && dif-- && rigor >= 0 && dif >= 0)
			ft_putchar(' ', new);
	}
	rigor = new->rigor;
	if (new->rigor > count)
		new->rigor -= count;
	if (neg_num == 1)
	{
		ft_putchar('-', new);
		num *= -1;
	}
	if (new->flag_plus == 1)
		ft_putchar('+', new);
	while (new->rigor-- && rigor > count)
		ft_putchar('0', new);
	ft_putnbr_ll(num, new);
	if (new->width > rigor && new->flag_minus == 1)
	{
		rigor = new->width - rigor - new->flag_plus - neg_num - new->flag_space;
		while (rigor-- && dif-- && rigor >= 0 && dif >= 0)
			ft_putchar(' ', new);
	}
}

static void	changemod(long long *num, pfdata *new, va_list *va)
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

void		showinteger(pfdata *new, va_list *va) //flag_space SDELAT' ZAVTRA A TO ZAEBALO
{
	long long num; 
	int count;
	int neg_num;

	changemod(&num, new, va);

	count =	countof(num);
	neg_num = 0;
		if (num < 0)
		{
			new->flag_plus = 0;
			new->flag_space = 0;
			neg_num = 1; 
		}
		if (new->flag_space && num > 0 && new->flag_plus == 0 && neg_num == 0)
			ft_putchar(' ', new);
		if (new->rigor != 0)
		{
			showint_rigor(new, num, count, neg_num);
			return ;	
		}
		(new->checkzero == 1 && num == 0) ? count = 0 : count;
		if (new->width > 0 && new->flag_minus == 1)
		{
			new->width = new->width - count - new->flag_plus - neg_num - new->flag_space;
			if (new->flag_plus == 1)
				ft_putchar('+', new);
			(new->checkzero == 1 && num == 0) ? 0 : ft_putnbr_ll(num, new);
			while (new->width-- && new->width > -1)
				ft_putchar(' ', new);
		}
		else if (new->width > 0 && new->flag_minus == 0)
		{
			new->width = new->width - count - new->flag_plus - neg_num - new->flag_space;
			if (new->flag_plus == 1)
				ft_putchar('+', new);
			else if (neg_num && new->flag_zero == 1)
				ft_putchar('-', new);
			while (new->width-- && new->width > -1)
			{
				if (new->flag_zero == 1)
				{
					ft_putchar('0', new);
					continue ;
				}
				ft_putchar(' ', new);
			}
			(new->checkzero == 1 && num == 0) ? 0 : ft_putnbr_ll(num, new);
		}
		else
		{
			if (new->flag_plus == 1)
				ft_putchar('+', new);
			if (neg_num && new->flag_zero == 1)
				ft_putchar('-', new);
			(new->checkzero == 1 && num == 0) ? 0 : ft_putnbr_ll(num, new);
		}
}

// static void	changemod(long long *num, pfdata *new)
// {
// 	long long change;

// 	if (new->mod_ll == 1)
// 		change = (long long int)*num;
// 	else if (new->mod_l == 1)
// 		change = (long int)*num;
// 	else if (new->mod_h == 1)
// 		change = (short int)*num; 
// 	else if (new->mod_hh == 1)
// 		change = (char)*num;

// 	if (new->mod_ll == 1 || new->mod_l == 1 || new->mod_h == 1 \
// 		|| new->mod_hh == 1)
// 	*num = change;
// }
