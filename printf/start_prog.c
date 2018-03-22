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

void	get_type(pfdata *new, va_list *va) //onpedel9em tip
{
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

	rewrite_struct(new);
}

void	treatment_flags(char *format, va_list *va, int* i, pfdata* new)
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
	else if(format[*i] == '0' && new->flag_minus == 0)
		new->flag_zero = 1;
	else if(format[*i] == '#')
		new->flag_diez = 1;
	(*i)++;
	return ;
}

void	getmod(char *format, va_list *va, int* i, pfdata* new)
{
	int count;

	//count = 0;
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
	else if(format[*i] == 'l')
		new->mod_l = 1;
	else if(format[*i] == 'z')
		new->mod_z = 1;
	else if(format[*i] == 'j')
		new->mod_j = 1;
	(*i)++;
	return ;
}

void	treatment(char *format, va_list *va, int* i, pfdata* new) //sobiraem flagi i td
{
	int k;

	k = 0;
	while (1)
	{
	if (format[*i] == '0' || format[*i] == '+' || format[*i] == '-' || format[*i] == ' ' \
		|| format[*i] == '#')
	{
		treatment_flags(format, va, i, new);
		continue ;
	}
	if  (ft_isdigit(format[*i])) //width //(ft_isdigit(format[*i]) && format[*i - 1] != '.' && format[*i - 1] != '%') ||
	{
		while (ft_isdigit(format[*i]))
		{
			k = k * 10 + (format[(*i)++] - 48);
			new->width = k;
		}
		k = 0;
		continue ;
	}
	if (format[*i] == '.') //rigor // && (ft_isdigit(format[*i + 1]) || format[*i + 1] == 's' || format[*i + 1] == 'd')
	{
		new->checkzero = 0;
		while (ft_isdigit(format[++(*i)]))
			k = k * 10 + (format[*i] - 48);
		new->rigor = k;
		if (new->rigor == 0)
			new->checkzero = 1;
		k = 0;
		continue ;
	}
	if (format[*i] == 'h' || format[*i] == 'l' || format[*i] == 'j' || format[*i] == 'z')
	{
		getmod(format, va, i, new);
		continue ;
	}
	if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'c' || format[*i] == 's' \
		|| format[*i] == 'o' || format[*i] == 'x' || format[*i] == 'X' || format[*i] == 'p' \
		|| format[*i] == 'D' || format[*i] == 'u' || format[*i] == 'U' || format[*i] == 'O')
	{
		new->type = format[*i];
		return ;
	}
	else
	{
		new->width -= 1;
		while (new->width >= 0 && !new->flag_minus && new->width--)
			ft_putchar(' ', new);
		ft_putchar(format[*i], new); //ne zabit' pro russkiy shrift
		while (new->width-- && new->width >= 0 && new->flag_minus)
			ft_putchar(' ', new);
		return ;
	}
	}
}


void	start_prog(char *format, va_list *va, pfdata *new)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i++;
		else if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			treatment(format, va, &i, new);
			get_type(new, va);
			i++;
			continue ;
		}
		ft_putchar(format[i++], new);
	}
}