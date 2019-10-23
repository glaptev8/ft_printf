/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays_for_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:22:23 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:22:24 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	display_zero_o(t_printf *list, int *len)
{
	int		i;

	i = list->width_space;
//	if (list->sharp == 1)
//		display_sharp_o(list, len);
	while (i-- > *len)
	{
		list->count++;
		ft_putchar('0');
	}
}

void	display_width_o(t_printf *list, int len)
{
	int		i;

	if (list->sharp == 1 && list->is_o)
		len--;
	i = list->width_space;
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
		list->count++;
		(*len)--;
		ft_putchar('0');
	}
	else if (list->is_0x)
	{
		if (list->number_o == 0)
			*len -= 2;
		else
		{
			list->count += 2;
			list->X == 1 ? ft_putstr("0X") : ft_putstr("0x");
		}
	}
	list->sharp = 0;
}

void	display_precision_o(t_printf *list, int len_num)
{
	int i;

	i = 0;
	while (len_num < list->precision_space - i++)
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
