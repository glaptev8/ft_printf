#include "../includes/ft_printf.h"

void	display_u(t_printf *list)
{
	uintmax_t n;
	int		len;
	int		i;
	int		len_num;

	len = initialze_display_u(list, &n, &len_num);
	if (list->space == 1 && list->plus != 1 && list->number >= 0)
		display_space_d(list, &len);
	if (list->zero == 1)
		display_zero_d(list, &len, &n);
	else if (list->width == 1)
		display_width_d(list, len);
	if (list->plus == 1 && list->zero == 0)
		display_plus_d(list, &n);
	if (list->precision == 1)
		display_precision_d(list, &n, len_num);
	if (list->minus == 1)
		display_minus_d(list, n, len);
	else if (!(list->precision_space <= 0 && n == 0 && list->precision == 1))
		ft_putnbrmax(n, list);
}