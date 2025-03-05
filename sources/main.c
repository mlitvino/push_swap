/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:53:33 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/04 19:11:35 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	*argc = i + 1;
	return (tab);
}

t_stack	*init_start(char **tab, t_stack *a, char *argv[], int *argc)
{
	int	i;

	i = 0;
	if (*argc == 2)
	{
		tab = split_arg(argv[1], argc, tab);
		a = get_input(a, 0, *argc - 1, tab);
	}
	else
		a = get_input(a, 1, *argc, argv);
	while (tab && tab[i])
		free(tab[i++]);
	free(tab);
	if (!a)
		print_error(a, "Error");
	return (a);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**tab;

	if (argc < 2)
		return (0);
	a = NULL;
	tab = NULL;
	b = NULL;
	a = init_start(tab, a, argv, &argc);
	chck_prepare_stck(a, argc - 1);
	if (argc - 1 <= 5)
		sort_small(&a, &b, argc - 1);
	else
		radix(&a, &b, argc - 1);
	stkclear(a);
	stkclear(b);
	return (0);
}
