/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_assignments.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 18:30:59 by showard       #+#    #+#                 */
/*   Updated: 2024/11/25 17:09:55 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_costs(t_list **head)
{
	int		counter;
	int		lstsize;
	t_list	*temp;

	counter = 0;
	lstsize = ft_lstsize(*head);
	temp = *head;
	while (temp != NULL)
	{
		temp->cost = counter;
		if (temp->cost == 0)
			temp->cost_r = 0;
		else
			temp->cost_r = lstsize - counter;
		temp = temp->next;
		counter++;
	}
}

void	ft_assign_targets(t_list **b_head, int max, int min, t_list **a_head)
{
	t_list	*temp;

	temp = *a_head;
	while (temp != NULL)
	{
		if (temp->value > max || temp->value < min)
		{
			temp->target = ft_find_node(b_head, max);
		}
		else
		{
			temp->target = ft_find_between(b_head, temp->value);
		}
		temp = temp->next;
	}
}

void	update_ops(t_list *a_head)
{
	t_list	*temp;

	temp = a_head;
	while (temp->ops.ra > 0 && temp->ops.rb > 0)
	{
		temp->ops.ra -= 1;
		temp->ops.rb -= 1;
		temp->ops.rc += 1;
	}
	while (temp->ops.rra > 0 && temp->ops.rrb > 0)
	{
		temp->ops.rra -= 1;
		temp->ops.rrb -= 1;
		temp->ops.rrc += 1;
	}
}

void	set_ops(t_list *a_head)
{
	t_list	*temp;

	temp = a_head;
	while (temp != NULL)
	{
		temp->ops.ra = temp->cost;
		temp->ops.rb = temp->target->cost;
		temp->ops.rra = temp->cost_r;
		temp->ops.rrb = temp->target->cost_r;
		temp->ops.tind1 = temp->cost + temp->target->cost_r;
		temp->ops.tind2 = temp->cost_r + temp->target->cost;
		update_ops(temp);
		temp->ops.tcr = temp->ops.ra + temp->ops.rb + temp->ops.rc;
		temp->ops.tcrr = temp->ops.rra + temp->ops.rrb + temp->ops.rrc;
		temp = temp->next;
	}
}
