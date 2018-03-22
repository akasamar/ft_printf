/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <akasamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:36:27 by akasamar          #+#    #+#             */
/*   Updated: 2018/03/05 20:26:20 by akasamar         ###   ########.fr       */
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


typedef struct s_pa
{
	char	type;
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_diez;
	int		width;
	int		rigor;
	int		mod_h;
	int		mod_hh;
	int		mod_l;
	int		mod_ll;
	int		mod_bigl;
	int		mod_j;
	int		mod_z;
	int		printflength;
	int		checklength;
	int		checkzero;
}				pfdata;

size_t				ft_strlen(char *s);
void				ft_putchar(char c, pfdata *new);
int					ft_isdigit(int c);
void				ft_putstr(char const *s, pfdata *new);

int		ft_printf(char *format, ...);
void	start_prog(char *format, va_list *va, pfdata *new);
void	showinteger(pfdata *new, va_list *va);
int		countof(long long n);
pfdata	create_struct (void);
void	rewrite_struct(pfdata *new);
void	treatment(char *format, va_list *va, int* i, pfdata* new);
void	showchar(pfdata *new, va_list *va);
void	showstring(pfdata *new, va_list *va);
void	showoct(pfdata *new, va_list *va);
void	showhex(pfdata *new, va_list *va);
int		countofhex(long long hex, int sys);
void	ft_hex(unsigned long long k, int sys, int bigx_or_not, pfdata *new);
void	ft_putnbr_ll(long long n, pfdata *new);
void	showptr(pfdata *new, va_list *va);
void	show_unint(pfdata *new, va_list *va);
int		un_countof(unsigned int n);
void	ft_putnbr_unint(unsigned long long n, pfdata *new);


#endif