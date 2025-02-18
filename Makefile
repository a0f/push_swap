NAME := push_swap
BONUS := checker
PRINTF := ./printf/libftprintf.a

SRCS := srcs/init_funcs.c srcs/list_assignments.c srcs/list_cheapest.c \
		srcs/list_clean.c srcs/list_funcs_a.c srcs/list_funcs_b.c srcs/list_funcs_check.c \
		srcs/list_op_methods.c srcs/list_operations_a.c srcs/list_operations_b.c srcs/list_validate.c srcs/push_swap.c \
		srcs/sort_3.c

SRCS_B := srcs/init_funcs.c srcs/list_assignments.c srcs/list_cheapest.c srcs/list_funcs_bonus.c\
		  srcs/list_clean.c srcs/list_funcs_a.c srcs/list_funcs_b.c srcs/list_funcs_check.c \
		  srcs/list_op_methods.c srcs/list_operations_a.c srcs/list_operations_b.c \
		  srcs/list_validate.c srcs/push_swap_bonus.c srcs/sort_3.c srcs/get_next_line.c srcs/get_next_line_utils.c

OBJS := objs/init_funcs.o objs/list_assignments.o objs/list_cheapest.o \
		objs/list_clean.o objs/list_funcs_a.o objs/list_funcs_b.o objs/list_funcs_check.o \
		objs/list_op_methods.o objs/list_operations_a.o objs/list_operations_b.o objs/list_validate.o objs/push_swap.o \
		objs/sort_3.o

OBJS_B := objs/init_funcs.o objs/list_assignments.o objs/list_cheapest.o srcs/list_funcs_bonus.o\
		  objs/list_clean.o objs/list_funcs_a.o objs/list_funcs_b.o objs/list_funcs_check.o \
		  objs/list_op_methods.o objs/list_operations_a.o objs/list_operations_b.o \
		  objs/list_validate.o objs/push_swap_bonus.o objs/sort_3.o objs/get_next_line.o objs/get_next_line_utils.o

CFLAGS := -Wall -Wextra -Werror -I./printf -I. -g

CC = cc

all: $(NAME)

bonus: $(BONUS)

$(PRINTF): 
	$(MAKE) -C printf

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PRINTF)

$(BONUS): $(PRINTF) $(OBJS_B)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJS_B) $(PRINTF)

objs/%.o: srcs/%.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

objs/%.o: %.c
	@mkdir -p objs
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_B)
	@if [ -d "objs" ]; then rmdir objs; fi
	$(MAKE) -C printf clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	$(MAKE) -C printf fclean

re: fclean all

.PHONY: clean fclean all re bonus
