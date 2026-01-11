/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:06:57 by abbouram          #+#    #+#             */
/*   Updated: 2024/07/25 17:06:58 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_dinner	*ft_lstnew(int ordre, t_data *data)
{
	t_dinner	*newnode;

	newnode = malloc(sizeof(t_dinner));
	if (!newnode)
		return (NULL);
	newnode->data = data;
	newnode->philo.id = ordre;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

t_dinner	*ft_lstfirst(t_dinner *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev != NULL)
	{
		lst = lst->prev;
	}
	return (lst);
}

t_dinner	*ft_lstlast(t_dinner *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_dinner *node)
{
	int	i;

	i = 0;
	while (node)
	{
		i++;
		node = node->next;
	}
	return (i);
}

void	creat_nodes(t_dinner **head, int ordre, t_data *data)
{
	t_dinner	*new;

	if (*head == NULL)
	{
		*head = ft_lstnew(ordre, data);
	}
	else
	{
		new = malloc(sizeof(t_dinner));
		new->data = data;
		new->philo.id = ordre;
		new->prev = NULL;
		new->next = NULL;
		ft_lstadd_back(head, new);
	}
}
