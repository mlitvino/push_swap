/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:56 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/02 03:25:43 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
	int		stk_size;
}			t_data;

typedef struct s_quick_vars
{
	int	i;
	int	j;
	int	mid;
	int	pivot;
}		t_quick_vars;

//sort_arr.c
void		int_swap(int *a, int *b);
void		partition(int *arr, t_quick_vars *vars, int left, int right);
void		quicksort(int *arr, int left, int right);

void		check_get_input(int argc, char *argv[], t_data *data);
void		check_prepare_stack(t_stack *a, int size);

//void	is_sorted(int *arr, int n);

int			push_swap(int argc, char *argv[]);
t_stack		*check_insert(int i, int argc, char *argv[], t_stack **a);
long		safe_atoi(const char *str);

//ops1
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);

//ops2
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

//ops3
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

//stk_alloc.c
void		stkclear(t_stack *stk);
t_stack		*stknew(int nbr);
// t_stack		*check_insert(int i, int argc, char *argv[], t_stack **a);
t_stack		*stkadd_back(t_stack *a, t_stack *new);

//stk_manip.c
void		push(t_stack **from, t_stack **to);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);

//utils.c
int			ft_isspace(int c);
void		print_error(char *message);

#endif
