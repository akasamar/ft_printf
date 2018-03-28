/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:36:19 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/02 23:32:56 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_type(t_p *new, va_list *va)
{
	if (new->mod_l == 1 && new->type == 'c')
		new->type = 'C';
	else if (new->mod_l == 1 && new->type == 's')
		new->type = 'S';
	if (new->type == 'i' || new->type == 'd' || new->type == 'D')
		showinteger(new, va);
	else if (new->type == 'c')
		showchar(new, va);
	else if (new->type == 's')
		showstring(new, va);
	else if (new->type == 'o' || new->type == 'O')
		showoct(new, va);
	else if (new->type == 'x' || new->type == 'X')
		showhex(new, va);
	else if (new->type == 'p')
		showptr(new, va);
	else if (new->type == 'u' || new->type == 'U')
		show_unint(new, va);
	else if (new->type == 'C')
		read_wchar(new, va_arg(*va, wchar_t));
	else if (new->type == 'S')
		read_swchar(new, va_arg(*va, wchar_t *));
	rewrite_struct(new);
}

void	treatment_flags(char *format, int *i, t_p *new)
{
	if (format[*i] == '-')
	{
		new->flag_minus = 1;
		new->flag_zero = 0;
	}
	else if (format[*i] == '+')
		new->flag_plus = 1;
	else if (format[*i] == ' ')
		new->flag_space = 1;
	else if (format[*i] == '0' && !new->flag_minus)
		new->flag_zero = 1;
	else if (format[*i] == '#')
		new->flag_diez = 1;
	(*i)++;
	return ;
}

void	getmod(char *format, int *i, t_p *new)
{
	int count;

	if (format[*i] == 'h')
	{
		count = 1;
		while (format[++(*i)] == 'h')
			count++;
		if (count % 2 == 0)
			new->mod_hh = 1;
		else
			new->mod_h = 1;
		return ;
	}
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
		new->mod_ll = 1;
	else if (format[*i] == 'l')
		new->mod_l = 1;
	else if (format[*i] == 'z')
		new->mod_z = 1;
	else if (format[*i] == 'j')
		new->mod_j = 1;
	(*i)++;
	return ;
}

void	start_prog(char *format, va_list *va, t_p *new)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			if (format[i] == '%' && !format[i + 1])
			{
				i++;
				continue;
			}
			i++;
			treatment(format, &i, new);
			get_type(new, va);
			i++;
			continue ;
		}
		ft_putchar(format[i++], new);
	}
}
