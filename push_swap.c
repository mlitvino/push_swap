/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:43 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/09 17:36:15 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *ft_check_insert(int i, int argc, char *argv[], t_stack **a)
{
	long int	nbr;
	int			j;
	t_stack		*temp;

	if (i == argc)
		return (*a);
	nbr = ft_atoi_check(argv[i]);
	j = 1;
	temp = *a;
	if (nbr > INT_MAX)
		return (ft_stkclear(a), NULL);
	while (temp && j < i)
	{
		if (nbr == temp->nbr)
			return (ft_stkclear(a), NULL);
		temp = temp->next;
	}
	if (i == 1)
		*a = ft_stknew(a, nbr);
	else if (*a)
		ft_stkadd_back(a, ft_stknew(a, nbr));
	if (!a)
		return (NULL);
	return (ft_check_insert(i + 1, argc, argv, a));
}

int	push_swap(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	// ft_printf("start : %d\n", argc);
	b = NULL;
	if (ft_check_insert(1, argc, argv, &a) == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	// if (ft_create_b(1, argc, &b) == NULL)
	// {
	// 	ft_putstr_fd("Error\n", 2);
	// 	return (1);
	// }

	// prints everything // test
	// while (a)
	// {
	// 	ft_printf("%d\n", a->nbr);
	// 	a = a->next;
	// }
	// ft_printf("end\n");
	ft_printf("sb\n");
	return (0);
}
