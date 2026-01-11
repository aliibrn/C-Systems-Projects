/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_the_dinner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:06:24 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:06:26 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	down_the_forks(t_mutex *right, t_mutex *left)
{
	pthread_mutex_unlock(&right->fork);
	pthread_mutex_unlock(&left->fork);
}

void	eat(t_dinner *chair, t_mutex *fork1, t_mutex *fork2)
{
	pthread_mutex_lock(&fork1->fork);
	ft_print(chair, chair->philo.id, "has taken a fork");
	pthread_mutex_lock(&fork2->fork);
	ft_print(chair, chair->philo.id, "has taken a fork");
	ft_print(chair, chair->philo.id, "is eating");
	pthread_mutex_lock(chair->data->meal);
	chair->philo.last_meal = ft_time();
	chair->philo.eat++;
	if (chair->data->num_of_times_each_philo_must_eat != -1
		&& chair->philo.eat == chair->data->num_of_times_each_philo_must_eat)
		chair->data->all_ate++;
	pthread_mutex_unlock(chair->data->meal);
	ft_usleep(chair->data->time_to_eat);
	down_the_forks(fork1, fork2);
}

void	sleep_and_think(t_dinner *chair)
{
	ft_print(chair, chair->philo.id, "is sleeping");
	ft_usleep(chair->data->time_to_sleep);
	ft_print(chair, chair->philo.id, "is thinking");
	if (chair->data->philo_num % 2 != 0)
		ft_usleep(ft_time_to_think(chair));
}

void	one_philo(t_dinner *chair)
{
	pthread_mutex_lock(&chair->philo.own->fork);
	ft_print(chair, chair->philo.id, "has taken a fork");
	ft_usleep(chair->data->time_to_die);
	ft_print(chair, chair->philo.id, "died");
	pthread_mutex_unlock(&chair->philo.own->fork);
}

void	*the_dinner(void *arg)
{
	t_dinner	*chair;

	chair = (t_dinner *)arg;
	if (chair->philo.id % 2 == 0)
		usleep(10);
	while (1)
	{
		if (check_out(chair))
			break ;
		if (chair->data->philo_num == 1)
		{
			one_philo(chair);
			break ;
		}
		if (chair->philo.id % 2 == 0)
			eat(chair, chair->philo.own, chair->philo.left);
		else
			eat(chair, chair->philo.left, chair->philo.own);
		sleep_and_think(chair);
	}
	return (NULL);
}
