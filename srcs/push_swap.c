/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:58:54 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 15:13:49 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

void	pushback(t_list **stack_a, t_list **stack_b)
{
	int	s3[3];

	s3[0] = (*stack_a)->value;
	s3[1] = (*stack_a)->next->value;
	if ((*stack_a)->next->next != NULL)
		s3[2] = (*stack_a)->next->next->value;
	while (*stack_b != NULL)
	{
		if ((*stack_b)->value < s3[2])
		{
			rev_rotate_list(stack_a, 'a');
			s3[2] = INT_MIN;
		}
		if ((*stack_b)->value < s3[1])
		{
			rev_rotate_list(stack_a, 'a');
			s3[1] = INT_MIN;
		}
		if ((*stack_b)->value < s3[0])
		{
			rev_rotate_list(stack_a, 'a');
			s3[0] = INT_MIN;
		}
		push(stack_a, stack_b, 'a');
	}
}

void	sort_low(t_list **stack_a)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		ft_clean_a(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
	{
		sort_3(stack_a);
		ft_clean_a(stack_a);
	}
}

t_list	*sort_stack(t_list *stack_a, t_list *stack_b)
{
	if (ft_lstsize(stack_a) == 2)
		ft_clean_a(&stack_a);
	else if (ft_lstsize(stack_a) == 3)
		sort_3(&stack_a);
	else
	{
		push(&stack_b, &stack_a, 'b');
		push(&stack_b, &stack_a, 'b');
		while (ft_lstsize(stack_a) > 3)
		{
			init_ops(stack_a, stack_b);
			ft_set_costs(&stack_a);
			ft_set_costs(&stack_b);
			ft_assign_targets(&stack_b, stack_a->ops.b_max, stack_a->ops.b_min,
				&stack_a);
			set_ops(stack_a);
			excecute_cheapest(&stack_a, &stack_b);
		}
		ft_clean_list(&stack_a, &stack_b);
		sort_low(&stack_a);
		pushback(&stack_a, &stack_b);
	}
	ft_clean_a(&stack_a);
	return (stack_a);
}

int	push_swap(char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argv[1][0] == '\0')
	{
		return (-1);
	}
	if (overflow_and_digit_check(argv) == -1)
		return (-1);
	stack_a = ft_init_stacka(argv);
	stack_b = NULL;
	if (check_valid(stack_a) == -1)
	{
		ft_lstclear(&stack_a);
		return (-1);
	}
	if (check_sorted(stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	stack_a = sort_stack(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	errorcheck;

	if (argc > 1)
	{
		errorcheck = push_swap(argv);
		if (errorcheck != 0)
		{
			write(2, "Error\n", 6);
			return (errorcheck);
		}
	}
	else
	{
		return (-1);
	}
	return (0);
}
