/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_index2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:22 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:48:23 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_found(t_stack *stack, int x)
{
	t_stack	*tmp;
	int		len;

	len = ft_lstsize(stack) / 2;
	tmp = stack;
	while (len)
	{
		if (tmp->index == x)
			return (1);
		len--;
		tmp = tmp->next;
	}
	return (0);
}

int	still_in(t_stack *stack_a, int div1)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->index < div1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
