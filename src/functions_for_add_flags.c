#include "../includes/ft_printf.h"

void	add_sharp(t_printf *list)
{
	printf("#\n");
	list->sharp = 1;
}

void	add_minus(t_printf *list)
{
	char	*num;

	printf("-\n");
	list->minus = 1;
	if (ft_isdigit(list->format[list->i + 1]))
	{
		list->i++;
		num = list->format;
		num += list->i;
		list->minus_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
}

void	add_plus(t_printf *list)
{
	printf("+\n");
	list->plus = 1;
}

void	add_space(t_printf *list)
{
	list->space = 1;
	if (list->format[list->i + 1] == ' ')
	{
		while (list->format[list->i] == ' ')
			list->i++;
		list->i--;
	}
}

void	add_precision(t_printf *list)
{
	char *num;

	list->precision = 1;
	if (ft_isdigit(list->format[list->i + 1]))
	{
		list->i++;
		num = list->format;
		num += list->i;
		list->precision_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
}

void	add_width(t_printf *list)
{
	char *num;

	list->width = 1;
	if (ft_isdigit(list->format[list->i + 1]))
	{
		list->i++;
		num = list->format;
		num += list->i;
		list->width_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
}

void	add_zero(t_printf *list)
{
	char *num;

	list->zero = 1;
	if (ft_isdigit(list->format[list->i + 1]))
	{
		list->i++;
		num = list->format;
		num += list->i;
		list->zero_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
}