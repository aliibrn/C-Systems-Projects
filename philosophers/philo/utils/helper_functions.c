/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:06:42 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:06:43 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_strlen_arr(char **arr)
{
	size_t	len;

	len = 0;
	while (arr[len] != NULL)
	{
		len++;
	}
	return (len);
}

long long int	ft_atoi_long(const char *nptr)
{
	long long int	res;
	long long int	sign;
	int				i;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (res > (INT_MAX - (nptr[i] - '0')) / 10)
			return (ft_putendl_fd("MAX INT ERROR", 2), -2);
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * res);
}

int	ft_time_to_think(t_dinner *chair)
{
	return (chair->data->time_to_eat);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
