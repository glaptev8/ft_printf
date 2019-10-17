#include "../includes/ft_printf.h"

uintmax_t		converter(uintmax_t n, int base)
{
	uintmax_t nb;

	nb = 0;
	if (n >= base)
		nb += converter(n / base, base);
	nb = nb * 10 + n % base;
	return (nb);
}

char			*converter_16(uintmax_t n, t_printf *list)
{
	char	*sym;
	char	*sym2;
	int		i;
	char	*str;
	int 	len;

	i = 0;

	sym = ft_strdup("0123456789abcdef");
	sym2 = ft_strdup("0123456789ABCDEF");
	if (n == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
	}
	else
	{
		len = get_number_len_for_16(n);
		str = ft_strnew(len);
		while (n != 0)
		{
			str[--len] = list->X == 1 ? sym2[n % 16] : sym[n % 16];
			n /= 16;
		}
	}
	free(sym);
	free(sym2);
	return (str);
}