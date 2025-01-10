/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:18:43 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/10 18:16:26 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_combo_rarb(int ind_a, int ind_b, t_stack **stack_a,
		t_stack **stack_b)
{
	while (ind_a > 0 && ind_b > 0)
	{
		write(1, "rr\n", 3);
		ft_rotate(stack_a);
		ft_rotate(stack_b);
		ind_a--;
		ind_b--;
	}
	while (ind_a > 0)
	{
		write(1, "ra\n", 3);
		ft_rotate(stack_a);
		ind_a--;
	}
	while (ind_b > 0)
	{
		write(1, "rb\n", 3);
		ft_rotate(stack_b);
		ind_b--;
	}
	write(1, "pa\n", 3);
	ft_push(stack_b, stack_a);
}

void	ft_combo_rrarb(int ind_a, int ind_b, t_stack **stack_a,
		t_stack **stack_b)
{
	int	size_stack_a;

	size_stack_a = ft_last_node(*stack_a)->index;
	while (ind_a && ind_a <= size_stack_a)
	{
		write(1, "rra\n", 4);
		ft_r_rotate(stack_a);
		ind_a++;
	}
	while (ind_b > 0)
	{
		write(1, "rb\n", 3);
		ft_rotate(stack_b);
		ind_b--;
	}
	write(1, "pa\n", 3);
	ft_push(stack_b, stack_a);
}

void	ft_combo_rarrb(int ind_a, int ind_b, t_stack **stack_a,
		t_stack **stack_b)
{
	int	size_stack_b;

	size_stack_b = ft_last_node(*stack_b)->index;
	while (ind_b && ind_b <= size_stack_b)
	{
		write(1, "rrb\n", 4);
		ft_r_rotate(stack_b);
		ind_b++;
	}
	while (ind_a > 0)
	{
		write(1, "ra\n", 3);
		ft_rotate(stack_a);
		ind_a--;
	}
	write(1, "pa\n", 3);
	ft_push(stack_b, stack_a);
}

void	ft_combo_rrarrb(int ind_a, int ind_b, t_stack **stack_a,
		t_stack **stack_b)
{
	int	size_stack_a;
	int	size_stack_b;

	size_stack_a = ft_last_node(*stack_a)->index;
	size_stack_b = ft_last_node(*stack_b)->index;
	while (ind_a && ind_a <= size_stack_a && ind_b && ind_b <= size_stack_b)
	{
		write(1, "rrr\n", 4);
		ft_r_rotate(stack_a);
		ft_r_rotate(stack_b);
		ind_a++;
		ind_b++;
	}
	while (ind_a && ind_a <= size_stack_a)
		(write(1, "rra\n", 4), ft_r_rotate(stack_a), ind_a++);
	while (ind_b && ind_b <= size_stack_b)
		(write(1, "rrb\n", 4), ft_r_rotate(stack_b), ind_b++);
	write(1, "pa\n", 3);
	ft_push(stack_b, stack_a);
}

int	init_var_split(int *i, int *j, char ***tab, char *str)
{
	*i = 0;
	*j = 0;
	*tab = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!*tab)
		return (0);
	return (1);
}
