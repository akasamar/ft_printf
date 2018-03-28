/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:37:03 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/05 23:19:41 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	va_list	va;
	t_p		new;

	va_start(va, format);
	new = create_struct();
	if (format)
	{
		start_prog(format, &va, &new);
		va_end(va);
		return (new.printflength);
	}
	else
		return (-1);
}
