/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_op_methods.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 18:27:06 by showard       #+#    #+#                 */
/*   Updated: 2024/11/29 22:48:54 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_0(t_list **a_head, t_list **b_head, t_list *ch)
{
	while (ch->ops.rc > 0)
	{
		rotate_both(a_head, b_head, 1);
		ch->ops.rc -= 1;
	}
	while (ch->ops.ra > 0)
	{
		rotate_list(a_head, 'a');
		ch->ops.ra -= 1;
	}
	while (ch->ops.rb > 0)
	{
		rotate_list(b_head, 'b');
		ch->ops.rb -= 1;
	}
}

void	rev_1(t_list **a_head, t_list **b_head, t_list *ch)
{
	while (ch->ops.rrc > 0)
	{
		rev_rotate_both(a_head, b_head, 1);
		ch->ops.rrc -= 1;
	}
	while (ch->ops.rra > 0)
	{
		rev_rotate_list(a_head, 'a');
		ch->ops.rra -= 1;
	}
	while (ch->ops.rrb > 0)
	{
		rev_rotate_list(b_head, 'b');
		ch->ops.rrb -= 1;
	}
}

void	rev_2(t_list **a_head, t_list **b_head, t_list *ch)
{
	while (ch->cost > 0)
	{
		rotate_list(a_head, 'a');
		ch->cost -= 1;
	}
	while (ch->target->cost_r > 0)
	{
		rev_rotate_list(b_head, 'b');
		ch->target->cost_r -= 1;
	}
}

void	rev_3(t_list **a_head, t_list **b_head, t_list *ch)
{
	while (ch->cost_r > 0)
	{
		rev_rotate_list(a_head, 'a');
		ch->cost_r -= 1;
	}
	while (ch->target->cost > 0)
	{
		rotate_list(b_head, 'b');
		ch->target->cost -= 1;
	}
}
