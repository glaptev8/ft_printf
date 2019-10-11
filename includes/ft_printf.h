#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "../libft/libft.h"
# include <stdarg.h>
#include  <stdlib.h>
#include <limits.h>

typedef struct 	s_printf
{
	va_list		argc;
	char		*format;
	short		zero;
	short		sharp;
	int			count;
	int			minus;
	int 		minus_space;
	int			i;
}				t_printf;

int			ft_printf(const char *format, ...);
int		is_flag(t_printf list);

#endif