/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_funcs_b.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:51:48 by showard       #+#    #+#                 */
/*   Updated: 2024/11/25 17:12:11 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}

t_list	*ft_find_node(t_list **head, int value)
{
	t_list	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->value == value)
		{
			return (temp);
		}
		temp = temp->next;
	}
	return (NULL);
}

t_list	*ft_find_between(t_list **head, int value)
{
	t_list	*temp;

	temp = *head;
	while (temp->next != NULL)
	{
		if (temp->value > value && temp->next->value < value)
		{
			return (temp->next);
		}
		temp = temp->next;
	}
	if (temp->value > value && (*head)->value < value)
	{
		return (*head);
	}
	return (NULL);
}
