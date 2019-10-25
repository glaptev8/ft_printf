/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:20:43 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/19 16:22:22 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*ft_strjoin_re(char *s1, char *s2)
{
	char				*tmp;

	tmp = ft_strjoin(s1, s2);
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (tmp);
}

int					ft_rounding(char *div, int i)
{
	if (div[i] >= '5')
	{
		div[--i] += 1;
		if (div[i] > '9')
		{
			while (div[i] > '9' && i > 0)
			{
				div[i] = '0';
				div[--i] += 1;
			}
			if (i == 0 && div[0] > '9')
			{
				div[i] = '0';
				return (1);
			}
		}
	}
	return (0);
}

int						ft_ftoa_div(double d, int pr, char *arr)
{
	int					i;

	i = 0;
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
	if (ft_rounding(arr, --i) == 1)
	{
		arr[pr - 1] = '\0';
		return (1);
	}
	arr[pr - 1] = '\0';
	return (0);
}

double					ft_sign(char *num, double d)
{
	long unsigned int	tmp;

	ft_memcpy(&tmp, &d, sizeof(double));
	if (tmp & 1L << 63)
	{
		num[0] = '-';
		return (-1.00);
	}
	else
		num[0] = '+';
	return (1.00);
}

char					*ft_ftoa(double d, int pr)
{
	char				*num;
	long unsigned int	mod;
	int					i;
	char				*div;

	if (!(num = ft_strnew(1)))
		return (NULL);
	d *= ft_sign(num, d);
	mod = (unsigned long int)d;
	if (pr <= 0)
	{
		if ((unsigned long int)((d - (double)mod) * 1e1) >= 5)
			return (ft_strjoin_re(num, ft_itoa_lu(++mod, 10, 'f')));
	}
	if (!(div = ft_strnew(++pr)))
		return (num);
	if (ft_ftoa_div(d - (unsigned long int)d, pr, div) == 1)
		mod++;
	num = ft_strjoin_re(num, ft_itoa_lu(mod, 10, 'f'));
	return (ft_strjoin_re(num, div));
}