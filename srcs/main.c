/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:39 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/17 20:17:04 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_state(t_state *state, char **argv, int argc)
{
	state->a = 0;
	state->b = 0;
	state->size_a = 0;
	state->size_b = 0;
	return (parse_argv(state, argv, argc));
}

void	ft_exit(int code)
{
	if (code)
		ft_putendl_fd("Error", 2);
	exit(code);
}

void	ft_clean_state(t_state *state, int code)
{
	ft_lstclear(&state->a);
	ft_lstclear(&state->b);
	ft_exit(code);
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 2)
		ft_exit(0);
	if (!init_state(&state, argv, argc))
		ft_clean_state(&state, 1);
	if (is_sorted_asc(state.a))
		ft_clean_state(&state, 0);
	else if (state.size_a > 5)
		radix(&state);
	else
		small(&state);
	ft_clean_state(&state, 0);
}
