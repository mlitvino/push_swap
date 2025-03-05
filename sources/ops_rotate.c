/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_ops3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:20:28 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/04 17:49:26 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	if (rev_rotate(a))
		ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	if (rev_rotate(b))
		ft_printf("rrb\n");
}

void	ra(t_stack **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}
