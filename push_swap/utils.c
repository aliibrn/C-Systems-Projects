/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:51:25 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:51:27 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int fd, char *str)
{
	ft_putstr_fd(str, 2);
	exit(fd);
}

void	ft_free(t_stack *stack_a)
{
	t_stack	*temp;

	while (stack_a->next != NULL)
	{
		temp = stack_a;
		stack_a = stack_a->next;
		free(temp);
	}
	free(stack_a);
}

void	print_node(t_stack *head)
{
	if (!head)
		ft_printf("null\n");
	while (head)
	{
		ft_printf("[%d] <-> DATA : %d \n", head->index, head->num);
		head = head->next;
	}
}

int	ft_sorted(t_stack *head)
{
	t_stack	*current;

	current = head;
	while (current && current->next)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!stack)
		return (-1);
	i = stack->num;
	tmp = stack;
	while (tmp)
	{
		if (tmp->num < i)
			i = tmp->num;
		tmp = tmp->next;
	}
	return (i);
}
