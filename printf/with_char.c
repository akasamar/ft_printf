#include "ft_printf.h"

void		showchar(pfdata *new, va_list *va)
{
	char c;

	//printf(">%d<", new->width);
	c = va_arg(*va, int);
	if (new->width > 1 && new->flag_minus != 1)
	{
		new->width -= 1;
		while ((new->width)-- && new->width >= 0)
			ft_putchar(' ', new);
	}
	ft_putchar(c, new);
	if (new->width > 1 && new->flag_minus == 1)
	{
		new->width -= 1;
		while ((new->width)-- && new->width >= 0)
			ft_putchar(' ', new);
	}
}