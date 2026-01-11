/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:48:29 by abbouram          #+#    #+#             */
/*   Updated: 2023/11/24 22:48:33 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*buf;

	if (size != 0)
	{
		if (nmemb >= SIZE_MAX / size)
			return (NULL);
	}
	buf = malloc(nmemb * size);
	if (!buf)
		return (NULL);
	ft_bzero(buf, nmemb * size);
	return (buf);
}
