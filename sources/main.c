/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:53:33 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/02 03:26:32 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	p(t_stack *a)
{
	while (a)
	{
		ft_printf("%d\n", a->nbr);
		a = a->next;
	}
}

t_stack	*get_input(t_stack *a, int i, int argc, char *argv[])
{
	long	nbr;

	if (i == argc)
		return (a);
	nbr = safe_atoi(argv[i]);
	if (nbr < INT_MIN || INT_MAX < nbr)
	{
		stkclear(a);
		print_error("Error: argument is not an integer");
	}
	if (i == 1)
		a = stknew(nbr);
	else if (a)
		a = stkadd_back(a, stknew(nbr));
	if (!a)
		return (NULL);
	return (get_input(a, i + 1, argc, argv));
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 3)
		return (0);
	data.stk_size = argc - 1;
	data.a = get_input(data.a, 1, argc, argv);
	if (!data.a)
		print_error("Error: malloc failed int get_input");
	check_prepare_stack(data.a, argc - 1);
	p(data.a);
	//check(argc, argv, &data);
	// if (data.stack_size <- 6)
	// 	sort_small_stack();
	// else
	// 	sort_big_stack();
	return (0);
}
