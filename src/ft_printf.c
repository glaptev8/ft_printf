#include "../includes/ft_printf.h"


int			ft_printf(const char *format, ...)
{
	t_printf	list;
	int 		i;

	i = 0;
	va_start(list.argc, format);
	list.i = 0;
	list.format = (char *)format;
	while (list.format[list.i] != '\0')
	{
		if (list.format[list.i] == '%')
		{
			if (list.format[list.i + 1] != '\0')
				i++;
			while ((is_flag(list) != 1) && (list.format[list.i] != '\0'))
			{

			}
		}
		list.i++;
	}
	return (list.count);
}