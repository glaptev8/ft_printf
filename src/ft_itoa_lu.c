/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:16:56 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/22 12:16:59 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
