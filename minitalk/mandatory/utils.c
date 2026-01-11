/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:04:20 by abbouram          #+#    #+#             */
/*   Updated: 2024/04/06 02:04:21 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

int	check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]) == NULL)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **av)
{
	int	pid;

	if (check_format(av[1]))
	{
		pid = ft_atoi(av[1]);
		return (pid);
	}
	return (0);
}

int	check_process(int pid)
{
	int	check;

	check = kill(pid, 0);
	return (check);
}
