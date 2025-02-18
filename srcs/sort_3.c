/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 18:35:30 by showard       #+#    #+#                 */
/*   Updated: 2024/11/29 16:41:23 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*stack_a)->value;
	n2 = (*stack_a)->next->value;
	n3 = (*stack_a)->next->next->value;
	if (n1 > n2 && n1 < n3 && n2 < n3)
		swap_top(stack_a, 1);
	else if (n1 > n2 && n1 > n3 && n2 > n3)
		swap_top(stack_a, 1);
	else if (n1 < n2 && n1 < n3 && n2 > n3)
		swap_top(stack_a, 1);
}
