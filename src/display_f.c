#include "../includes/ft_printf.h"

void	display_minus_f(t_printf *list, int len, char *str)
{
	int j;

	j = list->width_space;
	if (!(list->precision_space <= 0 && list->number == 0))
	{
		ft_putstr(str);
		if (list->precision_space == 0 && list->sharp == 1)
		{
			list->count++;
			ft_putchar('.');
		}
	}
	while (j-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_precision_f(t_printf *list)
{
	int j;

	if (list->number < 0)
	{
		list->count++;
		ft_putchar('-');
	}
}

void	display_plus_f(t_printf *list)
{
	list->count++;
	list->number < 0 ? ft_putchar('-') : ft_putchar('+');
	list->number < 0 ? list->number *= (-1) : 0;
}

void	display_f(t_printf *list)
{
	double n;
	int len_num;
	int	len;
	char *str;

	if (list->L)
		n = va_arg(list->argc, long double);
	else
		n = va_arg(list->argc, double);
	len = initialze_display_f(list, n, &len_num, &str);
//	if (list->L == 1)
//		str = ft_l_ftoa(n, list->precision_space);
//	else
//		str = ft_ftoa(n, list->precision_space);
//	str++;
//	if (list->precision_space <= 0)
//		*ft_strchr(str, '.') = '\0';
	if (list->space == 1 && list->plus != 1 && list->number >= 0)
		display_space_d(list, &len);
	if (list->zero == 1)
		display_zero_d(list, &len, (intmax_t *)&(list->number));
	else if (list->width == 1)
		display_width_d(list, len);
//	printf("(%d)", list->zero);
	if (list->plus == 1)
		display_plus_f(list);
	if (list->precision == 1)
		display_precision_f(list);
	if (list->minus == 1)
		display_minus_f(list, len, str);
	else if (!(list->precision_space <= 0 && n == 0 && list->precision == 1))
	{
		list->count += ft_strlen(str);
		ft_putstr(str);
		if (list->sharp == 1 && list->precision_space <= 0)
		{
			list->count++;
			ft_putchar('.');
		}
	}
}