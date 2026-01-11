/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:28 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:48:58 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	index_stack(t_stack **stack, int size)
{
	t_stack	*current;
	t_stack	*cur;
	int		i;

	if (!stack || !(*stack))
		return ;
	current = (*stack);
	while (current)
	{
		i = 0;
		cur = (*stack);
		while (cur)
		{
			if (cur->num > current->num)
				i++;
			cur = cur->next;
		}
		current->index = size - i - 1;
		current = current->next;
	}
}

int	last_index(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp->index);
}

int	get_min(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!stack)
		return (-1);
	i = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}

int	max_index(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!stack)
		return (-1);
	i = stack->index;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > i)
			i = tmp->index;
		tmp = tmp->next;
	}
	return (i);
}
