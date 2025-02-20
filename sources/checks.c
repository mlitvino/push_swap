/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:42:29 by mlitvino          #+#    #+#             */
/*   Updated: 2025/02/20 16:48:23 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int			res;
	int			sign;
	long		temp;

	res = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		temp = res;
		if (temp > INT_MAX || temp < INT_MIN)
			return (temp);
		res = res * 10 + (*str++ - '0');
	}
	if (*str)
		return ((long)INT_MAX + 1);
	return (res * sign);
}

void	check_dupl(t_stack **a, int i, int nbr)
{
	int			j;
	t_stack		*temp;

	j = 1;
	temp = *a;
	while (temp && j < i)
	{
		if (nbr == temp->nbr)
		{
			stkclear(a);
			print_error("Error: argument contains duplicate");
		}
		temp = temp->next;
	}
}

t_stack	*check_insert(int i, int argc, char *argv[], t_stack **a)
{
	long int	nbr;

	if (i == argc)
		return (*a);
	nbr = ft_atol(argv[i]);
	if (INT_MIN > nbr || nbr > INT_MAX)
	{
		stkclear(a);
		print_error("Error: argument is not an integer");
	}
	check_dupl(a, i, nbr);
	if (i == 1)
		*a = stknew(nbr);
	else if (*a)
		stkadd_back(a, stknew(nbr));
	if (!a)
		return (stkclear(a), NULL);
	return (check_insert(i + 1, argc, argv, a));
}
