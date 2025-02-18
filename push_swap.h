/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: showard <showard@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 18:59:56 by showard       #+#    #+#                 */
/*   Updated: 2024/11/30 13:55:33 by showard       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>

typedef struct t_ops
{
	int				b_min;
	int				b_max;
	int				ra;
	int				rb;
	int				rc;
	int				rra;
	int				rrb;
	int				rrc;
	int				tcr;
	int				tcrr;
	int				tind1;
	int				tind2;
	int				rev_flag;
}					t_ops;

typedef struct s_list
{
	int				value;
	int				sort_value;
	int				cost;
	int				cost_r;
	struct s_list	*next;
	struct s_list	*target;
	t_ops			ops;
}					t_list;

int					ft_atoi(const char *nptr);
t_list				*ft_lstnew(int number);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				swap_top(t_list **head, int p);
void				swap_both(t_list **head_a, t_list **head_b, int p);
int					push(t_list **dest, t_list **src, char c);
int					rotate_list(t_list **head, char c);
void				rotate_both(t_list **head_a, t_list **head_b, int p);
void				rev_rotate_both(t_list **head_a, t_list **head_b, int p);
int					rev_rotate_list(t_list **head, char c);
int					rot_count_min(t_list *lst, int value);
int					rot_count_max(t_list *lst, int value);
int					seek_max(t_list *lst);
int					seek_min(t_list *lst);
int					ft_printf(const char *format, ...);
int					check_sorted(t_list *head);
int					check_valid(t_list *head);
t_list				*return_max(t_list *lst);
t_list				*return_min(t_list *lst);
t_list				*ft_init_stacka(char **argv);
void				ft_assign_target(t_list **b_head, int max, int min,
						t_list *a_node);
t_list				*ft_find_node(t_list **head, int value);
t_list				*ft_find_between(t_list **head, int value);
void				init_ops(t_list *stack_a, t_list *stack_b);
int					overflow_and_digit_check(char *argv[]);
void				rev_0(t_list **a_head, t_list **b_head, t_list *ch);
void				rev_1(t_list **a_head, t_list **b_head, t_list *ch);
void				rev_2(t_list **a_head, t_list **b_head, t_list *ch);
void				rev_3(t_list **a_head, t_list **b_head, t_list *ch);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
void				ft_set_costs(t_list **head);
void				ft_assign_targets(t_list **b_head, int max, int min,
						t_list **a_head);
void				update_ops(t_list *a_head);
void				set_ops(t_list *a_head);
void				update_cheapest(t_list *temp, int *cheapest_cost,
						t_list **cheapest);
t_list				*find_cheapest(t_list *a_head);
void				excecute_cheapest(t_list **a_head, t_list **b_head);
void				ft_clean_a(t_list **stack_a);
void				ft_clean_list(t_list **stack_a, t_list **stack_b);
void				sort_3(t_list **stack_a);
void				ft_lstclear(t_list **lst);
#endif