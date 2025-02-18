/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/29 19:26:08 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 17:40:10 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include <unistd.h>

void	find_and_run_op(t_list **stack_a, t_list **stack_b, t_ins *node,
		int *flag)
{
	if ((ft_strcmp("sa\n", node->ins) == 0))
		swap_top(stack_a, 0);
	else if ((ft_strcmp("sb\n", node->ins) == 0))
		swap_top(stack_b, 0);
	else if ((ft_strcmp("ss\n", node->ins) == 0))
		swap_both(stack_a, stack_b, 0);
	else if ((ft_strcmp("pa\n", node->ins) == 0))
		push(stack_a, stack_b, 0);
	else if ((ft_strcmp("pb\n", node->ins) == 0))
		push(stack_b, stack_a, 0);
	else if ((ft_strcmp("ra\n", node->ins) == 0))
		rotate_list(stack_a, 0);
	else if ((ft_strcmp("rb\n", node->ins) == 0))
		rotate_list(stack_b, 0);
	else if ((ft_strcmp("rr\n", node->ins) == 0))
		rotate_both(stack_a, stack_b, 0);
	else if ((ft_strcmp("rra\n", node->ins) == 0))
		rev_rotate_list(stack_a, 0);
	else if ((ft_strcmp("rrb\n", node->ins) == 0))
		rev_rotate_list(stack_b, 0);
	else if ((ft_strcmp("rrr\n", node->ins) == 0))
		rev_rotate_both(stack_a, stack_b, 0);
	else
		*flag = -1;
}

void	run_ops(t_list **stack_a, t_list **stack_b, t_ins *inst, int *flag)
{
	t_ins	*temp;

	temp = inst;
	while (temp != NULL)
	{
		find_and_run_op(stack_a, stack_b, temp, flag);
		if (*flag == -1)
			return ;
		temp = temp->next;
	}
}

void	print_result(int flag, t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_b) != 0)
	{
		ft_printf("KO\n");
		ft_lstclear(stack_a);
		ft_lstclear(stack_b);
		return ;
	}
	if (flag == -1)
	{
		write(2, "Error\n", 6);
		ft_lstclear(stack_a);
		return ;
	}
	if (check_sorted(*stack_a) == 1)
	{
		ft_printf("OK\n");
		ft_lstclear(stack_a);
		return ;
	}
	ft_printf("KO\n");
	ft_lstclear(stack_a);
	return ;
}

void	push_swap_bonus(char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_ins	*inst;
	int		flag;

	if (overflow_and_digit_check(argv) == -1)
	{
		write(2, "Error\n", 6);
		return ;
	}
	stack_a = ft_init_stacka(argv);
	stack_b = NULL;
	inst = NULL;
	if (check_valid(stack_a) == -1)
	{
		write(2, "Error\n", 6);
		ft_lstclear(&stack_a);
		return ;
	}
	inst = create_ins_list(inst);
	flag = 0;
	run_ops(&stack_a, &stack_b, inst, &flag);
	print_result(flag, &stack_a, &stack_b);
	ft_lstclear_i(&inst);
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		push_swap_bonus(argv);
	}
	else
	{
		return (-1);
	}
	return (0);
}
