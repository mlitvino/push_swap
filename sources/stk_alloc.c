/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:18:25 by mlitvino          #+#    #+#             */
/*   Updated: 2025/03/03 00:46:46 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stknew(int nbr)
{
	t_stack	*stknew;

	stknew = malloc(sizeof(t_stack));
	if (stknew == NULL)
		return (NULL);
	stknew->nbr = nbr;
	stknew->next = NULL;
	return (stknew);
}

void	stkclear(t_stack *stk)
{
	t_stack	*temp;

	while (stk)
	{
		temp = stk->next;
		free(stk);
		stk = temp;
	}
}

t_stack	*stkadd_back(t_stack *a, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return (stkclear(a), NULL);
	if (!a)
		return (new);
	temp = a;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return (a);
}
