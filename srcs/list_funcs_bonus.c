/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_funcs_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/29 21:19:26 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 17:36:54 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"
#include <stdlib.h>

t_ins	*ft_lstnew_i(char *str)
{
	t_ins	*node;

	node = malloc(sizeof(t_ins));
	if (node == NULL)
	{
		return (NULL);
	}
	node->ins = str;
	node->next = NULL;
	return (node);
}

void	ft_lstclear_i(t_ins **lst)
{
	t_ins	*temp;
	t_ins	*last_node;

	temp = *lst;
	while (temp)
	{
		free(temp->ins);
		last_node = temp;
		temp = temp->next;
		free(last_node);
	}
	*lst = NULL;
}

void	ft_lstadd_back_i(t_ins **lst, t_ins *new)
{
	t_ins	*temp;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		temp = *lst;
		temp = ft_lstlast_i(*lst);
		temp->next = new;
	}
}

t_ins	*ft_lstlast_i(t_ins *lst)
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

t_ins	*create_ins_list(t_ins *head)
{
	char	*r_str;
	t_ins	*new_node;

	while (1)
	{
		r_str = get_next_line(0);
		if (r_str == NULL)
			break ;
		if (head == NULL)
			head = ft_lstnew_i(r_str);
		else
		{
			new_node = ft_lstnew_i(r_str);
			ft_lstadd_back_i(&head, new_node);
		}
	}
	return (head);
}
