#include "../includes/ft_printf.h"


int			ft_printf(const char *format, ...)
{
	t_printf	list;
	int			i;
	int			j;
	int 		flag;

	flag = 0;
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
			else
				break;
			while ((is_conversion(list) == -1) && (list.format[list.i] != '\0'))
			{
				if ((j = is_flag(list)) != -1)
					list.add_functions[j](&list);
				else if (ft_isalpha(list.format[list.i]))
					break;
				list.i++;
			}
			if ((j = is_conversion(list)) > -1 && flag == 0)
				list.display[j](&list);
			else
				flag = 1;
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