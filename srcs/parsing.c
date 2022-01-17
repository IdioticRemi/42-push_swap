/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:33:18 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/17 13:56:32 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dup(int n)
{
	return (n);
}

void	normalize(t_state *state)
{
	t_list	*copy[2];

	copy[0] = state->a;
	copy[1] = ft_lstmap(state->a, &dup);
	lst_sort(copy[1]);
	while (copy[0])
	{
		copy[0]->content = lst_index(copy[1], copy[0]->content);
		copy[0] = copy[0]->next;
	}
	ft_lstclear(&copy[1]);
}

int	check_number(char *n)
{
	int	i;

	if (ft_strlen(n) > (10 + (n[0] == '-')))
		return (0);
	if ((n[0] == '+' || n[0] == '-') && ft_strlen(n) < 2)
		return (0);
	i = -1;
	while (n[++i])
	{
		if (!ft_strchr("0123456789+-", n[i]))
			return (0);
		if ((n[0] == '+' || n[0] == '-') && i)
			if (!n[i] || !ft_isdigit(n[i]))
				return (0);
	}
	if (ft_atol(n) > INT_MAX || ft_atol(n) < INT_MIN)
		return (0);
	return (1);
}

int	parse_arg(t_state *state, char *arg)
{
	char	**numbers;
	int		i;

	i = -1;
	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	while (numbers[++i])
	{
		if (!check_number(numbers[i]))
		{
			ft_afree(numbers);
			return (0);
		}
		ft_lstadd_back(&state->a, ft_lstnew(ft_atoi(numbers[i])));
	}
	ft_afree(numbers);
	return (1);
}

int	parse_argv(t_state *state, char **argv, int argc)
{
	int		i;
	t_list	*el;
	t_list	*tmp;

	i = 0;
	while (++i < argc)
	{
		if (!parse_arg(state, argv[i]))
			return (0);
	}
	el = state->a;
	while (el && el->next)
	{
		tmp = el->next;
		while (tmp)
		{
			if (tmp->content == el->content)
				return (0);
			tmp = tmp->next;
		}
		el = el->next;
	}
	state->size_a = ft_lstsize(state->a);
	normalize(state);
	return (1);
}
