/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:58:06 by mlitvino          #+#    #+#             */
/*   Updated: 2025/02/20 17:23:39 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

void	free_data(t_data *data)
{
	stkclear(data->a);
	stkclear(data->b);
}

void	print_error(char *message, t_data *data)
{
	free_data(data);
	ft_putendl_fd(message, 2);
	exit(1);
}
