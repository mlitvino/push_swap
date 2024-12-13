/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:43 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/13 12:19:49 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *check_insert(int i, int argc, char *argv[], t_stack **a)
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
		return (stkclear(a), NULL);
	while (temp && j < i)
	{
		if (nbr == temp->nbr)
			return (stkclear(a), NULL);
		temp = temp->next;
	}
	if (i == 1)
		*a = stknew(a, nbr);
	else if (*a)
		stkadd_back(a, stknew(a, nbr));
	if (!a)
		return (stkclear(a), NULL);
	return (check_insert(i + 1, argc, argv, a));
}

int	push_swap(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (check_insert(1, argc, argv, &a) == NULL)
	{
		putstr_fd("Error\n", 2);
		return (1);
	}

	// prints everything // test
	ft_printf("start\n");
	t_stack *t = a;

	while (t)
	{
		ft_printf("%d\n", t->nbr);
		t = t->next;
	}

	push(&a, &b);
	swap(&a);

	t = a;
	ft_printf("after push+swap a:\n");
	while (t)
	{
		ft_printf("%d\n", t->nbr);
		t = t->next;
	}

	ft_printf("b:\n");
	while (b)
	{
		ft_printf("%d\n", b->nbr);
		b = b->next;
	}


	// rotate(&a);
	// ft_printf("after rotate a:\n");
	// t = a;
	// while (t)
	// {
	// 	ft_printf("%d\n", t->nbr);
	// 	t = t->next;
	// }

	// ft_printf("end\n");


	return (0);
}
