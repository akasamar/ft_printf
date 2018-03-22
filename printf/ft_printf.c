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
	va_list va;
	pfdata new;

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

int		main(void)
{
	int a;

	a = 5;
	long long k = 5;
	char c = 'a';
	char *s = "123";
	long long i = 9223372036854775807;
	//int k2 = (char)k;
	//char *str = "HAHAHA";
	// ft_printf("%llo|\n", i);
	// printf("%llo|\n", i);
	ft_printf("%4.0s|\n", "42");
	printf("%4.0s|", "42");
	return (0);
}
// # 0150 (long long)
//   ft_printf("%lld", -9223372036854775808); %5#.o 0
//   1. (    4) -->-(<--
//   2. (   20) -->-9223372036854775808<--
// # 0152 (intmax_t)
//   ft_printf("%jd", -9223372036854775808);
//   1. (    3) -->-(<--
//   2. (   20) -->-9223372036854775808<--

// # 0095 (int)
//   ft_printf("@moulitest: %#.o %#.0o", 0, 0);
//   1. (   13) -->@moulitest:  <--
//   2. (   15) -->@moulitest: 0 0<--

// # 0150 (long long)
//   ft_printf("%lld", -9223372036854775808);
//   1. (    2) -->-(<--
//   2. (   20) -->-9223372036854775808<--

// # 0152 (intmax_t)
//   ft_printf("%jd", -9223372036854775808);
//   1. (    2) -->-(<--
//   2. (   20) -->-9223372036854775808<--

// # 0175 (int)
//   ft_printf("@moulitest: %.d %.0d", 0, 0);
//   1. (   15) -->@moulitest: 0 0<--
//   2. (   13) -->@moulitest:  <--

// # 0176 (int)
//   ft_printf("@moulitest: %5.d %5.0d", 0, 0);
//   1. (   23) -->@moulitest:     0     0<--
//   2. (   23) -->@moulitest:            <--




//pohody nado vse inmax_t delat'
//dlina str

// c minusami ne rabotaet
// c -0 ne rabotaet
// vuvodit xyuinyu esli num < 0
// poproovat' stdarg vvuesti zaranee funckcii
//+8.15d
//ne rabotaet -0.7d flag 
//%4.2d|
//"%2.1d

//esle shirina > 4isla = vuebyetc9 liwnii probel
// printf("%-.d|", k);
 //printf("%hhhd|", k);
//	ft_printf("%-4s|\n", s);
//ft_printf("%.s|\n", s);
//ft_printf("%-7.15s|\n", s);

// ft_printf("%#5.x|\n", 42);
// 	printf("%#5.x|", 42); xyinIO vuvodit

	// ft_printf("% 1.d|\n", -2);
	// printf("% 1.d|", -2);

//s4ituvaet ne po por9dky flagi to4nost' i td 	printf("%6#o|", k);
//	printf("%5.o|", 255);
//po ymol4aniyu ll i l ???? a esli 3 lll??

// ne men9et long long 4islo pri smene modificatora
//long long mojno li dl9 lubogo tipa kak zamena??

// esli 4islo max v putnbr nado +2 ebanut'