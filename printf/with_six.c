#include "ft_printf.h"

void	six_rigor(int	count, pfdata* new, int num)
{
	int rigor;

	rigor = new->rigor;
	new->flag_diez *= 2;
	if (new->rigor >= new->width)
	{
		new->width = 0;
		new->rigor -= count;
		if (new->flag_diez && num)
			new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new); //rigor
	}
	else if (new->width > new->rigor)  //width
	{
		if (new->rigor > count)
			new->width = new->width - count - (new->rigor - count) - new->flag_diez;
		else
			new->width = new->width - count - new->flag_diez;
		while (new->flag_minus == 0 && new->width-- && new->width >= 0)
			ft_putchar(' ', new);
		if (new->flag_diez && num) 
			new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
		new->rigor -= count;
		while (new->rigor-- && new->rigor >= 0) 
			ft_putchar('0', new);
	}
	if (new->type == 'X')
		ft_hex(num, 16, 1, new);
	else
		ft_hex(num, 16, 0, new);
	if (new->flag_minus == 1)
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
}

static void	changemod(unsigned long long *num, pfdata *new, va_list *va)
{
	if (new->mod_z == 1)
		*num = (ssize_t)va_arg(*va, unsigned long long);
	else if (new->mod_j == 1)
		*num = (uintmax_t)va_arg(*va, unsigned long long);
	else if (new->mod_ll == 1)
		*num = va_arg(*va, unsigned long long);
	else if (new->mod_l == 1)
		*num = (unsigned long)va_arg(*va, unsigned long long);
	else if (new->mod_h == 1)
		*num = (unsigned short)va_arg(*va, unsigned long long); 
	else if (new->mod_hh == 1)
		*num = (unsigned char)va_arg(*va, unsigned long long);
	else
		*num = (unsigned int)va_arg(*va, unsigned long long);
}

void	showhex(pfdata *new, va_list *va)
{
	int count;
	unsigned long long num;

	changemod(&num, new, va);
	if (new->checkzero == 1 && num == 0)
	{
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
		return ;
	}
	count = countofhex(num, 16);
	if (new->rigor > 0) 
	{
		six_rigor(count, new, num);
		return ;
	}
	if (new->flag_diez && num && new->flag_zero)
		new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
	new->width = new->width - count - (new->flag_diez * 2);
	if (new->width > 0 && new->flag_minus == 0)
	{
		if (new->width > 0 && new->flag_minus == 0)
		{	
			while (new->width--)
			{
				if (new->flag_zero)
				{
					ft_putchar('0', new);
					continue ;
				}
				ft_putchar(' ', new);
			}
		}
	}
	if (new->flag_diez && num && !new->flag_zero)
		new->type == 'X' ? ft_putstr("0X", new) : ft_putstr("0x", new);
	if (new->type == 'X')
		ft_hex(num, 16, 1, new);
	else 
		ft_hex(num, 16, 0, new);
	if (new->width > 0 && new->flag_minus == 1)
		while (new->width--)
			ft_putchar(' ', new);
}