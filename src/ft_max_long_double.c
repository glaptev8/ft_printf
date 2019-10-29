/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_long_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:53:54 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/29 21:53:57 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
void				ft_putnbr_my(unsigned long int num, int i, int first, int index_str, char *number)
{
	if (first == 1)
	{
		if (num < 10)
		{
			number[index_str] = num + '0';
			return;
		}
	}
	else if (i < 1)
		return;
	ft_putnbr_my(num / 10, i - 1, first, index_str - 1, number);
	number[index_str] = num % 10 + '0';
//	write(1, &"0123456789abcdef"[num % 10], 1);
}

int			ft_exp_long_double(long double tmp)
{
	short int		*exp;

	exp = (short int*)(&tmp);
	if (exp[4] < 0)
		exp[4] *= -1;
	return (exp[4]);
}

char		*ft_str_long_double(unsigned long int *num_10, int next)
{
	char	*str;
	char	*tmp;
	int		index;

	if (!(str = ft_strnew(next * 18)))
		return (NULL);
	if (!(tmp = ft_itoa_lu(num_10[next], 10, 'n')))
		return (NULL);
	str = ft_strjoin(str, tmp);
	free(tmp);
	index = ft_strlen(str) + 17;
	while (--next >= 0)
	{
		ft_putnbr_my(num_10[next],18,0, index, str);
		index += 18;
	}
	return (str);
}

int			ft_main_div(unsigned long int *num_10, int exp, int next)
{
	int		index;

	index = 0;
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
	return (--next);
}

int			ft_first_div(unsigned long int *num_10, long double f)
{
	unsigned long int		*tmp;
	int						index;

	tmp = (unsigned long int*)(&f);
	num_10[0] = *tmp;
	index = 0;
	while (num_10[index] != 0)
	{
		num_10[index + 1] = num_10[index] / 1000000000000000000;
		num_10[index] = num_10[index] % 1000000000000000000;
		index++;
	}
	return (--index);
}

char		*ft_max_long_double(long double f)
{
	unsigned long int	num_10[276];
	int					exp;
	int					next;

	ft_memset(num_10, 0, 276 * sizeof(unsigned long int));
	exp = ft_exp_long_double(f) - 16383 - 63;
	next = ft_first_div(num_10, f);
	next = ft_main_div(num_10, exp, next);
	return (ft_str_long_double(num_10, next));
}
