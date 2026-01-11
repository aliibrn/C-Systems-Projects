/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:43:37 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:43:39 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_avance(const char *nptr, t_stack **head, int i, int sign)
{
	long long	res;

	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i])
	{
		res = 0;
		sign = 1;
		if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i] == '-')
				sign = -1;
			i++;
		}
		while (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + nptr[i++] - '0';
		res *= sign;
		if (res > 2147483647 || res < -2147483648)
			ft_error(1, "Error\n");
		creat_nodes(head, (int)res);
		while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
			i++;
	}
}

void	ft_atoi_push(char *nptr, t_stack **head)
{
	int	i;
	int	sign;

	sign = 1;
	i = 0;
	if (!nptr)
		ft_error(1, "Error\n");
	if (!ft_check_format1(nptr) || !ft_check_format2(nptr)
		|| !ft_check_format3(nptr))
		ft_error(1, "Error\n");
	ft_atoi_avance(nptr, head, i, sign);
	if (!ft_check_dub(*head))
		ft_error(1, "Error\n");
}
