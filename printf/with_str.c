#include "ft_printf.h"

void	stringrigor(pfdata *new, va_list *va, char *s)
{
	int i;
	int dif;

	i = -1;
	dif = 0;
	if (ft_strlen(s) > new->rigor)
		dif = ft_strlen(s) - new->rigor;
	new->width = new->width - ft_strlen(s) + dif;
	if (new->width > 0 && new->flag_minus == 0)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
	if (new->rigor > 0)
		while (*s && new->rigor--)
		{
			ft_putchar(*s, new);
			s++;
		}
	else
		ft_putstr(s, new);
	if (new->width > 0 && new->flag_minus == 1)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
}

void	showstring(pfdata *new, va_list *va)
{
	char *s;

	s = va_arg(*va, char *);
	if (s == NULL)
	{
		ft_putstr("(null)", new);
		return ;
	}
	if (new->rigor > 0)
	{
		stringrigor(new, va, s);
		return ;
	}
	new->checkzero == 1 ? new->width += ft_strlen(s) : 0;
	new->width = new->width - ft_strlen(s);
	if (new->width > 0 && new->flag_minus == 0)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
	new->checkzero != 1 ? ft_putstr(s, new) : 0;
	if (new->width > 0 && new->flag_minus == 1)
		while ((new->width)-- && new->width > -1)
			ft_putchar(' ', new);
}

	// ft_printf("%-7.8s|\n", s);
	// printf("%-7.8s|", s);