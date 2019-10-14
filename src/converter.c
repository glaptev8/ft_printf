#include "../includes/ft_printf.h"

int		converter(uintmax_t n, int base)
{
	uintmax_t nb;

	nb = 0;
	if (n >= base)
		nb += converter(n / base, base);
	nb = nb * 10 + n % base;
	return (nb);
}