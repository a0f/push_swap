NAME := libftprintf.a
LIBFT := ./libft/libft.a
SRCS := ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
        ft_printf.c ft_printf_char.c ft_printf_int.c ft_printf_str.c \
        ft_printf_ptr.c ft_printf_perc.c ft_printf_lowerhex.c\
        ft_printf_upperhex.c ft_printf_uint.c \

OBJS := ft_printf.o ft_printf_char.o ft_printf_int.o ft_printf_str.o\
        ft_printf_ptr.o ft_printf_perc.o ft_printf_lowerhex.o\
        ft_printf_upperhex.o  ft_printf_uint.o \


CFLAGS := -Wall -Wextra -Werror -I./libft -I.

TFLAGS := main.c libftprintf.a -I./libft -I.

CC = cc

all : $(NAME)

$(LIBFT): 
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $@ $^

test : main.c $(NAME)
	$(CC) $(TFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY:	clean fclean all bonus test