/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_manip.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:18:12 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/03 01:07:22 by mlitvino         ###   ########.fr       */
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

void push(t_stack **from, t_stack **to)
{
    if (!*from)
        return;

    // remove the first node from '*from'
    t_stack *temp = *from;
    *from = (*from)->next;

    // push that node onto '*to'
    temp->next = *to;
    *to = temp;
}

void rotate(t_stack **stack)
{
    t_stack *head = *stack;
    if (!head || !head->next)
        return; // 0 or 1 node, no rotate needed

    // find the last node
    t_stack *end = head;
    while (end->next)
        end = end->next;

    // move the first node to the end
    *stack = head->next;   // new head
    end->next = head;      // old head becomes last
    head->next = NULL;     // old head next is null
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
