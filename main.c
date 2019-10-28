#include "includes/ft_printf.h"
#include <stdio.h>
#include <float.h>

#include <unistd.h>
/*
void					ft_putnbr_my(unsigned short int num, int i)
{
	if (i > 1)
	{
		return;
	}
	ft_putnbr_my(num / 16, i + 1);
	write(1, &"0123456789abcdef"[num % 16], 1);
}

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
//	ft_memcpy(arr, &f, sizeof(long double));
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
int			ft_exp_double(unsigned long int tmp)
{
	int		index;
	int		exp;

	exp = 0;
	tmp >>= 52;
	index = 10;
	while (index >= 0)
	{
		if (tmp & 1L << index)
			exp |= 1L << index;
		index--;
	}
	return (exp);
}

void		ft_big_number(double f)
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
		num_10[index + 1] = num_10[index] / 10;
		num_10[index] = num_10[index] % 10;
		index++;
	}
	next = index - 1;
//	while (index >= 0)
//		printf("%lu   ", num_10[index--]);
//	printf("\n");
	while (exp > 0)
	{
		index = next;
		while (index >= 0)
			num_10[index--] <<= 1;
		index++;
		while (index <= next)
		{
			if (num_10[index] >= 10)
			{
				num_10[index] -= 10;
				num_10[index + 1] += 1;
			}
			index++;
		}
		if (num_10[next] != 0)
			next++;
		exp--;
	}
	while (--next >= 0)
		printf("%lu", num_10[next]);
	printf("\n%d  dec number\n", index);
}

int			main(void)
{
//    printf("%.10Lf\n", 0.87650894255l);
//    ft_printf("%.10Lf\n", 0.87650894255l);
	double *f;
	unsigned int *num;

	num = (unsigned int*)f;
	num[0] = 0xffffffff;
	num[1] = 0x7FEFFFFF;
//	unsigned char	num[10] = {0};

//	num[3]  = 127;
//	num[2] = 128;
//	num[1] = 1;
//	ft_memcpy(&f, num, 4);
//	char *s ="123456789";

	ft_print_long_double(f);
	ft_big_number(*f);
	printf("%309.lf!\n", *f);

	//	printf("%-41llf!\n", f);
//	ft_print_float(f);
//	ft_printf("%.-5s!\n", s);
//
//	printf("%.128f\n", FLT_MIN);
//	ft_printf("%.128f\n", FLT_MIN);

////	long unsigned	num;
//	unsigned long		num1[2];
//
////	num = 0xffffff000000000;
////	ft_memcpy(num1,&num, 8);
//	unsigned char	*s;
//	s = (unsigned char *)num1;
//	num1[1] = 0;
//	num1[0] = 0;
////	s[7] = 255;
////	s[6] = 255;
////	s[5] = 255;
////	s[4] = 255;
////	s[3] = 255;
//	s[1] = 255;
//	s[0] = 255;
////	s[2] = 255;
////	s[9] = 255;
////	s[8] = 255;
//	unsigned long z;
//	z = 100;
////	unsigned long z[1];
////	s = (unsigned char *)z;
////	z[0] = 0;
////	s[7] = 0x0d;
////	s[6] = 0xe0;
////	s[5] = 0xb6;
////	s[4] = 0xb3;
////	s[3] = 0xa7;
////	s[2] = 0x64;
////	print_memory(z, sizeof(z));
//	print_memory(num1, sizeof(num1));
//	divlu(num1 + 1, num1, &z);
//
//
//	printf("%lu  cel   %lu   ost \n", num1[0], num1[1]);
//
//	print_memory(num1, sizeof(num1));
////	num[0] *=
////	ft_print_float(0.87650894255);
//	//	long unsigned int	i;
//	long unsigned int	a;
//	char				*c;
//	char				b;
//
//	b = 100;
//	c = &b;
//	printf("{%*d}\n", -5, 42);
//	ft_printf("{%*d}\n", -5, 42);
//	a = 100;
//	i = (long unsigned int)c;
//	ft_printf("%\n", "test");
//	printf("%.30p__i\n", i);
//	printf("% /n", "test");
	//	ft_printf("%c", '}');
//	ft_printf("%0+5d\n", 42);
//	printf("%0+5d", 42);
//	   printf("% d\n", ft_printf("%.d, %.0d", 0, 0));
//	   printf("% d\n", printf("%.d, %.0d", 0, 0));
//	ft_printf("%*d", 5, 12345);
//	printf("%40-30#+d", -42);
//	ft_printf("%lld\n", -LLONG_MAX);
//	   printf("%lld", -LLONG_MAX);
//	printf("% sdfs", "gleb");
	return (0);
}
