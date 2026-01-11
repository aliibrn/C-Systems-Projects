/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:52:50 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:52:51 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	new_div(t_stack *stack_a, int *div1, int *div2)
{
	*div2 = (ft_lstsize(stack_a) / 6) + (*div1);
	*div1 += (ft_lstsize(stack_a) / 3);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int	div1;
	int	div2;
	int	rem;

	div2 = (ft_lstsize(*stack_a) / 6);
	div1 = (ft_lstsize(*stack_a) / 3);
	rem = -1;
	while (ft_lstsize(*stack_a) > 3)
	{
		if (!still_in(*stack_a, div1))
		{
			rem = div1;
			new_div(*stack_a, &div1, &div2);
		}
		if ((*stack_a)->index < div1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		if (ft_lstsize(*stack_b) > 1 && (*stack_a)->index > div1
			&& (*stack_b)->index > rem && (*stack_b)->index < div2)
			rr(stack_a, stack_b);
		else if (ft_lstsize(*stack_b) > 1 && (*stack_b)->index > rem
			&& (*stack_b)->index < div2)
			rb(stack_b);
	}
}

void	pa_ra(t_stack **stack_a, t_stack **stack_b, int *flag)
{
	pa(stack_a, stack_b);
	ra(stack_a);
	*flag = 1;
}

void	check_and_push(t_stack **stack_a, t_stack **stack_b, int *flag)
{
	while (((*stack_b)->index != (*stack_a)->index - 1))
	{
		if (((*stack_b)->index > (last_index(*stack_a))) || !flag)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
			*flag = 1;
		}
		else
			rrb(stack_b);
	}
	pa(stack_a, stack_b);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	int	flag;

	flag = 0;
	while (ft_lstsize(*stack_b))
	{
		if (is_found(*stack_b, (*stack_a)->index - 1))
		{
			while (((*stack_b)->index != (*stack_a)->index - 1))
			{
				if (((*stack_b)->index > (last_index(*stack_a))) || !flag)
					pa_ra(stack_a, stack_b, &flag);
				else
					rb(stack_b);
			}
			pa(stack_a, stack_b);
		}
		else
			check_and_push(stack_a, stack_b, &flag);
		while (last_index(*stack_a) == (*stack_a)->index - 1)
			rra(stack_a);
		if (max_index(*stack_a) == last_index(*stack_a))
			flag = 0;
	}
}
