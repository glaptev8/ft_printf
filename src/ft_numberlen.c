#include "../includes/ft_printf.h"

int		get_number_len(intmax_t n, t_printf list)
{
	int		i;

	i = 0;
	if (n < 0 || list.plus == 1)
		i++;
	n < 0 ? n *= -1 : 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int		get_number_len_for_16(uintmax_t n)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}