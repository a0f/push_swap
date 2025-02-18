/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_funcs_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:37:46 by showard       #+#    #+#                 */
/*   Updated: 2024/11/29 21:19:12 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "push_swap_bonus.h"
#include <stdlib.h>

t_list	*ft_lstnew(int number)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
	{
		return (NULL);
	}
	node->value = number;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
	{
		return (NULL);
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*last_node;

	temp = *lst;
	while (temp)
	{
		last_node = temp;
		temp = temp->next;
		free(last_node);
	}
	*lst = NULL;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
