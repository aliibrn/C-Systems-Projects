/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_checker_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:54:28 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:54:28 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstadd_reverse(t_stack **lst, t_stack *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	reverse_rotate_checker(t_stack **stack)
{
	t_stack	*last;
	t_stack	*head;

	last = *stack;
	last = ft_lstlast(last);
	head = *stack;
	while (head->next != NULL)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	ft_lstadd_reverse(stack, last);
}

void	rra_checker(t_stack **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	reverse_rotate_checker(stack_a);
}

void	rrb_checker(t_stack **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return ;
	reverse_rotate_checker(stack_b);
}

void	rrr_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b))
		return ;
	reverse_rotate_checker(stack_a);
	reverse_rotate_checker(stack_b);
}
