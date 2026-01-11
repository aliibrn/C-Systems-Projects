/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_checker_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:54:32 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:54:32 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate_checker(t_stack **stack)
{
	t_stack	*last;

	last = ft_lstlast(*stack);
	last->next = (*stack);
	(*stack) = (*stack)->next;
	last->next->next = NULL;
}

void	ra_checker(t_stack **stack_a)
{
	if (ft_lstsize(*stack_a) < 2)
		return ;
	rotate_checker(stack_a);
}

void	rb_checker(t_stack **stack_b)
{
	if (ft_lstsize(*stack_b) < 2)
		return ;
	rotate_checker(stack_b);
}

void	rr_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
		return ;
	rotate_checker(stack_a);
	rotate_checker(stack_b);
}
