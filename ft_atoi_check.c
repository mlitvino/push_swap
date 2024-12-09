/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlitvino <mlitvino@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:42:29 by mlitvino          #+#    #+#             */
/*   Updated: 2024/12/09 17:09:20 by mlitvino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_check(const char *str)
{
	int			res;
	int			sign;
	long int	temp;

	res = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		temp = res;
		if (temp > INT_MAX)
			return (temp);
		res = res * 10 + (*str++ - '0');
	}
	temp = INT_MAX;
	if (*str)
		return (temp + 1);
	return (res * sign);
}
