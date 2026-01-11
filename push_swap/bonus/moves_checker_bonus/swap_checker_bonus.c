/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:54:36 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:54:37 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap_checker(t_stack **stack)
{
	int	value;

	if ((*stack) == NULL || (*stack)->next == NULL)
		return ;
	value = (*stack)->num;
	(*stack)->num = (*stack)->next->num;
	(*stack)->next->num = value;
}

void	sa_checker(t_stack **stack_a)
{
	swap_checker(stack_a);
}

void	sb_checker(t_stack **stack_b)
{
	swap_checker(stack_b);
}

void	ss_checker(t_stack **stack_a, t_stack **stack_b)
{
	swap_checker(stack_a);
	swap_checker(stack_b);
}
