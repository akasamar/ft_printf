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

void	ft_putnbr_unint(unsigned long long n, t_p *new)
{
	if (n > 9)
		ft_putnbr_unint(n / 10, new);
	ft_putchar(n % 10 + 48, new);
}

void	ft_putnbr_ll(long long n, t_p *new)
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
	int i;

	i = 0;
	while (hex > sys - 1)
	{
		hex = hex / sys;
		i++;
	}
	return (i + 1);
}
