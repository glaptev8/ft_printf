/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ftoa_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjosue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:03:12 by cjosue            #+#    #+#             */
/*   Updated: 2019/10/22 19:03:14 by cjosue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

void	ft_print_float(float f)
{
	unsigned int	i;
	int				index;

	i = 0;
	index = 31;
	memcpy(&i, &f, sizeof(float));
	while (index >= 0)
	{
		if (index == 30 || index == 22)
			write(1, ".", 1);
		if (i & (1U << index))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		index--;
	}
	write(1, "\n", 1);
}

void	ft_print_int(int f)
{
	unsigned int	i;
	int				index;

	i = 0;
	index = 31;
	memcpy(&i, &f, sizeof(float));
	while (index >= 0)
	{
		if (!((index + 1)  % 8))
			write(1, ".", 1);
		if (i & (1U << index))
			write(1, "1", 1);
		else
			write(1, "0", 1);
		index--;
	}
	write(1, "\n", 1);
}

int		main(void)
{
	float	f;
	double	d;

	f = 0.87650894255;
	d = -1.0000;
	printf("%.4f\n", 0.33);
//	printf("%.0lf\n", d);
/*
	ft_print_float((float)d);
	f = (float)d;
	ft_print_float(f);
	unsigned int			num;
	ft_memcpy(&num, &f, 4);
	ft_print_int(num);
	ft_print_int(1L << 31);
	if (num & 1L << 31)
		printf("yes\n");*/
	printf("%s\n", ft_l_ftoa(0.33, ));
//	printf("%s\n", ft_l_ftoa(d, 0));
	return (0);
}
