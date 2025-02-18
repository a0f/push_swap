/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_funcs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 20:41:05 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 13:55:55 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if ((unsigned char)*s1 != (unsigned char)*s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = (*nptr - '0') + (value * 10);
		nptr++;
	}
	return (value * sign);
}

t_list	*ft_init_stacka(char **argv)
{
	t_list	*head;
	t_list	*new_node;
	int		i;

	i = 1;
	head = ft_lstnew(ft_atoi(argv[i]));
	if (head == NULL)
		return (NULL);
	i++;
	while (argv[i] != NULL)
	{
		new_node = ft_lstnew(ft_atoi(argv[i]));
		if (new_node == NULL)
		{
			ft_lstclear(&head);
			return (NULL);
		}
		ft_lstadd_back(&head, new_node);
		i++;
	}
	return (head);
}

void	init_ops(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;

	temp = stack_a;
	while (temp != NULL)
	{
		temp->ops.b_min = seek_min(stack_b);
		temp->ops.b_max = seek_max(stack_b);
		temp->ops.ra = 0;
		temp->ops.rb = 0;
		temp->ops.rc = 0;
		temp->ops.rra = 0;
		temp->ops.rrb = 0;
		temp->ops.rrc = 0;
		temp->ops.tcr = 0;
		temp->ops.tcrr = 0;
		temp->ops.tind1 = 0;
		temp->ops.tind2 = 0;
		temp->ops.rev_flag = 0;
		temp = temp->next;
	}
}
