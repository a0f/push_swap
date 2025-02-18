/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations_b.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 15:45:00 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 13:56:26 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_list **head_a, t_list **head_b, int p)
{
	if (p == 1)
	{
		swap_top(head_a, 0);
		swap_top(head_b, 0);
		ft_printf("ss\n");
	}
	else
	{
		swap_top(head_a, 0);
		swap_top(head_b, 0);
	}
}

void	rotate_both(t_list **head_a, t_list **head_b, int p)
{
	if (p == 1)
	{
		rotate_list(head_a, 0);
		rotate_list(head_b, 0);
		ft_printf("rr\n");
	}
	else
	{
		rotate_list(head_a, 0);
		rotate_list(head_b, 0);
	}
}

void	rev_rotate_both(t_list **head_a, t_list **head_b, int p)
{
	if (p == 1)
	{
		rev_rotate_list(head_a, 0);
		rev_rotate_list(head_b, 0);
		ft_printf("rrr\n");
	}
	else
	{
		rev_rotate_list(head_a, 0);
		rev_rotate_list(head_b, 0);
	}
}
