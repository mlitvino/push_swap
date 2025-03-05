/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_ops1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:16:44 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/04 17:49:09 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(b);
	ft_printf("sa\n");
}

void	pa(t_stack **b, t_stack **a)
{
	if (push(b, a))
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(a, b))
		ft_printf("pb\n");
}
