#include "includes/ft_printf.h"

int		main(void)
{
	ft_printf("%.15*100d_!\n", 1,42);
	printf("%.15*100d_!", 1,42);
//	ft_printf("%0+5d\n", 42);
//	printf("%0+5d", 42);
//	   printf("% d\n", ft_printf("%.d, %.0d", 0, 0));
//	   printf("% d\n", printf("%.d, %.0d", 0, 0));
//	ft_printf("%*d", 5, 12345);
//	printf("%40-30#+d", -42);
//	ft_printf("%lld\n", -LLONG_MAX);
//	   printf("%lld", -LLONG_MAX);
//	printf("% sdfs", "gleb");
	return (0);
}











































// our MakeFiel


//NAME =		libftprintf.a
//LIBFT_A =	libft.a
//
//COMP =		gcc $(PRINTF_H) $(LIBFT_H) -c -o
//
//		PRINTF_H =	-I includes/
//LIBFT_H = 	-I libft/
//
//OBJ_DIR =	obj/
//			 SRC_DIR =	src/
//						  LIB_DIR =	libft/
//
//									   CFILE =		add_accuracy.c  \
//			add_hh_h.c \
//			add_l_ll.c \
//			add_minus.c \
//			add_plus.c \
//			add_sharp.c \
//			add_width.c \
//			add_zero.c \
//			display_c.c \
//			display_d.c \
//			display_i.c \
//			display_s.c \
//			display_p.c \
//			ft_get_number.c \
//			ft_numlen.c \
//			ft_printf.c \
//			ft_putnbrmax.c \
//			ft_write.c \
//			functions.c \
//			operations.c \
//			ft_printf.c \
//			ft_putlstr.c \
//			add_space.c
//
//		CFIND =		$(CFILE:%=$(SRC_DIR)%)
//
//OFILE =		$(CFILE:%.c=%.o)
//
//OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))
//
//all: $(OBJ_DIR) $(NAME)
//
//$(OBJ_DIR):
//@mkdir -p $(OBJ_DIR)
//@echo Create: ft_printf Object directory
//
//$(NAME): $(OBJ)
//@echo LIBFT START
//@make -C $(LIB_DIR)
//@echo Copying $(LIBFT_A) to root.
//@cp $(LIB_DIR)$(LIBFT_A) .
//@mv $(LIBFT_A) $(NAME)
//@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
//@ranlib $(NAME)
//@echo Merged: $(NAME) with $(LIBFT_A)
//@echo FT_PRINTF COMPLETE
//
//$(OBJ): $(CFIND)
//@$(MAKE) $(OFILE)
//
//$(OFILE):
//@echo Create: $(@:obj/%=%)
//@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)
//
//clean:
//@/bin/rm -rf $(OBJ_DIR)
//@make -C $(LIB_DIR) clean
//@echo Cleaned ft_printf object files
//
//		fclean: clean
//@/bin/rm -f $(NAME)
//@make -C $(LIB_DIR) fclean
//@echo Cleaned $(NAME)
//
//re: fclean all
//
//.PHONY: all clean flcean re


