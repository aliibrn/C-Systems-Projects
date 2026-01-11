/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:06:35 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:06:36 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_number(char **args)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (args[i])
	{
		y = 0;
		if (args[i][y] && args[i][y] == '+')
			y++;
		while (args[i][y])
		{
			if (!ft_isdigit(args[i][y]))
				return (0);
			y++;
		}
		i++;
	}
	return (1);
}

int	*return_numbers(char **args)
{
	int	*num;
	int	len;
	int	i;
	int	y;

	num = NULL;
	i = 1;
	y = 0;
	len = ft_strlen_arr(args);
	if (check_number(args))
	{
		num = (int *)malloc(sizeof(int) * (len));
		while (i < len)
		{
			num[y] = ft_atoi_long(args[i]);
			y++;
			i++;
		}
		return (num);
	}
	return (NULL);
}
