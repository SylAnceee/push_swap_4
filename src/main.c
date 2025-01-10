/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:19:44 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/10 18:47:31 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	if (!*stack_a)
		return ;
	i = ft_last_node(*stack_a)->index;
	if (!ft_is_sorted(*stack_a))
	{
		while (i > 2)
		{
			(write(1, "pb\n", 3), ft_push(stack_a, stack_b));
			i--;
		}
		if (!ft_is_sorted(*stack_a))
			(write(1, "sa\n", 3), ft_swap(stack_a));
		if (*stack_b)
		{
			i = ft_last_node(*stack_b)->index;
			while (i >= 0)
				(ft_make_best_combo(stack_a, stack_b), i--);
		}
	}
	ft_make_order(stack_a);
}

t_stack	*ft_find_best_elem(t_stack *stack_a, t_stack *stack_b)
{
	int		best_score;
	t_stack	*elem;

	elem = stack_b;
	best_score = ft_find_cheapest(stack_a, stack_b,
			ft_find_target(stack_a, elem -> nbr), elem -> index);
	while (stack_b)
	{
		if (best_score >= ft_find_cheapest(stack_a, stack_b,
				ft_find_target(stack_a, stack_b -> nbr), stack_b -> index))
		{
			best_score = ft_find_cheapest(stack_a, stack_b,
					ft_find_target(stack_a, stack_b -> nbr), stack_b -> index);
			elem = stack_b;
		}
		stack_b = stack_b -> next;
	}
	return (elem);
}

void	ft_make_best_combo(t_stack **stack_a, t_stack **stack_b)
{
	int	ind_target_a;
	int	ind_target_b;
	int	best_combo;

	ind_target_a = ft_find_target(*stack_a,
			ft_find_best_elem(*stack_a, *stack_b)->nbr);
	ind_target_b = ft_find_best_elem(*stack_a, *stack_b)->index;
	best_combo = ft_find_best_combo(ind_target_a,
			ind_target_b, *stack_a, *stack_b);
	if (best_combo == RARB)
		ft_combo_rarb(ind_target_a, ind_target_b, stack_a, stack_b);
	else if (best_combo == RRARRB)
		ft_combo_rrarrb(ind_target_a, ind_target_b, stack_a, stack_b);
	else if (best_combo == RRARB)
		ft_combo_rrarb(ind_target_a, ind_target_b, stack_a, stack_b);
	else
		ft_combo_rarrb(ind_target_a, ind_target_b, stack_a, stack_b);
}

void	init_vars(t_stack **stack_a, t_stack **stack_b, int *nbr, int *i)
{
	*stack_a = NULL;
	*stack_b = NULL;
	*nbr = 0;
	*i = 0;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		nbr;
	int		i;

	init_vars(&stack_a, &stack_b, &nbr, &i);
	if (ac == 2)
		split_arguments(av[1], &stack_a);
	else if (fill_stack(av, &stack_a, i) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	ft_set_index(stack_a);
	ft_sort(&stack_a, &stack_b);
	ft_stackclear(&stack_a);
	return (EXIT_SUCCESS);
}
