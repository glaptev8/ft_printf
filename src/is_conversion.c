#include "../includes/ft_printf.h"

int		is_conversion(t_printf list)
{
	char	*str;
	int		i;
	str = ft_strdup("scpdiouxXf%");
	i = 0;
	while (str[i] != '\0')
	{
		if (list.format[list.i] == str[i])
		{
			free(str);
			return (i);
		}
		i++;
	}
	free(str);
	return (-1);
}

int		is_flag(t_printf list)
{
	char	*flags;
	char	*types;
	int		i;

	if (ft_isdigit(list.format[list.i]) && list.format[list.i] != '0')
		return (5);
	flags = ft_strdup("-+# .*0l2h2");
	i = 0;
	while (flags[i] != '\0')
	{
		if (list.format[list.i] == flags[i])
		{
			if (flags[i] == 'l' && list.format[list.i + 1] == 'l')
			{
				return (++i);
			}
			else if (flags[i] == 'h' && list.format[list.i + 1] == 'h')
				return (++i);
			return (i);
		}
		i++;
	}
	return (-1);
}
