/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:43:26 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/09 13:13:57 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	**ft_sa(t_list **a)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!(*a)->next)
		return (NULL);
	temp1 = (*a)->next->next;
	temp2 = (*a)->next;

	//temp1->prevs = *a;
	(*a)->next = temp1;
	//(*a)->prevs = temp2;

	temp2->next = *a;
	//temp2->prevs = NULL;
}

