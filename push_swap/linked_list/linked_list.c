/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:48:10 by abbouram          #+#    #+#             */
/*   Updated: 2024/03/26 12:48:12 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_stack *lst)
{
	t_stack	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*add;

	if (new)
	{
		if (!*lst)
		{
			*lst = new;
			new->next = NULL;
			return ;
		}
		add = ft_lstlast(*lst);
		add->next = new;
		new->next = NULL;
	}
}

void	creat_nodes(t_stack **head, int nbr)
{
	t_stack	*new;

	if (*head == NULL)
	{
		*head = ft_lstnew(nbr);
	}
	else
	{
		new = malloc(sizeof(t_stack));
		new->num = nbr;
		new->next = NULL;
		ft_lstadd_back(head, new);
	}
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->num = content;
	newnode->next = NULL;
	return (newnode);
}
