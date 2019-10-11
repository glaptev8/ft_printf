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
	void		(*add_functions[10])(struct s_printf *);
	void		(*display[10])(struct s_printf *);
	short		zero;
	int			zero_space;
	short		sharp;
	int			count;
	int			minus;
	int			width;
	int 		width_space;
	int			plus;
	int			space;
	int 		precision;
	int			precision_space;
	int 		minus_space;
	int 		l;
	int 		ll;
	int 		h;
	int 		hh;
	int			i;
}				t_printf;

int			ft_printf(const char *format, ...);
int			is_conversion(t_printf list);
int			is_flag(t_printf list);
void		add_flags(t_printf list);
void		add_width(t_printf *list);
void		add_precision(t_printf *list);
void		add_space(t_printf *list);
void		add_plus(t_printf *list);
void		add_minus(t_printf *list);
void		add_sharp(t_printf *list);
void		init_struct_functions(t_printf *l);
void		init_struct(t_printf *l);
void		display_u(t_printf *list);
void		display_s(t_printf *list);
void		display_p(t_printf *list);
void		display_o(t_printf *list);
void		display_i(t_printf *list);
void		display_d(t_printf *list);
void		display_c(t_printf *list);
void		init_display_functions(t_printf *l);
void		add_zero(t_printf *list);
#endif