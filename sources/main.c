/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:53:33 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/03 01:35:49 by mlitvino         ###   ########.fr       */
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

void	sort_three(t_stack **a, t_stack **b, int size)
{
	
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
		return (0);
	b = NULL;
	data.size = argc - 1;
	a = get_input(a, 1, argc, argv);
	if (!a)
		print_error("Error: malloc failed int get_input");
	chck_prepare_stck(a, argc - 1);
	if (argc - 1 <= 3)
		sort_three(&a, &b, argc - 1);
	else if (argc - 1 <= 5)
		sort_five(&a, &b, argc - 1);
	else
		radix(&a, &b, argc - 1);
	stkclear(a);
	stkclear(b);
	return (0);
}
