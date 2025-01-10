/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abreuil <abreuil@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:05:23 by abreuil           #+#    #+#             */
/*   Updated: 2025/01/10 18:16:15 by abreuil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strlcpy(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_split(char *str, char sep)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!init_var_split(&i, &j, &tab, str))
		return (NULL);
	while (str[i])
	{
		while (str[i] == sep)
			i++;
		k = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i > k)
		{
			tab[j] = malloc(sizeof(char) * (i - k + 1));
			if (!tab[j])
				return (NULL);
			ft_strlcpy(tab[j], str + k, i - k + 1);
			j++;
		}
	}
	return (tab[j] = NULL, tab);
}

void	split_arguments(char *arg, t_stack **stack_a)
{
	char	**args;
	t_stack	*new;
	int		nbr;
	int		i;

	args = ft_split(arg, ' ');
	if (!args)
		return (write(2, "Error\n", 6), exit(EXIT_FAILURE));
	i = -1;
	while (args[++i])
	{
		if (!ft_atoi(&nbr, args[i]) || ft_is_duplicate(*stack_a, nbr))
			return (write(2, "Error\n", 6), ft_stackclear(stack_a),
				ft_free_split(args), exit(EXIT_FAILURE));
		new = ft_stacknew(nbr);
		if (!new)
			return (write(2, "Error\n", 6), ft_stackclear(stack_a),
				ft_free_split(args), exit(EXIT_FAILURE));
		ft_stackadd_back(stack_a, new);
	}
	ft_free_split(args);
}

void	ft_free_split(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}
