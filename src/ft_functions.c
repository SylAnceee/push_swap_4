/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:37:20 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/08 12:21:22 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_atoi(int *result, char *str)
{
	int	sign;

	sign = 1;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (!*str)
			return (false);
	}
	*result = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (*result > *result * 10 - 48 + *str && !(*result == INT_MAX / 10
				&& *str == '8' && !str[1] && sign < 0))
			return (false);
		*result = *result * 10 - 48 + *str;
		str++;
	}
	if (*str)
		return (false);
	return (*result *= sign, true);
}

int	ft_min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

int	ft_max(int x, int y)
{
	if (x < y)
		return (y);
	else
		return (x);
}
