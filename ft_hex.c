/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 22:29:38 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/27 22:29:44 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert(unsigned long long k, int bigx_or_not, t_p *new)
{
	if (k > 9 && bigx_or_not == 1)
		ft_putchar(k + 55, new);
	else if (k > 9 && bigx_or_not == 0)
		ft_putchar(k + 87, new);
	else
		ft_putchar(k + 48, new);
}

void	ft_hex(unsigned long long k, int sys, int b, t_p *new)
{
	if (k > (unsigned long long)sys - 1)
		ft_hex(k / (unsigned long long)sys, sys, b, new);
	if (k < (unsigned long long)sys)
		ft_convert(k, b, new);
	else
		ft_convert(k % (unsigned long long)sys, b, new);
}

t_p		create_struct(void)
{
	t_p new;

	new.width = 0;
	new.type = 0;
	new.flag_minus = 0;
	new.rigor = 0;
	new.flag_plus = 0;
	new.flag_space = 0;
	new.flag_zero = 0;
	new.flag_diez = 0;
	new.mod_h = 0;
	new.mod_hh = 0;
	new.mod_l = 0;
	new.mod_ll = 0;
	new.mod_bigl = 0;
	new.mod_j = 0;
	new.mod_z = 0;
	new.printflength = 0;
	new.checklength = 1;
	new.checkzero = 0;
	return (new);
}

void	rewrite_struct(t_p *new)
{
	new->width = 0;
	new->type = 0;
	new->flag_minus = 0;
	new->rigor = 0;
	new->flag_plus = 0;
	new->flag_space = 0;
	new->flag_zero = 0;
	new->flag_diez = 0;
	new->mod_h = 0;
	new->mod_hh = 0;
	new->mod_l = 0;
	new->mod_ll = 0;
	new->mod_bigl = 0;
	new->mod_j = 0;
	new->mod_z = 0;
	new->checkzero = 0;
}
