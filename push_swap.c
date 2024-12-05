/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:43 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/05 12:20:11 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_is_invalid(int argc, char *argv[])
{
	int	i;

	i = 1;
	char	len[argc];
	if (argc < 2)
		return (1);
	while (i < argc)
	{

		i++;
	}

	return (0);
}

int	push_swap(int argc, char *argv[])
{
	if (ft_is_invalid(argc, argv))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}

	printf("%d\n", argc);
	return (0);
}

int main(int argc, char *argv[])
{
	push_swap(argc, argv);

	return (0);
}
