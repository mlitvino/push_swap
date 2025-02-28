/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:53:33 by mlitvino          #+#    #+#             */
/*   Updated: 2025/02/28 17:03:06 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (arr[i] > arr[i + 1])
			return ;
		i++;
	}
	free(arr);
	print_error("Stack is sorted");
}

// void	convert_to_ranks(t_data *data)
// {
// }

// void	check_dupls(t_data *data)
// {
// }

void	int_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*b = *a ^ *b;
}

void	partition(int *arr, t_quick_vars *vars, int left, int right)
{
	if (right - left <= 1)
	{

	}
}

void	quicksort(int *arr, int left, int right)
{
	t_quick_vars vars;

	if (left >= right)
		return ;
	partition(arr, &vars, left, right);
	quicksort(arr, left, vars.i);
	quicksort(arr, vars.j, right);
}

void	check_get_input(int argc, char *argv[], t_data *data)
{
	int		i;
	long	temp;

	data->stk_size = argc;
	data->arr = malloc(argc * sizeof(int));
	if (!data->arr)
		print_error("Error: malloc failed in get_input");
	i = 0;
	while (i < data->stk_size)
	{
		temp = ft_atol(argv[i]);
		if (temp > (long)INT_MAX + 1)
			(free(data->nbr), print_error("Error: invalid argument in input"));
		data->arr[i] = temp;
		i++;
	}
	is_sorted(data->arr, data->stk_size);
	quicksort(data->arr, 0, data->stk_size - 1);
	// check_dupls(data);
	// convert_to_ranks(data);
	// quicksort(data->arr);
	// put_in_stack(data);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		print_error("Error: invalid input");
	check_get_input(argc, argv, &data);
	// if (data.stack_size <- 6)
	// 	sort_small_stack();
	// else
	// 	sort_big_stack();
	return (0);
}
