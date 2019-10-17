#include "../includes/ft_printf.h"

void	display_space_o(t_printf *list, int *len)
{
	(*len)++;
	list->count++;
	ft_putchar(' ');
}

void	display_zero_o(t_printf *list, int *len)
{
	int		i;

	if ((list->is_0x == 1 || list->is_o == 1) && list->sharp == 1)
	{
		display_sharp_o(list, len);
		list->sharp = 0;
	}
	i = list->width_space;
	while (i-- > *len)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_width_o(t_printf *list, int len)
{
	int		i;

	i = list->width_space;
	if (list->sharp == 1 && list->is_o && list->number_o == 0)
		len--;
	else if (list->sharp == 1 && list->is_0x && list->number_o == 0)
		len -= 2;
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_sharp_o(t_printf *list, int *len)
{
	if (list->is_o)
	{
		if (list->number_o == 0)
			(*len)--;
		list->count++;
		ft_putchar('0');
	}
	else if (list->is_0x && list->number_o != 0)
	{
		if (list->number_o == 0)
			*len -= 2;
		list->count += 2;
		list->X == 1 ? ft_putstr("0X") : ft_putstr("0x");
	}
}

void	display_precision_o(t_printf *list, int len_num)
{
	int i;

	i = 0;
	while (i++ < list->precision_space - len_num)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_minus_o(t_printf *list, int len)
{
	int i;

	i = list->width_space;
	if (!(list->sharp == 1 && list->number_o == 0))
		ft_putnbrmax_o(list->number_o, list);
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}