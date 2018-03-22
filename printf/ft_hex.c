#include "ft_printf.h"

static void	ft_convert(unsigned long long k, int bigx_or_not, pfdata *new) //long long
{
	if (k > 9 && bigx_or_not == 1)
		ft_putchar(k + 55, new);
	else if (k > 9 && bigx_or_not == 0)
		ft_putchar(k + 87, new);
	else
		ft_putchar(k + 48, new);
}

void		ft_hex(unsigned long long k, int sys, int bigx_or_not, pfdata *new)
{
	if (k > sys - 1)
		ft_hex(k / sys, sys, bigx_or_not, new);
	if (k < sys)
		ft_convert(k, bigx_or_not, new);
	else
		ft_convert(k % sys, bigx_or_not, new);
}
