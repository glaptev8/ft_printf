/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmelia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:24:58 by tmelia            #+#    #+#             */
/*   Updated: 2019/10/21 12:30:38 by tmelia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_add_flags(t_printf *list, int *flag)
{
	int j;

	init_struct(list);
	if (list->format[list->i + 1] != '\0')
		list->i++;
	else
		return (0);
	while ((is_conversion(*list) == -1) && (list->format[list->i] != '\0'))
	{
		if ((j = is_flag(*list)) != -1)
		{
			if (list->format[list->i + 1] == 'l' ||
			list->format[list->i + 1] == 'h')
				list->i++;
			list->add_functions[j](list);
		}
		else if (ft_isalpha(list->format[list->i]))
			break ;
		list->i++;
	}
	if ((j = is_conversion(*list)) > -1 && *flag == 0)
		list->display[j](list);
	else
		*flag = 1;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	t_printf	list;
	int			j;
	int			flag;

	flag = 0;
	va_start(list.argc, format);
	list.i = 0;
	list.format = (char *)format;
	init_struct_functions(&list);
	init_display_functions(&list);
	list.count = 0;
	while (list.format[list.i] != '\0')
	{
		if (list.format[list.i] == '%')
			ft_add_flags(&list, &flag);
		else
		{
			list.count++;
			ft_putchar(list.format[list.i]);
		}
		list.i++;
	}
	return (list.count);
}
