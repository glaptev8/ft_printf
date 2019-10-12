#include "../includes/ft_printf.h"

void	init_struct(t_printf *l)
{
	l->minus = 0;
	l->plus = 0;
	l->sharp = 0;
	l->space = 0;
	l->precision = 0;
	l->width = 0;
	l->zero = 0;
	l->number = 0;
	l->zero_space = 0;
	l->minus_space = 0;
	l->width_space = 0;
	l->precision_space = -1;
	l->l = 0;
	l->ll = 0;
	l->h = 0;
	l->hh = 0;
}

void	init_struct_functions(t_printf *l)
{
	l->add_functions[0] = &add_minus;
	l->add_functions[1] = &add_plus;
	l->add_functions[2] = &add_sharp;
	l->add_functions[3] = &add_space;
	l->add_functions[4] = &add_precision;
	l->add_functions[5] = &add_width;
	l->add_functions[6] = &add_zero;
	l->add_functions[7] = &add_l;
	l->add_functions[8] = &add_ll;
	l->add_functions[9] = &add_h;
	l->add_functions[10] = &add_hh;
}

void	init_display_functions(t_printf *l)
{
	l->display[0] = &display_s;
	l->display[1] = &display_c;
	l->display[2] = &display_p;
	l->display[3] = &display_d;
	l->display[4] = &display_i;
	l->display[5] = &display_o;
	l->display[6] = &display_u;
	l->display[7] = &display_x;
	l->display[8] = &display_X;
	l->display[9] = &display_f;
	l->display[10] = &display_procent;
}