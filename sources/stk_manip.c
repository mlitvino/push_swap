/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:18:12 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/05 12:59:07 by mlitvino         ###   ########.fr       */
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

int	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return (0);
	temp = *from;
	*from = (*from)->next;
	temp->next = *to;
	*to = temp;
	return (1);
}

int	rotate(t_stack **stack)
{
	t_stack	*end;
	t_stack	*head;

	if (!*stack || !((*stack)->next))
		return (0);
	end = *stack;
	while (end->next)
		end = end->next;
	head = *stack;
	*stack = head->next;
	end->next = head;
	head->next = NULL;
	return (1);
}

int	rev_rotate(t_stack **stack)
{
	t_stack	*start;
	t_stack	*end;

	if (!stack || !*stack || !((*stack)->next))
		return (0);
	start = NULL;
	end = *stack;
	while (end->next)
	{
		start = end;
		end = end->next;
	}
	start->next = NULL;
	end->next = *stack;
	*stack = end;
	return (1);
}
