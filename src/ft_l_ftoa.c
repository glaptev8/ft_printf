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

#include "../includes/ft_printf.h"

char					*ft_l_ftoa_div(long double d, int pr)
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
	num = ft_strjoin_re(num, ft_l_ftoa_div(d - (unsigned long int)d, pr));
	return (num);
}