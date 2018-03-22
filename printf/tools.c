/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 00:59:57 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/02 23:32:56 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		countof(long long n)
{
	int		i;

	i = 0;
	if (n == -9223372036854775807 - 1)
		return (19);
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

int		un_countof(unsigned int n)
{
	int		i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

void	ft_putnbr_unint(unsigned long long n, pfdata *new)
{
	if (n > 9)
		ft_putnbr_unint(n / 10, new);
	ft_putchar(n % 10 + 48, new);
}

void	ft_putnbr_ll(long long n, pfdata *new)
{
	if (n == -9223372036854775807 - 1)
	{
		if (new->flag_zero == 0)
			ft_putchar('-', new);
		ft_putstr("9223372036854775808", new);
		return ;
	}
	if (n < 0)
	{
		if (new->flag_zero == 0)
			ft_putchar('-', new);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_ll(n / 10, new);
	ft_putchar(n % 10 + 48, new);
}

int		countofhex(long long hex, int sys)
{
	int 	i;

	i = 0;
	while (hex > sys - 1)
	{
		hex = hex / sys;
		i++;
	}
	return (i + 1);
}

pfdata	create_struct(void)
{
	pfdata new;

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

void	rewrite_struct(pfdata *new)
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