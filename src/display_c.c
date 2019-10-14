#include "../includes/ft_printf.h"

void	display_c(t_printf *list)
{
	char	sym;

	sym = va_arg(list->argc, int);
	if (list->minus == 1)
	{
		ft_putchar(sym);
		while (list->width_space-- > 1)
			ft_putchar(' ');
	}
	else if (list->zero == 1)
	{
		while (list->width_space-- > 1)
			ft_putchar('0');
		ft_putchar(sym);
	}
	else
	{
		while (list->width_space-- > 1)
			ft_putchar(' ');
		ft_putchar(sym);
	}
}