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

intmax_t	get_number_for_d(t_printf *list)
{
	intmax_t n;

	if (list->l == 1)
		n = va_arg(list->argc, long int);
	else if (list->ll == 1)
		n = va_arg(list->argc, long long int);
	else if (list->h == 1)
		n = (short)va_arg(list->argc, int);
	else if (list->hh == 1)
		n = (char)va_arg(list->argc, int);
	else
		n = va_arg(list->argc, int);
	n = (intmax_t)n;
	return (n);
}

int		get_number_len(intmax_t n, t_printf list)
{
	int		i;

	i = 0;
	if (n < 0 || list.plus == 1)
		i++;
	n < 0 ? n *= -1 : 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void		display_d(t_printf *list)
{
	intmax_t n;
	int		len;
	int		i;
	int		len_num;

	n = get_number_for_d(list);
	list->number = n;
	len = get_number_len(n, *list);
	len_num = len;
	if (list->precision == 1 || list->minus == 1)
	{
		if (list->zero == 1)
		{
			list->width = 1;
		}
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ? list->precision_space - len : 0);
	if ((list->number < 0 || list->plus == 1) && (list->precision_space > len_num - 1))
		len++;
	if (list->space == 1 && list->plus != 1 && list->number >= 0)
	{
		len++;
		list->count++;
		ft_putchar(' ');
	}
	if (list->zero == 1)
	{
		i = list->width_space;
		while (i-- > len)
		{
			if (n < 0 || list->plus == 1)
			{
				list->count++;
				n < 0 ? n *= -1 : 0;
				list->plus = 0;
				list->number < 0 ? ft_putchar('-') : ft_putchar('+');
			}
			list->count++;
			ft_putchar('0');
		}
	}
	else if (list->width == 1)
	{
		i = list->width_space;
		while (i-- > len)
		{
			list->count++;
			ft_putchar(' ');
		}
	}
	if (list->plus == 1)
	{
		if (list->zero == 0)
		{
			list->count++;
			n < 0 ? ft_putchar('-') : ft_putchar('+');
			n < 0 ? n *= (-1) : 0;
		}
	}
	if (list->precision == 1)
	{
//		printf("(%d)", n);
		i = 0;
		if (list->number < 0 || list->plus == 1)
			i--;
		if (n < 0)
		{
			list->count++;
			n *= -1;
			ft_putchar('-');
		}
		while (i++ < list->precision_space - len_num)
		{
			list->count++;
			ft_putchar('0');
		}
	}
	if (list->minus == 1)
	{
		i = list->width_space;
		if (!(list->precision_space <= 0 && n == 0))
			ft_putnbrmax(n, list);
		while (i-- > len)
		{
			list->count++;
			ft_putchar(' ');
		}
	}
	else if (!(list->precision_space <= 0 && n == 0 && list->precision == 1))
		ft_putnbrmax(n, list);
}