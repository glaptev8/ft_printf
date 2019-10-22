/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l_ftoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:24:51 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/22 12:24:54 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

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

char					*ft_l_ftoa(long double d, int pr)
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