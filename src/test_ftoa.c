/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 13:55:23 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/20 13:55:25 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
/*
void reverse(char s[])
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa(unsigned long int n, char s[])
{
	long int i, sign;

	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
//	if (sign < 0)
//		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}*/
static int		count_int(unsigned long int n)
{
	int i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char				*ft_itoa_lu(unsigned long int n)
{
	char				*str;
	int					size;
	unsigned long int	nb;
	int					index;

	size = count_int(n);
	if (!(str = ft_strnew(size + 1)))
		return (NULL);
	nb = n;
	index = size - 1;
	while (nb >= 10)
	{
		str[index--] = nb % 10 + '0';
		nb /= 10;
	}
	str[index] = nb + '0';
	str[size] = '.';
	str[size + 1] = '\0';
	return (str);
}

int						ft_float_exp(float num_f)
{
	int					exp;
	int					index;
	int					tmp_f;

	index = 30;
	exp = 0;
	ft_memcpy(&tmp_f, &num_f, sizeof(float));
	while (index > 22)
	{
		exp <<= 1;
		if (tmp_f & 1U << index)
			exp |= 1U;
		index--;
	}
	exp -=127;
	return (exp);
}
char					*ft_strjoin_re(char *s1, char *s2)
{
	char				*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (tmp);
}

void					ft_rounding(char *arr, int i)
{
	while (arr[i] > '5')
	{
		arr[i] = '0';
		arr[--i]++;
		if (arr[i]  > '9')
		{
			arr[i] = '0';
			arr[i - 1]++;
			i--;
		}
		else
			break;
	}
}

char					*ft_ftoa_div(long double d, int pr)
{
	char				*arr;
	int					i;

	i = 0;
	if (!(arr = ft_strnew(++pr)))
		return (NULL);
	while (i < pr)
	{
		d *= 10.00;
		if ((unsigned long int)d == 0)
			arr[i] = '0';
		else
		{
			arr[i] = (unsigned long int)d + '0';
			d -= (unsigned long int)d;
		}
		i++;
	}
	ft_rounding(arr, --i);
	arr[pr - 1] = '\0';
	return (arr);
}

char					*ft_ftoa(long double d, int pr)
{
	char				*num;
	long unsigned int	mod;
	int					i;

	if (!(num = ft_strnew(0)))
		return (NULL);
	if (d < 0)
	{
		num = ft_strjoin("-", "\0");
		d *= (-1);
	}
	else
		num = ft_strjoin("+", "\0");
	num = ft_strjoin_re(num, ft_itoa_lu((unsigned long int)d));
	num = ft_strjoin_re(num, ft_ftoa_div(d - (unsigned long int)d, pr));
	return (num);
}
/*
void	divlu(unsigned long int *x,unsigned long int *y, unsigned long int z)
{
	int		i;
	unsigned long int	t;

	i = 0;
	while (i < 16)
	{
		t = *(long int*)x >> 63;
		*x = (*x << 1) | (*y >> 63);
		*y = (*y << 1);
		if ((*x | t) >= z)
		{
			*x = *x - z;
			*y = *y + 1;
		}
		i++;
	}
}*/


int		main(void)
{
	float		f;
	double		d;

	f = 0.33;
	d =0.33;
	printf("%.21f-f\n", f);
	printf("%.20lf-d\n", d);
	printf("%s -num", ft_ftoa(d, 21));
	return (0);
}



