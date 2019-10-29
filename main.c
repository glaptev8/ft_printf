#include "includes/ft_printf.h"
#include <stdio.h>
#include <float.h>

#include <unistd.h>


/*
unsigned short int		ft_byte(unsigned char byte)
{
	unsigned short int	num;
	int					i;

	i = 0;
	num = 0;
	while (i < 8)
	{
		if (byte & (1U << i))
			num |= (1U << i);
		i++;
	}
	return (num);
}

void					print_memory(const void *addr, size_t size)
{
	unsigned char		*tab_short;
	unsigned char   	*tab_char;
	unsigned short int	byte;
	size_t				i;
	size_t				io;

	i = 0;
	tab_short = (unsigned char*)addr;
	tab_char = tab_short;
	while (i < size)
	{
		io = 0;
		byte = ft_byte(*tab_short);
		ft_putnbr_my(byte, 0);
		tab_short++;
		if (i % 2)
			write(1, " ", 1);
		if ((i % 16) == 15)
		{
			while (io < 16)
			{
				if (*tab_char >= 32 && *tab_char < 127)
					write(1, tab_char, 1);
				else
					write(1, ".", 1);
				io++;
				tab_char++;
			}
			write(1, "\n", 1);
		}
		i++;
	}
	i = 0;
	if (size % 16)
	{

		while(i < (40 - ((size % 16) * 2 + (size % 16) / 2 )))
		{
			write(1, " ", 1);
			i++;
		}
		while (io < (size % 16))
		{
			if (*tab_char >= 32 && *tab_char < 127)
				write(1, tab_char, 1);
			else
				write(1, ".", 1);
			io++;
			tab_char++;
		}
		write(1, "\n", 1);
	}
}*/
void	ft_print_float(double f)
{
	unsigned long int	i;
	int				index;

	i = 0;
	index = 63;
	memcpy(&i, &f, sizeof(double));
	while (index >= 0)
	{
		if (i % 8 == 1)
			write(1, ".", 1);
		if (i & (1U << index))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		index--;
	}
	write(1, "\n", 1);
}

void		ft_print_long_double(double *f)
{
	char	*arr;
	int		i;
	int		j;

	i = sizeof(double) - 1;
	arr = (char *)f;
	while (i >= 0)
	{
		j = 7;
		while (j >= 0)
		{
			if (arr[i] & (1U << j))
				write(1, "1", 1);
			else
				write(1 , "0", 1);
			j--;
		}
		write(1, ".", 1);
		i--;
	}
	write(1, "\n", 1);
}

/*
void	ft_print_int(int f)
{
	unsigned int i;
	int index;

	i = 0;
	index = 31;
	memcpy(&i, &f, sizeof(float));
	while (index >= 0)
	{
		if (!((index + 1) % 8))
			write(1, ".", 1);
		if (i & (1U << index))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		index--;
	}
	write(1, "\n", 1);
}
unsigned long	divlu(unsigned long *x, unsigned long *y, unsigned long *z)
{
	int			i;
	unsigned long	t;

	for (i = 1; i <= 64; i++)
	{
		t = *(long int*)x >> 63;

		*x = (*x << 1) | (*y >> 63);
		*y = *y << 1;
		if ((*x | t) >= *z)
		{
			*x = *x - *z;
			*y = *y + 1;
		}
	}
	return (*y);
}*/
/*
char	*ft_nan_inf(long double f)
{

}*/
int			ft_exp_double(double d)
{
	int					index;
	int					exp;
	unsigned long int	*tmp;

	ft_print_long_double(&d);
	tmp = (unsigned long int*)(&d);
	exp = 0;
	*tmp >>= 52;
	index = 10;
	while (index >= 0)
	{
		if (*tmp & 1L << index)
			exp |= 1L << index;
		index--;
	}
	ft_print_long_double(&d);
	return (exp);
}
/*
void		ft_big_number_double(double f)
{
	unsigned long int	num_10[1000] = {0};
	unsigned long int	tmp;
	int					index;
	int					exp;
	int					next;

	index = 63;
	exp = 0;
	next = 1;
	ft_memcpy(&tmp, &f, sizeof(double));
	exp = ft_exp_double(tmp) - 1023 -  52;
	printf("%d bit\n", (exp + 52));
	while (index >= 52)
	{
		if (tmp & 1L << index)
			tmp ^= 1L << index;
		index--;
	}
	tmp |= 1L << 52;
	num_10[0] = tmp;
	index = 0;
	while (num_10[index] != 0)
	{
		num_10[index + 1] = num_10[index] / 1000000000000000000;
		num_10[index] = num_10[index] % 1000000000000000000;
		index++;
	}
	next = index - 1;
	while (exp > 0)
	{
		index = next;
		while (index >= 0)
			num_10[index--] <<= 1;
		index++;
		while (index <= next)
		{
			if (num_10[index] >= 1000000000000000000)
			{
				num_10[index] -= 1000000000000000000;
				num_10[index + 1] += 1;
			}
			index++;
		}
		if (num_10[next] != 0)
			next++;
		exp--;
	}
	ft_putnbr_my(num_10[--next],18,1);
	while (--next >= 0)
		ft_putnbr_my(num_10[next],18,0);
	printf("\n%d  dec number\n", index);
}*/

int			main(void)
{
//	ft_print_long_double(&LDBL_MAX);
//	ft_big_number_long_double(LDBL_MAX);
//	printf("\n%.Lf", LDBL_MAX);
	long double		d;
	char			*str;
	d = LDBL_MAX;
	printf("%Lf\n", d);
	str = ft_max_long_double(d);
	printf("%s\n", str);
	free(str);

//	printf("%d\n", ft_exp_double(d));

	return (0);
}
