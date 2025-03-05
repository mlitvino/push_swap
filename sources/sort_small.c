/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:43:56 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/05 12:58:51 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_path(t_stack **a, int size)
{
	int		i;
	int		min;
	int		min_i;
	t_stack	*temp;

	temp = *a;
	min = temp->nbr;
	min_i = 0;
	i = 0;
	if (size == 2)
		return (sa(a), -1);
	while (i < size)
	{
		if (temp->nbr < min)
		{
			min = temp->nbr;
			min_i = i;
		}
		rotate(&temp);
		i++;
	}
	return (min_i);
}

void	sort_three(t_stack **a, int size)
{
	int	min_path;

	min_path = get_path(a, size);
	if (min_path == 0)
	{
		ra(a);
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
		rra(a);
	}
	else if (min_path == 1)
	{
		rra(a);
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
		rra(a);
	}
	else if (min_path == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
		rra(a);
	}
}

void	sort_small(t_stack **a, t_stack **b, int size)
{
	int	min_path;

	if (size <= 3)
	{
		sort_three(a, size);
		pa(b, a);
		pa(b, a);
		return ;
	}
	min_path = get_path(a, size);
	if (min_path < 3)
		while (min_path-- > 0)
			ra(a);
	else if (min_path > size - 3)
		while (min_path++ < size)
			rra(a);
	pb(a, b);
	sort_small(a, b, size - 1);
}
