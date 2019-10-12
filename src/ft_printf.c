#include "../includes/ft_printf.h"


int			ft_printf(const char *format, ...)
{
	t_printf	list;
	int			i;
	int			j;

	i = 0;
	va_start(list.argc, format);
	list.i = 0;
	list.format = (char *)format;
	init_struct_functions(&list);
	init_display_functions(&list);
	list.count = 0;
	while (list.format[list.i] != '\0')
	{
		if (list.format[list.i] == '%')
		{
			init_struct(&list);
			if (list.format[list.i + 1] != '\0')
				list.i++;
			while ((is_conversion(list) == -1) && (list.format[list.i] != '\0'))
			{
				if ((j = is_flag(list)) != -1)
				{
					if (list.format[list.i + 1] == 'l' || list.format[list.i + 1] == 'h')
						list.i++;
					list.add_functions[j](&list);
				}
				list.i++;
			}
			if ((j = is_conversion(list)) > -1)
				list.display[j](&list);
		}
		else
		{
			list.count++;
			ft_putchar(list.format[list.i]);
		}
		list.i++;
	}
	return (list.count);
}