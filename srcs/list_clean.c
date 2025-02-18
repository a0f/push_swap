/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_clean.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 18:34:02 by showard       #+#    #+#                 */
/*   Updated: 2024/11/25 17:10:31 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clean_list(t_list **stack_a, t_list **stack_b)
{
	t_list	*max_node;

	init_ops(*stack_a, *stack_b);
	ft_set_costs(stack_a);
	ft_set_costs(stack_b);
	max_node = return_max(*stack_b);
	if (max_node->cost < max_node->cost_r)
	{
		while (max_node->cost > 0)
		{
			rotate_list(stack_b, 'b');
			max_node->cost -= 1;
		}
	}
	else
	{
		while (max_node->cost_r > 0)
		{
			rev_rotate_list(stack_b, 'b');
			max_node->cost_r -= 1;
		}
	}
}

void	ft_clean_a(t_list **stack_a)
{
	t_list	*min_node;

	ft_set_costs(stack_a);
	min_node = return_min(*stack_a);
	if (min_node->cost < min_node->cost_r)
	{
		while (min_node->cost > 0)
		{
			rotate_list(stack_a, 'a');
			min_node->cost -= 1;
		}
	}
	else
	{
		while (min_node->cost_r > 0)
		{
			rev_rotate_list(stack_a, 'a');
			min_node->cost_r -= 1;
		}
	}
}
