#include "../includes/ft_printf.h"

void	display_minus_f(t_printf *list, int i, int d, int len)
{
	int j;
	int len_num;

	len_num = get_number_len(list->integer, *list) + get_number_len_for_uint(list->decimal);
	j = list->width_space;
	if (!(list->precision_space <= 0 && list->number == 0))
			ft_putnbrmax_for_f(i, d, list, len_num);
	while (j-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_precision_f(t_printf *list, int *i, int len_num)
{
	int j;

	if (list->floatminus == 1)
	{
		list->count++;
		*i *= -1;
		ft_putchar('-');
	}
}

void	display_f(t_printf *list)
{
	double n;
	int len_num;
	int	len;

	n = va_arg(list->argc, double);
	len = initialze_display_f(list, n, &len_num);
	if (list->space == 1 && list->plus != 1 && list->number >= 0)
		display_space_d(list, &len);
	if (list->zero == 1)
		display_zero_d(list, &len, (intmax_t *)&(list->integer));
	else if (list->width == 1)
		display_width_d(list, len);
	if (list->plus == 1 && list->zero == 0)
		display_plus_d(list,(intmax_t *)&(list->integer));
	if (list->precision == 1)
		display_precision_f(list, &(list->integer), len_num);
	if (list->minus == 1)
		display_minus_f(list, list->integer, list->decimal, len);
	else if (!(list->precision_space <= 0 && n == 0 && list->precision == 1))
		ft_putnbrmax_for_f(list->integer, list->decimal, list, len_num);
}