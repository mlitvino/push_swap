/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:56 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/04 19:20:54 by mlitvino         ###   ########.fr       */
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

typedef struct s_quick_vars
{
	int	i;
	int	j;
	int	mid;
	int	pivot;
}		t_quick_vars;

//checks.c
long		safe_atoi(const char *str);
void		is_sorted(t_stack *a);
void		check_dupls(int *arr, int size, t_stack *a);
void		convert_ranks(t_stack *a, int *arr, int size);
t_stack		*chck_prepare_stck(t_stack *a, int size);

//main.c
t_stack		*get_input(t_stack *a, int i, int argc, char *argv[]);
char		**split_arg(char *argv, int *argc, char **tab);
t_stack		*init_start(char **tab, t_stack *a, char *argv[], int *argc);

//ops_rotate.c
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);

//ops_swappush.c
void		sa(t_stack **a);
void		sb(t_stack **b);
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);

//quicksort.c
void		int_swap(int *a, int *b);
void		partition(int *arr, t_quick_vars *vars, int left, int right);
void		quicksort(int *arr, int left, int right);

//radix.c
void		radix(t_stack **a, t_stack **b, int size);

//sort_small.c
int			get_path(t_stack **a, int size);
void		sort_three(t_stack **a, int size);
void		sort_small(t_stack **a, t_stack **b, int size);

//stk_alloc.c
void		stkclear(t_stack *stk);
t_stack		*stknew(int nbr);
t_stack		*stkadd_back(t_stack *a, t_stack *new);

//stk_manip.c
int			push(t_stack **from, t_stack **to);
void		swap(t_stack **stack);
int			rotate(t_stack **stack);
int			rev_rotate(t_stack **stack);

//utils.c
int			ft_isspace(int c);
void		print_error(t_stack *a, char *message);

#endif
