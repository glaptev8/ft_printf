#include "../includes/ft_printf.h"

void	ft_putnbrmax(intmax_t n, t_printf *l)
{
	if (n == -9223372036854775807 - 1)
	{
		l->count += 20;
		write(1, "-9223372036854775808", 20);
	}
	else
	{
		if (n < 0)
		{
			l->count++;
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
			ft_putnbrmax(n / 10, l);
		if (!(l->precision == 1 && l->number == 0))
		{
			l->count++;
			ft_putchar((n % 10) + '0');
		}
	}
}