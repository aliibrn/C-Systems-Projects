/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:54:22 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:54:23 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pop_checker(t_stack **stack)
{
	t_stack	*curr;

	curr = (*stack)->next;
	free(*stack);
	(*stack) = curr;
}

void	push_checker(t_stack **stack, int value)
{
	t_stack	*node;

	node = ft_lstnew(value);
	if (!node)
		return ;
	node->num = value;
	node->next = (*stack);
	(*stack) = node;
}

void	pa_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return ;
	push_checker(stack_a, (*stack_b)->num);
	pop_checker(stack_b);
}

void	pb_checker(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return ;
	push_checker(stack_b, (*stack_a)->num);
	pop_checker(stack_a);
}
