/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 02:46:22 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:42:59 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dub(t_stack *head)
{
	t_stack	*current;
	t_stack	*cur;

	current = head;
	while (current)
	{
		cur = current->next;
		while (cur)
		{
			if (current->num == cur->num)
				return (0);
			cur = cur->next;
		}
		current = current->next;
	}
	return (1);
}

int	ft_check_format1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] == '-' || str[i + 1] == '+')
				return (0);
			if (!ft_isdigit(str[i + 1]))
				return (0);
		}
		if (ft_isdigit(str[i]) && (str[i + 1] == '-' || str[i + 1] == '+'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_format2(char *str)
{
	int	y;

	y = 0;
	while (str[y])
	{
		if ((ft_strchr(" 0123456789+-", str[y]) == NULL))
		{
			return (0);
		}
		y++;
	}
	return (1);
}

int	ft_check_format3(char *str)
{
	int	y;

	y = 0;
	while (str[y] == ' ' || str[y] == '\t')
		y++;
	if (str[y] == '\0')
		return (0);
	else
		return (1);
}
