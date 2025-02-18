/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_operations_a.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/25 15:45:00 by showard       #+#    #+#                 */
/*   Updated: 2024/11/29 23:55:49 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(t_list **head, int p)
{
	t_list	*node_1;
	t_list	*node_2;

	if (ft_lstsize(*head) > 1)
	{
		node_1 = *head;
		node_2 = (*head)->next;
		node_1->next = node_2->next;
		node_2->next = node_1;
		*head = node_2;
	}
	if (p == 1)
	{
		ft_printf("sa\n");
	}
}

int	push(t_list **dest, t_list **src, char c)
{
	t_list	*temp;

	if (!dest || !src || !(*src))
		return (1);
	temp = *src;
	*src = (*src)->next;
	ft_lstadd_front(dest, temp);
	if (c == 'a')
		ft_printf("pa\n");
	else if (c == 'b')
		ft_printf("pb\n");
	return (0);
}

int	rotate_list(t_list **head, char c)
{
	t_list	*temp_head;
	t_list	*temp_tail;

	if (ft_lstsize(*head) < 2)
		return (-1);
	temp_head = (*head)->next;
	temp_tail = ft_lstlast(*head);
	temp_tail->next = (*head);
	(*head)->next = NULL;
	(*head) = temp_head;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	return (0);
}

int	rev_rotate_list(t_list **head, char c)
{
	t_list	*temp_head;
	t_list	*temp;

	if (ft_lstsize(*head) < 2)
		return (-1);
	temp = *head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp_head = *head;
	*head = ft_lstlast(*head);
	(*head)->next = temp_head;
	temp->next = NULL;
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
	else if (c == 'c')
		ft_printf("rrr\n");
	return (0);
}
