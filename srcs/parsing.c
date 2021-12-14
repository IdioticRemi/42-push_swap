/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:33:18 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/14 15:51:20 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_single_argv(t_state *state, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		ft_lstadd_back(&state->a, ft_lstnew(ft_atoi(&str[i])));
		while (str[i] && str[i] != ' ')
			i++;
	}
}

void	parse_argv(t_state *state, char **argv, int argc)
{
	int	i;

	if (argc > 2)
	{
		i = 0;
		while (++i < argc)
			ft_lstadd_back(&state->a, ft_lstnew(ft_atoi(argv[i])));
	}
	else
		parse_single_argv(state, argv[1]);
	state->size_a = ft_lstsize(state->a);
}
