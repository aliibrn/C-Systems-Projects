/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:07:05 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:07:11 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_time(void)
{
	t_time	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_print(t_dinner *dinner, int id, char *msg)
{
	pthread_mutex_lock(dinner->data->monitor);
	if (!dinner->data->finish)
	{
		pthread_mutex_unlock(dinner->data->monitor);
		pthread_mutex_lock(dinner->data->print);
		printf("%ld %d %s\n", ft_time() - dinner->data->creation_time, id, msg);
		pthread_mutex_unlock(dinner->data->print);
	}
	else
		pthread_mutex_unlock(dinner->data->monitor);
}

void	ft_usleep(long long time_in_ms)
{
	long	start;

	start = ft_time();
	while ((ft_time() - start) < time_in_ms)
		usleep(500);
}

int	check_out(t_dinner *chair)
{
	pthread_mutex_lock(chair->data->monitor);
	if (chair->data->finish)
	{
		pthread_mutex_unlock(chair->data->monitor);
		return (1);
	}
	pthread_mutex_unlock(chair->data->monitor);
	return (0);
}

void	ft_clean(t_dinner *dinner, int *num)
{
	t_dinner	*temp;

	if (dinner)
	{
		if (dinner->data)
			destroy_data(dinner->data);
		while (dinner)
		{
			if (dinner->philo.own)
			{
				pthread_mutex_destroy(&dinner->philo.own->fork);
				free(dinner->philo.own);
			}
			temp = dinner;
			dinner = dinner->next;
			free(temp);
		}
	}
	free(num);
}
