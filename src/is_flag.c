#include "../includes/ft_printf.h"

int		is_flag(t_printf list)
{
	char	*str;
	int		i;

	str = ft_strdup("scpdiouxX%");
	while (str[i] != '\0')
	{
		if (list.format[list.i] == str[i++])
		{
			free(str);
			return (1);
		}
	}
	free(str);
	return (-1);
}