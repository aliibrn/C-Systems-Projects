/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:53:34 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:53:35 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pop(t_stack **stack)
{
	t_stack	*curr;

	curr = (*stack)->next;
	free(*stack);
	(*stack) = curr;
}

void	push(t_stack **stack, int value, int index)
{
	t_stack	*node;

	node = ft_lstnew(value);
	if (!node)
		return ;
	node->num = value;
	node->index = index;
	node->next = (*stack);
	(*stack) = node;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, (*stack_b)->num, (*stack_b)->index);
	pop(stack_b);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, (*stack_a)->num, (*stack_a)->index);
	pop(stack_a);
	ft_putstr_fd("pb\n", 1);
}
