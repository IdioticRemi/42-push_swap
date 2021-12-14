/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:25:39 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/14 16:04:16 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_state(t_state *state, char **argv, int argc)
{
	state->a = 0;
	state->b = 0;
	state->size_a = 0;
	state->size_b = 0;
	parse_argv(state, argv, argc);
	return (1);
}

int	ft_error(int code)
{
	if (!code)
		ft_putchar_fd('\n', 2);
	else
		ft_putendl_fd("Error", 2);
	return (code);
}

int	ft_clean_state(t_state *state, int code)
{
	ft_lstclear(&state->a);
	ft_lstclear(&state->b);
	return (ft_error(code));
}

int	main(int argc, char **argv)
{
	t_state	state;

	if (argc < 2)
		return (ft_error(0));
	if ((argc != 2 && !multi_argv(argv)) || (argc == 2 && !single_argv(argv)))
		return (ft_error(1));
	if (!init_state(&state, argv, argc))
		return (ft_clean_state(&state, 1));
	return (ft_clean_state(&state, 0));
}
