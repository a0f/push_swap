/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_funcs_check.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:46:49 by showard       #+#    #+#                 */
/*   Updated: 2024/11/25 17:12:22 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	seek_max(t_list *lst)
{
	int	max_value;

	max_value = lst->value;
	if (!lst)
	{
		return (-2);
	}
	while (lst)
	{
		if (lst->value > max_value)
		{
			max_value = lst->value;
		}
		lst = lst->next;
	}
	return (max_value);
}

int	seek_min(t_list *lst)
{
	int	min_value;

	min_value = lst->value;
	if (!lst)
	{
		return (-2);
	}
	while (lst)
	{
		if (lst->value < min_value)
		{
			min_value = lst->value;
		}
		lst = lst->next;
	}
	return (min_value);
}

t_list	*return_max(t_list *lst)
{
	int		max_value;
	t_list	*max_node;

	max_value = lst->value;
	max_node = lst;
	while (lst)
	{
		if (lst->value > max_value)
		{
			max_value = lst->value;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

t_list	*return_min(t_list *lst)
{
	int		min_value;
	t_list	*min_node;

	min_value = lst->value;
	min_node = lst;
	while (lst)
	{
		if (lst->value < min_value)
		{
			min_value = lst->value;
			min_node = lst;
		}
		lst = lst->next;
	}
	return (min_node);
}
