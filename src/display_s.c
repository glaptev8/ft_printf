#include "../includes/ft_printf.h"

void	display_s(t_printf *list)
{
	char	*str;
	size_t	len;

	str = va_arg(list->argc, char*);
	len = ft_strlen(str);
	if (list->minus == 1)
	{
		ft_putstr(str);
//		printf("%zu _ len\n", len);
//		printf("%d _ width\n", list->width_space);
		while (list->width_space-- > len)
			ft_putchar(' ');
	}
	else if (list->zero == 1)
	{
		while (list->width_space-- > len)
			ft_putchar('0');
		ft_putstr(str);
	}
	else
	{
		while (list->width_space-- > len)
			ft_putchar(' ');
		ft_putstr(str);
	}
}