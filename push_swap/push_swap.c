/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 10:16:12 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/24 10:24:07 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	if (size == 3)
		three(stack_a);
	if (size == 4)
		four(stack_a, stack_b);
	if (size == 5)
		five(stack_a, stack_b);
	if (size > 5)
	{
		index_stack(stack_a, size);
		push_b(stack_a, stack_b);
		three(stack_a);
		push_a(stack_a, stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		c;
	int		w;

	if (ac > 1)
	{
		stack_a = NULL;
		stack_b = NULL;
		c = ac;
		w = 1;
		while (w < c)
		{
			ft_atoi_push(av[w], &stack_a);
			w++;
		}
		if (!ft_sorted(stack_a))
		{
			sort(&stack_a, &stack_b);
		}
		ft_free(stack_a);
	}
}
