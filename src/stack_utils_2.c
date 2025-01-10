/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:31:35 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/10 16:42:04 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	if (!(*stack))
		*stack = new;
	else
		ft_last_node(*stack)->next = new;
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	new -> next = *stack;
	*stack = new;
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	ft_make_order(t_stack **stack)
{
	int	ind_min;
	int	size;

	if (!*stack)
		return ;
	ind_min = ft_find_min(*stack)->index;
	size = ft_last_node(*stack)->index;
	if (ind_min <= size / 2)
	{
		while (ind_min > 0)
			(write(1, "ra\n", 3), ft_rotate(stack), ind_min--);
	}
	else
	{
		while (ind_min <= size)
			(write(1, "rra\n", 4), ft_r_rotate(stack), ind_min++);
	}
}

int	fill_stack(char **av, t_stack **stack_a, int i)
{
	t_stack	*new;
	int		nbr;

	while (av[++i])
	{
		if (!ft_atoi(&nbr, av[i]))
			return (write(2, "Error1\n", 6), ft_stackclear(stack_a),
				EXIT_FAILURE);
		new = ft_stacknew(nbr);
		if (!new || ft_is_duplicate(*stack_a, nbr))
			return (write(2, "Error2\n", 6), ft_stackclear(stack_a),
				EXIT_FAILURE);
		ft_stackadd_back(stack_a, new);
	}
	return (EXIT_SUCCESS);
}
