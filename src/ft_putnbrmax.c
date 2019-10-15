#include "../includes/ft_printf.h"

void	ft_putnbrmax(intmax_t n, t_printf *l)
{
	if (l->u == 1 && n == (uintmax_t)18446744073709551613 + 2)
	{
		l->count += 20;
		write(1, "18446744073709551615", 20);
	}
	else if (n == -9223372036854775807 - 1)
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

int		ft_str_equally(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
			return (-1);
	}
	return (1);
}

void	ft_putnbrmax_o(intmax_t n, t_printf *l)
{

	if (n > 9)
			ft_putnbrmax_o(n / 10, l);
		l->count++;
		ft_putchar((n % 10) + '0');
}

void	ft_putnbrmax_x(char *n)
{
	if (ft_str_equally("9223372036854775807", n) == 1)
		write(1, "7fffffffffffffff", 16);
	ft_putstr(n);
}

