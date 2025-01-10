/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:16:47 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/10 18:16:53 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
# include <string.h>

# define RARB 1
# define RRARB 2
# define RARRB 3
# define RRARRB 4

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct init_vava
{
	int		i;
	int		j;
	char	**tab;
} t_vava;
// MAIN
void	ft_sort(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_find_best_elem(t_stack *stack_a, t_stack *stack_b);
void	ft_make_best_combo(t_stack **stack_a, t_stack **stack_b);
void	init_vars(t_stack **stack_a, t_stack **stack_b, int *nbr, int *i);

// COMBOS
void	ft_combo_rarb(int ind_a, int ind_b, t_stack **stack_a,
			t_stack **stack_b);
void	ft_combo_rrarb(int ind_a, int ind_b, t_stack **stack_a,
			t_stack **stack_b);
void	ft_combo_rarrb(int ind_a, int ind_b, t_stack **stack_a,
			t_stack **stack_b);
void	ft_combo_rrarrb(int ind_a, int ind_b, t_stack **stack_a,
			t_stack **stack_b);
int		init_var_split(int *i, int *j, char ***tab, char *str);

// FINDS
t_stack	*ft_find_max(t_stack *stack);
t_stack	*ft_find_min(t_stack *stack);
int		ft_find_target(t_stack *stack, int nbr);
int		ft_find_cheapest(t_stack *stack_a, t_stack *stack_b, int ind_target_a,
			int ind_target_b);
int		ft_find_best_combo(int ind_target_a, int ind_target_b, t_stack *stack_a,
			t_stack *stack_b);

// OPERATIONS
void	ft_push(t_stack **stack_src, t_stack **stack_dest);
void	ft_rotate(t_stack **stack);
void	ft_r_rotate(t_stack **stack);
void	ft_swap(t_stack **stack);

// FTs
int		ft_min(int x, int y);
int		ft_max(int x, int y);
bool	ft_atoi(int *result, char *str);

// STACK UTILS
t_stack	*ft_stacknew(int nbr);
t_stack	*ft_last_node(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackclear(t_stack **stack);
void	ft_set_index(t_stack *stack);
bool	ft_is_duplicate(t_stack *stack, int nbr);
bool	ft_is_sorted(t_stack *stack);
void	ft_make_order(t_stack **stack);
int		fill_stack(char **av, t_stack **stack_a, int i);

//SPLIT
void	split_arguments(char *arg, t_stack **stack_a);
void	ft_free_split(char **args);
int		ft_strlen(char *str);
char	**ft_split(char *str, char sep);
#endif