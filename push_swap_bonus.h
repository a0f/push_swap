/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_bonus.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/29 20:49:56 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 13:58:23 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stddef.h>

typedef struct s_ins
{
	char			*ins;
	struct s_ins	*next;
}					t_ins;

t_ins	*ft_lstnew_i(char *str);
void	ft_lstadd_back_i(t_ins **lst, t_ins *new);
void	ft_lstclear_i(t_ins **lst);
t_ins	*ft_lstlast_i(t_ins *lst);
t_ins	*create_ins_list(t_ins *head);
#endif