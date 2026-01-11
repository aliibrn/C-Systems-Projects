/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:54:12 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 13:22:38 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sorted_checker(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current;

	current = stack_a;
	if (stack_a != NULL && stack_b == NULL)
	{
		while (current && current->next)
		{
			if (current->num > current->next->num)
				return (0);
			current = current->next;
		}
		return (1);
	}
	else
		return (0);
}

int	moves_on_checker(t_stack **stack_a, t_stack **stack_b, char *move)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		sa_checker(stack_a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb_checker(stack_b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss_checker(stack_a, stack_b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		pa_checker(stack_a, stack_b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb_checker(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra_checker(stack_a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb_checker(stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr_checker(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", 4) == 0)
		rra_checker(stack_a);
	else if (ft_strncmp(move, "rrb\n", 4) == 0)
		rrb_checker(stack_b);
	else if (ft_strncmp(move, "rrr\n", 4) == 0)
		rrr_checker(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	check_line(t_stack **stack_a, t_stack **stack_b)
{
	char	*line;
	int		error;

	line = get_next_line(0);
	while (line)
	{
		error = moves_on_checker(stack_a, stack_b, line);
		if (!error)
			ft_error(1, "Error\n");
		free(line);
		line = get_next_line(0);
	}
}

void	check_and_free(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_sorted_checker(stack_a, stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_error(1, "KO\n");
	ft_free(stack_a);
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
		check_line(&stack_a, &stack_b);
		check_and_free(stack_a, stack_b);
	}
}
