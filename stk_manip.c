/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:18:12 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/13 16:44:09 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*end;

	end = *stack;
	while (end->next)
		end = end->next;
	end->next = (*stack);
	(*stack) = (*stack)->next;
	end->next->next = NULL;
}

void	rev_rotate(t_stack **stack)
{
	t_stack	*start;
	t_stack	*end;

	if ((*stack)->next == NULL)
		return ;
	start = *stack;
	while (start->next->next)
		start = start->next;
	end = start->next;
	end->next = *stack;
	start->next = NULL;
	*stack = end;
}
