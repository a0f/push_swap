/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_validate.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 14:11:09 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 14:17:36 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isdigit_or_sign(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!((str[i] >= '0' && str[i] <= '9')))
	{
		return (-1);
	}
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9')))
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

int	overflow_and_digit_check(char *argv[])
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (isdigit_or_sign(argv[i]) == -1)
			return (-1);
		if (ft_strlen(argv[i]) == 10)
		{
			if (ft_strcmp(argv[i], "2147483647") > 0)
				return (-1);
		}
		else if (ft_strlen(argv[i]) == 11 && argv[i][0] == '-')
		{
			if (ft_strcmp(argv[i], "-2147483648") > 0)
				return (-1);
		}
		else if (ft_strlen(argv[i]) > 10)
			return (-1);
		i++;
	}
	return (0);
}

int	check_sorted(t_list *head)
{
	t_list	*temp;
	int		value;

	temp = head;
	while (temp->next != NULL)
	{
		value = temp->value;
		if (value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_valid(t_list *head)
{
	t_list	*temp;
	t_list	*temp2;
	int		value;
	int		counter;

	temp = head;
	while (temp)
	{
		counter = 0;
		value = temp->value;
		temp2 = head;
		while (temp2)
		{
			if (value == temp2->value)
				counter++;
			if (counter > 1)
				return (-1);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (0);
}
