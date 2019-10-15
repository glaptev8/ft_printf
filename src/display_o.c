#include "../includes/ft_printf.h"

uintmax_t	get_number_for_o(t_printf *list)
{
	uintmax_t n;

	if (list->l == 1)
		n = va_arg(list->argc, unsigned long int);
	else if (list->ll == 1)
		n = va_arg(list->argc, unsigned long long int);
	else if (list->h == 1)
		n = (unsigned short)va_arg(list->argc,unsigned int);
	else if (list->hh == 1)
		n = (unsigned char)va_arg(list->argc,unsigned int);
	else
		n = (unsigned int)va_arg(list->argc, unsigned int);
	n = (uintmax_t)n;
	return (n);
}


void	display_o(t_printf *list)
{
	uintmax_t n;
	int		len;
	int		i;
	int		len_num;

	len = initialze_display_o(list, &n, &len_num);
	if (list->space == 1 && list->number_o >= 0)
		display_space_o(list, &len);
	if (list->zero == 1)
		display_zero_o(list, &len);
	else if (list->width == 1)
		display_width_o(list, len);
	if (list->precision == 1)
		display_precision_o(list, len_num);
	if (list->sharp == 1)
		display_sharp_o(list, len);
	if (list->minus == 1)
		display_minus_o(list, len);
	else if (!(list->precision_space <= 0 && n == 0 && list->precision == 1))
		ft_putnbrmax_o(n, list);
}