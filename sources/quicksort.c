/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 03:13:15 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/04 18:41:36 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	int_swap(int *a, int *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void	partition(int *arr, t_quick_vars *vars, int left, int right)
{
	int	mid;
	int	pivot;

	if (right - left <= 1)
	{
		if (arr[right] < arr[left])
			int_swap(&arr[right], &arr[left]);
		vars->i = left;
		vars->j = right;
		return ;
	}
	mid = left;
	pivot = arr[(left + right) / 2];
	while (mid <= right)
	{
		if (arr[mid] < pivot)
			int_swap(&arr[left++], &arr[mid++]);
		else if (arr[mid] == pivot)
			mid++;
		else if (arr[mid] > pivot)
			int_swap(&arr[mid], &arr[right--]);
	}
	vars->i = left - 1;
	vars->j = mid;
}

void	quicksort(int *arr, int left, int right)
{
	t_quick_vars	vars;

	if (left >= right)
		return ;
	partition(arr, &vars, left, right);
	quicksort(arr, left, vars.i);
	quicksort(arr, vars.j, right);
}
