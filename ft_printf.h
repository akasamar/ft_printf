/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:36:27 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/28 13:11:57 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <wchar.h>
# include <locale.h>

typedef struct	s_pa
{
	char		type;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			flag_zero;
	int			flag_diez;
	int			width;
	int			rigor;
	int			mod_h;
	int			mod_hh;
	int			mod_l;
	int			mod_ll;
	int			mod_bigl;
	int			mod_j;
	int			mod_z;
	int			printflength;
	int			checklength;
	int			checkzero;
}				t_p;

int				ft_strlen(char *s);
void			ft_putchar(char c, t_p *new);
int				ft_isdigit(int c);
void			ft_putstr(char const *s, t_p *new);
void			treatment_flags(char *format, int *i, t_p *new);
void			getmod(char *format, int *i, t_p *new);
void			treatment(char *format, int *i, t_p *new);
int				ft_printf(char *format, ...);
void			start_prog(char *format, va_list *va, t_p *new);
void			showinteger(t_p *new, va_list *va);
int				countof(long long n);
t_p				create_struct (void);
void			rewrite_struct(t_p *new);
void			showchar(t_p *new, va_list *va);
void			showstring(t_p *new, va_list *va);
void			showoct(t_p *new, va_list *va);
void			showhex(t_p *new, va_list *va);
int				countofhex(long long hex, int sys);
void			ft_hex(unsigned long long k, int sys, int b, t_p *new);
void			ft_putnbr_ll(long long n, t_p *new);
void			showptr(t_p *new, va_list *va);
void			show_unint(t_p *new, va_list *va);
int				un_countof(unsigned int n);
void			ft_putnbr_unint(unsigned long long n, t_p *new);
void			read_wchar(t_p *new, wchar_t k);
void			read_swchar(t_p *new, wchar_t *s);
void			ft_wputchar(wchar_t k, t_p *new);
void			ft_wputstr(wchar_t *s, t_p *new);
int				ft_wstrlen(wchar_t *s);
void			showinteger3(t_p *new, int neg_num, long long num);

#endif
