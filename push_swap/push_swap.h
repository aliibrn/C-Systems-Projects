/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:51:53 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:51:54 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>

typedef struct a_list
{
	int				num;
	int				index;
	struct a_list	*next;
}					t_stack;

////////////////////////////////// PARSING
int					ft_check_dub(t_stack *head);
int					ft_check_format2(char *str);
int					ft_check_format1(char *str);
int					ft_check_format3(char *str);
void				ft_atoi_push(char *nptr, t_stack **head);
/////////////////////////////////////// utils
int					ft_sorted(t_stack *head);
int					find_min(t_stack *stack);
void				ft_error(int fd, char *str);
void				ft_free(t_stack *stack_a);
void				print_node(t_stack *head);
///////////////////////////////// linked_list - moves - indexing and sorting ->
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *lst);
void				creat_nodes(t_stack **head, int nbr);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
void				ft_lstadd_reverse(t_stack **lst, t_stack *new);
//////////////////////////// moves
void				push(t_stack **stack, int value, int index);
void				swap(t_stack **stack);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);
void				pop(t_stack **stack);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
/////////////////////////////////////////////// index utils
int					last_index(t_stack *stack_a);
int					max_index(t_stack *stack);
int					get_min(t_stack *stack);
int					is_found(t_stack *stack, int x);
int					still_in(t_stack *stack_a, int div1);
void				index_stack(t_stack **stack, int size);
////////////////////////////// sorting
void				sort(t_stack **stack_a, t_stack **stack_b);
void				three(t_stack **stack);
void				four(t_stack **stack_a, t_stack **stack_b);
void				five(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				push_a(t_stack **stack_a, t_stack **stack_b);
////////////////////////////////////////////////////////// bonus
void				pa_checker(t_stack **stack_a, t_stack **stack_b);
void				pb_checker(t_stack **stack_a, t_stack **stack_b);
void				rra_checker(t_stack **stack_a);
void				rrb_checker(t_stack **stack_b);
void				rrr_checker(t_stack **stack_a, t_stack **stack_b);
void				ra_checker(t_stack **stack_a);
void				rb_checker(t_stack **stack_b);
void				rr_checker(t_stack **stack_a, t_stack **stack_b);
void				sa_checker(t_stack **stack_a);
void				sb_checker(t_stack **stack_b);
void				ss_checker(t_stack **stack_a, t_stack **stack_b);

#endif
