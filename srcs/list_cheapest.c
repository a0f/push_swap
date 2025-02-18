/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_cheapest.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 18:32:32 by showard       #+#    #+#                 */
/*   Updated: 2024/11/25 17:10:21 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	update_cheapest(t_list *temp, int *cheapest_cost, t_list **cheapest)
{
	if (*cheapest_cost > temp->ops.tcr)
	{
		*cheapest_cost = temp->ops.tcr;
		*cheapest = temp;
		temp->ops.rev_flag = 0;
	}
	if (*cheapest_cost > temp->ops.tcrr)
	{
		*cheapest_cost = temp->ops.tcrr;
		*cheapest = temp;
		temp->ops.rev_flag = 1;
	}
	if (*cheapest_cost > temp->ops.tind1)
	{
		*cheapest_cost = temp->ops.tind1;
		*cheapest = temp;
		temp->ops.rev_flag = 2;
	}
	if (*cheapest_cost > temp->ops.tind2)
	{
		*cheapest_cost = temp->ops.tind2;
		*cheapest = temp;
		temp->ops.rev_flag = 3;
	}
}

t_list	*find_cheapest(t_list *a_head)
{
	t_list	*cheapest;
	t_list	*temp;
	int		cheapest_cost;

	cheapest = NULL;
	temp = a_head;
	cheapest_cost = INT_MAX;
	while (temp != NULL)
	{
		update_cheapest(temp, &cheapest_cost, &cheapest);
		temp = temp->next;
	}
	return (cheapest);
}

void	excecute_cheapest(t_list **a_head, t_list **b_head)
{
	t_list	*ch;

	ch = find_cheapest(*a_head);
	if (ch->ops.rev_flag == 0)
		rev_0(a_head, b_head, ch);
	if (ch->ops.rev_flag == 1)
		rev_1(a_head, b_head, ch);
	if (ch->ops.rev_flag == 2)
		rev_2(a_head, b_head, ch);
	if (ch->ops.rev_flag == 3)
		rev_3(a_head, b_head, ch);
	push(b_head, a_head, 'b');
}
