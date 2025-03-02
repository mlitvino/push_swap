/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:42:29 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/03 01:13:12 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	safe_atoi(const char *str)
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
			return ((long)INT_MAX + 1);
		res = res * 10 + (*str++ - '0');
	}
	while (ft_isspace(*str))
		str++;
	if (*str)
		return ((long)INT_MAX + 1);
	return (res * sign);
}

void	is_sorted(t_stack *a)
{
	int		num;
	t_stack	*temp;

	temp = a;
	num = temp->nbr;
	while (temp->next)
	{
		temp = temp->next;
		if (num >= temp->nbr)
			return ;
		num = temp->nbr;
	}
	stkclear(a);
	exit(0);
}

void	check_dupls(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			print_error("Error: input contains a duplicate");
		}
		i++;
	}
}

void	convert_ranks(t_stack *a, int *arr, int size)
{
	int		i;
	t_stack	*temp;
	int		org;

	temp = a;
	while (temp)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] == temp->nbr)
			{
				temp->nbr = i;
				break;
			}
			i++;
		}
		temp = temp->next;
	}
}

t_stack	*chck_prepare_stck(t_stack *a, int size)
{
	t_stack	*temp;
	int		*copy;
	int		i;

	is_sorted(a);
	copy = malloc(sizeof(int) * size);
	if (!copy)
	{
		stkclear(a);
		print_error("Error: malloc failed in chck_prepare_stck");
	}
	i = 0;
	temp = a;
	while (i < size)
	{
		copy[i] = temp->nbr;
		temp = temp->next;
		i++;
	}
	quicksort(copy, 0, size - 1);
	check_dupls(copy, size);
	convert_ranks(a, copy, size);
	free(copy);
	return (a);
}
