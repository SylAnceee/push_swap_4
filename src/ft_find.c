/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 17:38:57 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/07 23:38:50 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_find_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (stack -> nbr > max -> nbr)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*ft_find_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (stack -> nbr < min -> nbr)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_target(t_stack *stack, int nbr)
{
	int	index;
	int	target_a;

	if (nbr > ft_find_max(stack)->nbr)
		return (ft_find_min(stack)->index);
	target_a = INT_MAX;
	index = 0;
	while (stack)
	{
		if (stack -> nbr > nbr && stack -> nbr < target_a)
		{
			index = stack -> index;
			target_a = stack -> nbr;
		}
		stack = stack -> next;
	}
	return (index);
}

int	ft_find_cheapest(t_stack *stack_a, t_stack *stack_b, int ind_target_a,
		int ind_target_b)
{
	int	rarb2;
	int	rrarrb2;
	int	rarrb2;
	int	rrarb2;

	rarb2 = ft_max(ind_target_a, ind_target_b);
	rrarrb2 = ft_max(ft_last_node(stack_a)->index - ind_target_a,
			ft_last_node(stack_b)->index - ind_target_b) + 1;
	rarrb2 = ind_target_a + ft_last_node(stack_b)->index - ind_target_b + 1;
	rrarb2 = ind_target_b + ft_last_node(stack_a)->index - ind_target_a + 1;
	return (ft_min(ft_min(rarb2, rrarrb2), ft_min(rarrb2, rrarb2)));
}

int	ft_find_best_combo(int ind_target_a, int ind_target_b, t_stack *stack_a,
		t_stack *stack_b)
{
	int	rarb;
	int	rrarrb;
	int	rarrb;
	int	rrarb;

	rarb = ft_max(ind_target_a, ind_target_b);
	rrarrb = ft_max(ft_last_node(stack_a)->index - ind_target_a,
			ft_last_node(stack_b)->index - ind_target_b) + 1;
	rarrb = ind_target_a + ft_last_node(stack_b)->index - ind_target_b + 1;
	rrarb = ind_target_b + ft_last_node(stack_a)->index - ind_target_a + 1;
	if (rarb <= rrarb && rarb <= rrarrb && rarb <= rarrb)
		return (RARB);
	if (rrarrb <= rarb && rrarrb <= rrarb && rrarrb <= rarrb)
		return (RRARRB);
	if (rarrb <= rarb && rarrb <= rrarrb && rarrb <= rrarb)
		return (RARRB);
	return (RRARB);
}
