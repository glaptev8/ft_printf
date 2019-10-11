#include "../includes/ft_printf.h"

int		is_conversion(t_printf list)
{
	char	*str;
	int		i;
	str = ft_strdup("scpdiouxX%");
	i = 0;
	while (str[i] != '\0')
	{
		if (list.format[list.i] == str[i++])
		{
			free(str);
			return (i);
		}
	}
	free(str);
	return (-1);
}

int		is_flag(t_printf list)
{
	char	*flags;
	char	*types;
	int		i;

	if (ft_isdigit(list.format[list.i]))
		return (5);
	flags = ft_strdup("-+# .w0");
	i = 0;
	while (flags[i] != '\0')
	{
		if (list.format[list.i] == flags[i])
			return (i);
		i++;
	}
	return (-1);
}
