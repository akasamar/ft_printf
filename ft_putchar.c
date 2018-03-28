/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:56:48 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/21 19:00:30 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putchar(char c, t_p *new)
{
	new->printflength++;
	write(1, &c, 1);
}

static int	for_wchar(int mas[], int i, int k, unsigned long long letter)
{
	if (k <= 7)
		mas[i] = letter;
	else if (k <= 11)
	{
		mas[i] = letter >> 6 | 0xC0;
		mas[++i] = (letter & 0x3F) | 0x80;
	}
	else if (k <= 16)
	{
		mas[i] = letter >> 12 | 0xE0;
		mas[++i] = (letter >> 6 & 0x3F) | 0x80;
		mas[++i] = (letter & 0x3F) | 0x80;
	}
	else
	{
		mas[i] = (letter >> 18 | 0xF0) & ~(1 << 3);
		mas[++i] = (letter >> 12 & 0x3F) | 0x80;
		mas[++i] = (letter >> 6 & 0x3F) | 0x80;
		mas[++i] = (letter & 0x3F) | 0x80;
	}
	return (i + 1);
}

void		ft_wputchar(wchar_t k, t_p *new)
{
	int					i;
	wchar_t				save_k;
	int					a;
	int					mas[4];

	a = 0;
	i = 0;
	save_k = k;
	while (++i < 32)
	{
		k & 0x01 ? a = i : 0;
		k >>= 1;
	}
	i = 0;
	i = for_wchar(mas, i, a, save_k);
	a = 0;
	while (a < i)
		ft_putchar(mas[a++], new);
}
