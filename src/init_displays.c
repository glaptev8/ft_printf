#include "../includes/ft_printf.h"

int		initialze_display_d(t_printf *list, intmax_t *n, int *len_num)
{
	int len;

	*n = get_number_for_d(list);
	list->number = *n;
	len = get_number_len(*n, *list);
	*len_num = len;
	if (list->precision == 1 || list->minus == 1)
	{
		if (list->zero == 1)
			list->width = 1;
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ? list->precision_space - len : 0);
	if ((list->number < 0 || list->plus == 1) && (list->precision_space > *len_num - 1))
		len++;
	return (len);
}