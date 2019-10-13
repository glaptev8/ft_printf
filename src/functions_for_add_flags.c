#include "../includes/ft_printf.h"

void	add_sharp(t_printf *list)
{
	list->sharp = 1;
}

void	add_minus(t_printf *list)
{
	char	*num;

	list->minus = 1;
	if (ft_isdigit(list->format[list->i + 1]) || list->format[list->i + 1] == '-' || list->format[list->i + 1] == '+')
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

void	add_plus(t_printf *list)
{
	list->space = 0;
	list->plus = 1;
}

void	add_space(t_printf *list)
{
	if (list->plus != 1)
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
	if (list->format[list->i + 1] == '*')
	{
		list->precision_space = va_arg(list->argc, int);
		list->i++;
	}
	else if (ft_isdigit(list->format[list->i + 1]))
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
//	if (list->zero == 1)
//		return;
	if (list->format[list->i] == '*')
	{
		list->width_space = va_arg(list->argc, int);
		if (list->width_space < 0)
		{
			list->width = 0;
			list->minus = 1;
			list->minus_space = list->width_space * (-1);
		}

	}
	else if (ft_isdigit(list->format[list->i]))
	{
		num = list->format;
		num += list->i;
		list->width_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
//	printf("(%d)", list->width_space);
}

void	add_zero(t_printf *list)
{
	char *num;

	list->zero = 1;
	if (ft_isdigit(list->format[list->i + 1]) || list->format[list->i + 1] == '+')
	{
		list->i++;
		num = list->format;
		num += list->i;
		list->width_space = ft_atoi(num);
		while (ft_isdigit(list->format[list->i]))
			list->i++;
		list->i--;
	}
//	printf("(%d)", list->zero_space);
}