/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:56 by mlitvino          #+#    #+#             */
/*   Updated: 2025/02/20 16:48:03 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

typedef struct s_nbr
{
	int	nbr;
	int	rank;
}		t_nbr;

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_list	opers;
}	t_data;

int			push_swap(int argc, char *argv[]);
t_stack		*check_insert(int i, int argc, char *argv[], t_stack **a);
long	ft_atol(const char *str);

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
void		stkclear(t_stack **stk);
t_stack		*stknew(int nbr);
t_stack		*check_insert(int i, int argc, char *argv[], t_stack **a);
t_stack		*stkadd_back(t_stack **a, t_stack *new);

//stk_manip.c
void		push(t_stack **from, t_stack **to);
void		swap(t_stack **stack);
void		rotate(t_stack **stack);
void		rev_rotate(t_stack **stack);

//utils.c
int			ft_isspace(int c);
void		print_error(char *message);

#endif
