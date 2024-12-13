/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_stk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:18:25 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/13 12:20:33 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stknew(t_stack **a, int nbr)
{
	t_stack	*stknew;

	stknew = malloc(sizeof(t_stack));
	if (stknew == NULL)
		return (NULL);
	stknew->nbr = nbr;
	stknew->next = NULL;
	return (stknew);
}

void	stkclear(t_stack **stk)
{
	t_stack	*temp;

	if (*stk == NULL || stk == NULL)
		return ;
	while (*stk != NULL)
	{
		temp = (*stk)->next;
		free(*stk);
		*stk = temp;
	}
	*stk = NULL;
}

t_stack	*stkadd_back(t_stack **a, t_stack *new)
{
	t_stack	*temp;

	if (new == NULL)
		return (NULL);
	if (*a == NULL)
	{
		*a = new;
		return (NULL);
	}
	temp = *a;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}
