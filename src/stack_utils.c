/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 12:25:02 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/07 23:24:49 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_stacknew(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> nbr = nbr;
	new -> index = 0;
	new -> next = NULL;
	return (new);
}

bool	ft_is_duplicate(t_stack *stack, int nbr)
{
	while (stack)
	{
		if (stack -> nbr == nbr)
			return (true);
		stack = stack -> next;
	}
	return (false);
}

t_stack	*ft_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_set_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack -> index = i;
		stack = stack -> next;
		i++;
	}
}

bool	ft_is_sorted(t_stack *stack)
{
	int	max;
	int	min;

	if (!stack)
		return (false);
	max = ft_find_max(stack)->nbr;
	min = ft_find_min(stack)->nbr;
	while (stack -> next)
	{
		if (stack -> nbr == max)
		{
			if (stack ->next->nbr != min)
				return (false);
		}
		else if (stack -> nbr > stack->next->nbr)
			return (false);
		stack = stack -> next;
	}
	return (true);
}
