/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_displays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:36:22 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 13:35:38 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if ((list->number < 0 || list->plus == 1) &&
			(list->precision_space > *len_num - 1))
		len++;
	if ((list->precision != 1 && list->number == 0))
		len++;
	return (len);
}

int		initialze_display_f(t_printf *list, double n, int *len_num)
{
	int p;
	int len;
	int d_len;

	if (list->precision == 0)
		list->precision = 1;
	if (list->precision_space < 0)
		list->precision_space = 6;
	if (n < 0 && n > -1)
		list->floatminus = 1;
	p = ft_pow(10, list->precision_space);
	list->integer = (int)(n * p);
	list->number = list->integer / 10;
	d_len = list->integer % p;
	d_len *= d_len > 0 ? 1 : -1;
	if (list->precision_space < get_number_len(d_len, *list))
		list->decimal = d_len % 10 >= 5 ? d_len / 10 + 1 : d_len / 10;
	else
		list->decimal = d_len / 10;
	list->decimal *= list->decimal < 0 ? -1 : 1;
	list->integer /= p;
	len = get_number_len(list->integer, *list) +
		get_number_len_for_uint(list->decimal);
	d_len = ft_pow(10, (get_number_len((uintmax_t)list->decimal, *list) -
				list->precision_space) - 1);
	len++;
	*len_num = len;
	if (list->minus == 1)
	{
		if (list->zero == 1)
			list->width = 1;
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ? list->precision_space - len : 0);
	if ((list->number < 0 || list->plus == 1) &&
			(list->precision_space > *len_num - 1))
		len++;
	return (len);
}

int		initialze_display_u(t_printf *list, uintmax_t *n, int *len_num)
{
	int len;

	*n = get_number_for_o(list);
	list->space = 0;
	list->plus = 0;
	list->u = 1;
	list->number_o = *n;
	len = get_number_len_for_uint(*n);
	*len_num = (*n == 0 && list->precision_space > 0) ? 1 : len;
	if (list->precision == 1 || list->minus == 1)
	{
		if (list->zero == 1)
			list->width = 1;
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ?
			list->precision_space - len : 0);
	if ((list->number < 0 || list->plus == 1) &&
			(list->precision_space > *len_num - 1))
		len++;
	if ((list->precision != 1 && list->number_o == 0))
		len++;
	return (len);
}

int		initialze_display_o(t_printf *list, uintmax_t *n, int *len_num)
{
	int len;

	*n = get_number_for_o(list);
	list->is_o = 1;
	*n = converter(*n, 8);
	list->number_o = *n;
	len = get_number_len_for_uint(*n);
	*len_num = len;
	if (*n == 0)
		*len_num = 1;
	if (list->precision == 1 || list->minus == 1)
	{
		if (list->zero == 1)
			list->width = 1;
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ? list->precision_space - len : 0);
	if (list->sharp == 1)
	{
		if (list->is_o == 1)
			len++;
		else if (list->is_0x == 1)
			len += 2;
	}
	if ((list->precision != 1 && list->number_o == 0))
		len++;
	return (len);
}

int		initialze_display_x(t_printf *list, char *n, int *len_num)
{
	int len;

	list->is_0x = 1;
	list->number_o = get_number_for_o(list);
	n = converter_16(list->number_o, list);
	len = get_number_len_for_16(list->number_o);
	*len_num = len;
	if (n[0] == '0' && len == 0)
	{
		if (!(list->precision == 1 && list->precision_space <= 0))
		{
			len = 1;
			*len_num = 1;
		}
	}
	if (list->precision == 1 || list->minus == 1)
	{
		if (list->zero == 1)
			list->width = 1;
		list->zero = 0;
	}
	if (list->minus == 1)
		list->width = 0;
	len += (list->precision_space > len ? list->precision_space - len : 0);
	if (list->sharp == 1)
	{
		if (list->is_o == 1)
			len++;
		else if (list->is_0x == 1)
			len += 2;
	}
	return (len);
}
