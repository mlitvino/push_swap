/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:53:33 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/04 02:06:08 by mlitvino         ###   ########.fr       */
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

	if (!argv)
		return (NULL);
	if (i == argc)
		return (a);
	nbr = safe_atoi(argv[i]);
	if (nbr < INT_MIN || INT_MAX < nbr)
		return (stkclear(a), NULL);
	if (!a)
		a = stknew(nbr);
	else if (a)
		a = stkadd_back(a, stknew(nbr));
	if (!a)
		return (NULL);
	return (get_input(a, i + 1, argc, argv));
}

char	**split_arg(char *argv, int *argc, char **tab)
{
	int	i;

	tab = ft_split(argv, ' ');
	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	*argc = i;
	return (tab);
}

t_stack	*init_start(char **tab, t_stack *a, char *argv[], int *argc)
{
	int	i;

	a = NULL;
	tab = NULL;
	i = 0;
	if (*argc == 2)
	{
		tab = split_arg(argv[1], argc, tab);
		a = get_input(a, 0, *argc, tab);
	}
	else
		a = get_input(a, 1, *argc, argv);
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	if (!a)
		print_error("Error");
	return (a);
}

int	get_path(t_stack *a, int size)
{
	int	i;
	int	min;
	int	min_i;

	min = a->nbr;
	min_i = 0;
	i = 0;
	while (i++ < size)
	{
		rotate(&a);
		if (min <= a->nbr)
			continue ;
		min = a->nbr;
		min_i = i;
	}
	return (min_i);
}

void	sort_three(t_stack *a, int size)
{
	int	min_path;

	min_path = get_path(a, size);
	if (min_path == 0)
	{
		ra(&a);
		if (a->nbr > a->next->nbr)
			sa(&a);
		rra(&a);
	}
	else if (min_path == 1)
	{
		rra(&a);
		if (a->nbr > a->next->nbr)
			sa(&a);
		rra(&a);
	}
	else if (min_path == 2)
	{
		if (a->nbr > a->next->nbr)
			sa(&a);
		rra(&a);
	}
	stkclear(a);
}

void	sort_five(t_stack *a, t_stack *b, int size)
{
	int	i;
	int	min_path;

	min_path = get_path(a, size);
	if (min_path < 3)
		while (min_path > 0)
			ra(&a);
	else
		while (min_path)
			rra(&a);
	pb(&a, &b);
	min_path = get_path(a, size);
	if (min_path < 3)
		while (min_path > 0)
			ra(&a);
	else
		while (min_path)
			rra(&a);
	pb(&a, &b);
	sort_three(&a);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**tab;

	if (argc < 2)
		return (0);
	b = NULL;
	a = init_start(tab, a, argv, &argc);
	chck_prepare_stck(a, argc - 1);
	if (argc - 1 <= 3)
		sort_three(a, argc - 1);
	else if (argc - 1 <= 5)
		sort_five(&a, &b, argc - 1);
	else
		radix(&a, &b, argc - 1);
	stkclear(a);
	stkclear(b);
	return (0);
}
