/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:52:55 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:52:56 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	three(t_stack **stack)
{
	int	top;
	int	bot;
	int	mid;

	top = (*stack)->num;
	bot = (*stack)->next->next->num;
	mid = (*stack)->next->num;
	if (top > mid && bot > mid && bot > top)
		sa(stack);
	else if (top > mid && mid > bot)
	{
		sa(stack);
		rra(stack);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(stack);
	else if (top < mid && bot < mid && top < bot)
	{
		sa(stack);
		ra(stack);
	}
	else if (top < mid && bot < mid && top > bot)
		rra(stack);
}

void	four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	if ((*stack_a)->num == min)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->num == min)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->num == min)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	three(stack_a);
	pa(stack_a, stack_b);
}

void	push_min(t_stack **stack_a, t_stack **stack_b, int min)
{
	if ((*stack_a)->num == min)
		pb(stack_a, stack_b);
	else if ((*stack_a)->next->num == min)
	{
		sa(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->num == min)
	{
		ra(stack_a);
		ra(stack_a);
		pb(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->num == min)
	{
		rra(stack_a);
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
}

void	five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = find_min(*stack_a);
	push_min(stack_a, stack_b, min);
	four(stack_a, stack_b);
	pa(stack_a, stack_b);
}
