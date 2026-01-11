/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_talk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbouram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 02:04:11 by abbouram          #+#    #+#             */
/*   Updated: 2024/04/06 02:04:12 by abbouram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_TALK_H
# define MINI_TALK_H

# include "../libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

int	check_format(char *str);
int	check_args(char **av);
int	check_process(int pid);

#endif
