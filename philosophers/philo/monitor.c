/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:06:09 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:06:10 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isdie(t_dinner *chair)
{
	pthread_mutex_lock(chair->data->meal);
	if (ft_time() - chair->philo.last_meal > chair->data->time_to_die)
	{
		pthread_mutex_unlock(chair->data->meal);
		return (1);
	}
	pthread_mutex_unlock(chair->data->meal);
	return (0);
}

int	is_all_eat(t_dinner *chair)
{
	pthread_mutex_lock(chair->data->meal);
	if (chair->data->all_ate == chair->data->philo_num)
	{
		pthread_mutex_unlock(chair->data->meal);
		return (1);
	}
	pthread_mutex_unlock(chair->data->meal);
	return (0);
}

void	finish(t_dinner *chair)
{
	pthread_mutex_lock(chair->data->monitor);
	chair->data->finish = true;
	pthread_mutex_unlock(chair->data->monitor);
}

void	*ft_monitor(void *arg)
{
	t_dinner	*chair;

	chair = (t_dinner *)arg;
	if (chair->data->philo_num != 1)
	{
		while (1)
		{
			if (isdie(chair))
			{
				finish(chair);
				printf("%ld %d %s\n", ft_time() - chair->data->creation_time,
					chair->philo.id, "died");
				return (NULL);
			}
			else if (is_all_eat(chair))
			{
				finish(chair);
				return (NULL);
			}
			chair = return_the_left(chair);
		}
	}
	return (NULL);
}
