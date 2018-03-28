/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_prog2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:32:28 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:32:31 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	treatment4(char *format, int *i, t_p *new, int *k)
{
	if (format[*i] == '0' || format[*i] == '+' || format[*i] == '-' \
	|| format[*i] == ' ' || format[*i] == '#')
	{
		treatment_flags(format, i, new);
		return (1);
	}
	if (ft_isdigit(format[*i]))
	{
		while (ft_isdigit(format[*i]))
		{
			*k = *k * 10 + (format[(*i)++] - 48);
			new->width = *k;
		}
		*k = 0;
		return (1);
	}
	return (0);
}

static void	treatment3(char *format, int *i, t_p *new)
{
	if (format[*i] == 'd' || format[*i] == 'i' || format[*i] == 'c' \
	|| format[*i] == 's' || format[*i] == 'o' || format[*i] == 'x' \
	|| format[*i] == 'X' || format[*i] == 'p' || format[*i] == 'D' \
	|| format[*i] == 'u' || format[*i] == 'U' || format[*i] == 'O' \
	|| format[*i] == 'C' || format[*i] == 'S')
		new->type = format[*i];
	else
	{
		new->width -= 1;
		while (new->width >= 0 && !new->flag_minus && new->width--)
			new->flag_zero ? ft_putchar('0', new) : ft_putchar(' ', new);
		ft_putchar(format[*i], new);
		while (new->width-- && new->width >= 0 && new->flag_minus)
			ft_putchar(' ', new);
	}
}

static void	treatment2(char *format, int *i, t_p *new, int *k)
{
	new->checkzero = 0;
	while (ft_isdigit(format[++(*i)]))
		*k = *k * 10 + (format[*i] - 48);
	new->rigor = *k;
	if (new->rigor == 0)
		new->checkzero = 1;
	*k = 0;
}

void		treatment(char *format, int *i, t_p *new)
{
	int k;

	k = 0;
	while (1)
	{
		if (treatment4(format, i, new, &k) == 1)
			continue ;
		if (format[*i] == '.')
		{
			treatment2(format, i, new, &k);
			continue ;
		}
		if (format[*i] == 'h' || format[*i] == 'l' || \
			format[*i] == 'j' || format[*i] == 'z')
		{
			getmod(format, i, new);
			continue ;
		}
		treatment3(format, i, new);
		return ;
	}
}
