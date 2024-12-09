/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:16:56 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/09 17:25:29 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "limits.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

int			push_swap(int argc, char *argv[]);
long int	ft_atoi_check(const char *str);
void		ft_stkclear(t_stack **stk);
t_stack		*ft_stknew(t_stack **a, int nbr);
t_stack		*ft_check_insert(int i, int argc, char *argv[], t_stack **a);
t_stack		*ft_stkadd_back(t_stack **a, t_stack *new);

#endif
