/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:05:48 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:05:50 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct timeval	t_time;

typedef struct s_data
{
	int					philo_num;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_of_times_each_philo_must_eat;
	bool				finish;
	int					all_ate;
	long				creation_time;
	pthread_mutex_t		*print;
	pthread_mutex_t		*meal;
	pthread_mutex_t		*monitor;
}						t_data;

typedef struct s_mutex
{
	pthread_mutex_t		fork;
}						t_mutex;

typedef struct s_philo
{
	pthread_t			thread;
	t_mutex				*own;
	t_mutex				*left;
	int					id;
	int					eat;
	long				last_meal;
}						t_philo;

typedef struct s_list
{
	t_data				*data;
	t_philo				philo;
	struct s_list		*next;
	struct s_list		*prev;
}						t_dinner;

// ############### LINKED LIST Functions
void					creat_nodes(t_dinner **head, int ordre, t_data *data);
t_dinner				*return_the_left(t_dinner *philo);
t_dinner				*return_the_right(t_dinner *dinner);
t_dinner				*ft_lstlast(t_dinner *lst);
t_dinner				*ft_lstfirst(t_dinner *lst);
int						ft_lstsize(t_dinner *node);
void					ft_lstadd_front(t_dinner **lst, t_dinner *new);
void					ft_lstadd_back(t_dinner **lst, t_dinner *new);
// ############################### UTILS AND HELPER FUNCTIONS
int						ft_isdigit(int c);
size_t					ft_strlen_arr(char **arr);
long long int			ft_atoi_long(const char *nptr);
void					ft_print(t_dinner *dinner, int id, char *msg);
void					ft_usleep(long long time_in_ms);
long					ft_time(void);
int						check_out(t_dinner *chair);
void					ft_clean(t_dinner *dinner, int *num);
void					destroy_data(t_data *data);
int						ft_time_to_think(t_dinner *chair);
void					ft_putendl_fd(char *s, int fd);
// ############################### PARSE and START philo
int						init(t_dinner **dinner, int *data, int ac);
int						*return_numbers(char **args);
void					print_the_dinner(t_dinner *dinner);
void					lunch_the_dinner(t_dinner *dinner);
void					*the_dinner(void *arg);
void					*ft_monitor(void *arg);

#endif
