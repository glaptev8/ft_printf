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
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
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

void	display_sharp_o(t_printf *list)
{
	if (list->is_o == 1)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_minus_o(t_printf *list, uintmax_t n, int len)
{
	int i;

	i = list->width_space;
	if (!(list->precision_space <= 0 && n == 0))
			ft_putnbrmax_o(n, list);
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}