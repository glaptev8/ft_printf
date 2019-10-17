#include "../includes/ft_printf.h"

void	display_space_u(t_printf *list, int *len)
{
	(*len)++;
	list->count++;
	ft_putchar(' ');
}

void	display_zero_u(t_printf *list, int *len, uintmax_t *n)
{
	int		i;

	i = list->width_space;
	while (i-- > *len)
	{
		if (list->plus == 1)
		{
			list->count++;
			list->plus = 0;
		}
		list->count++;
		ft_putchar('0');
	}
}

void	display_width_u(t_printf *list, int len)
{
	int		i;

	i = list->width_space;
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}

void	display_plus_u(t_printf *list, uintmax_t *n)
{
	list->count++;
}

void	display_precision_u(t_printf *list, uintmax_t *n, int len_num)
{
	int i;

	i = 0;
	while (i++ < list->precision_space - len_num)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_minus_u(t_printf *list, uintmax_t n, int len)
{
	int i;

	i = list->width_space;
//	if (!(list->precision_space <= 0 && list->number_o == 0))
//	{
		if (list->u == 1)
			ft_putnbrmax_o(n, list);
		else
			ft_putnbrmax(n, list);
//	}
	while (i-- > len)
	{
		list->count++;
		ft_putchar(' ');
	}
}