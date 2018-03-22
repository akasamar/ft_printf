#include "ft_printf.h"

void	rigor_unint(int	count, pfdata* new, int num)
{
	int rigor;

	rigor = new->rigor;
	if (new->rigor >= new->width)
	{
		new->width = 0;
		new->rigor -= count;
		while(new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
	}
	if (new->width > rigor)
	{
		new->width -= new->rigor;
		while (new->flag_minus == 0 && new->width-- && new->width >= 0)
			ft_putchar(' ', new);
		new->rigor -= count;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
	}
	ft_putnbr_unint(num, new);
	if (new->flag_minus == 1)
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
}

static void	changemod(unsigned long long *num, pfdata *new, va_list *va)
{
	if (new->type == 'U')
		new->mod_l = 1;
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

void	show_unint(pfdata *new, va_list *va) // sdelat' UNSIGNED LONG "U"
{
	unsigned long long num;
	int count;

	changemod(&num, new, va);
	count = un_countof(num);
	if (new->rigor > 0)
	{
		rigor_unint(count, new, num);
		return ;
	}
	new->width = new->width - count;
	if (new->width > 0 && new->flag_minus == 0)
	{
		while (new->width-- && new->width >= 0)
		{
			if (new->flag_zero && num)
				ft_putchar('0', new);
			else
				ft_putchar(' ', new);
		}
	}
	ft_putnbr_unint(num, new);
	if (new->width > 0 && new->flag_minus == 1)
	{
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
	}
}