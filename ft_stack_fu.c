/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_fu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:26:05 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/09 16:29:45 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stknew(t_stack **a, int nbr)
{
	t_stack	*stknew;

	stknew = malloc(sizeof(t_stack));
	if (stknew == NULL)
		return (NULL);
	stknew->nbr = nbr;
	stknew->next = NULL;
	return (stknew);
}

void	ft_stkclear(t_stack **stk)
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

t_stack	*ft_stkadd_back(t_stack **a, t_stack *new)
{
	t_stack	*temp;

	if (new == NULL)
		return (ft_stkclear(a), NULL);
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
