#include "ft_printf.h"

void	ptr_rigor(long long num, int count, pfdata *new)
{
	int def;

	def = new->rigor > count ? 2 + (new->rigor - count) + count : 0;
	if (new->rigor >= new->width)
	{
		new->width = 0;
		ft_putstr("0x", new);
		new->rigor -= count;
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
		ft_hex(num, 16, 0, new);
	}
	else if (new->width > new->rigor)
	{
		new->width -= def;
		new->rigor -= count;
		while (new->width >= 0 && new->flag_minus == 0 && new->width--)
			ft_putchar(' ', new);
		ft_putstr("0x", new);
		while (new->rigor-- && new->rigor >= 0)
			ft_putchar('0', new);
		ft_hex(num, 16, 0, new);
		while (new->width-- && new->width >= 0 && new->flag_minus == 1)
			ft_putchar(' ', new);
	} // proverit' 4to6 rigor ne stalo men'we
}

void	showptr(pfdata *new, va_list *va)
{
	long long num;
	int count;

	num = va_arg(*va, long long);
	count = countofhex(num, 16);
	if (new->rigor > 0)
	{
		ptr_rigor(num, count, new);
		return ;
	}
	if (new->width > 0 && new->flag_minus == 0)
	{
		new->width = new->width - count - 2;
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
	}
	ft_putstr("0x", new);
	ft_hex(num, 16, 0, new);
	if (new->width > 0 && new->flag_minus == 1)
	{
		new->width = new->width - count - 2;
		while (new->width-- && new->width >= 0)
			ft_putchar(' ', new);
	}
}