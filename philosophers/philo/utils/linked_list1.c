/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:21:34 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:21:36 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_dinner	*return_the_left(t_dinner *dinner)
{
	if (dinner->next)
		return (dinner->next);
	else
		return (ft_lstfirst(dinner));
	return (NULL);
}

void	ft_lstadd_front(t_dinner **lst, t_dinner *new)
{
	if (!new)
		return ;
	new->next = *lst;
	if (*lst)
		(*lst)->prev = new;
	*lst = new;
}

void	ft_lstadd_back(t_dinner **lst, t_dinner *new)
{
	t_dinner	*add;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		add = ft_lstlast(*lst);
		add->next = new;
		new->prev = add;
		new->next = NULL;
	}
}
