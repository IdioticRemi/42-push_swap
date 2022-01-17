/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:54:31 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/17 20:09:18 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix(t_state *state)
{
	int	shift;
	int	j;
	int	max;

	max = 0;
	while ((state->size_a - 1) >> max)
		max++;
	shift = -1;
	while (shift++ < max - 1)
	{
		j = state->size_a + 1;
		while (--j)
		{
			if (state->a->content & (1 << shift))
				ra(state);
			else
				pb(state);
		}
		while (state->size_b)
			pa(state);
	}
}

void	sort_3(t_state *state)
{
	int	i[3];

	while (!is_sorted_asc(state->a))
	{
		i[0] = state->a->content;
		i[1] = state->a->next->content;
		i[2] = state->a->next->next->content;
		if (i[0] > i[1] && i[1] < i[2] && i[0] > i[2])
			ra(state);
		else if (i[0] < i[1] && i[1] > i[2])
			rra(state);
		else if (i[0] < i[1] && i[1] > i[2] && i[0] < i[2])
			ra(state);
		else if (i[0] > i[1])
			sa(state);
	}
}

void	small(t_state *state)
{
	if (state->size_a == 2)
		sa(state);
	else if (state->size_a == 3)
		sort_3(state);
	else
	{
		while (state->size_a == 5)
		{
			ft_move_toward(state, 0);
			if (state->a->content == 0)
				pb(state);
		}
		while (state->size_a == 4)
		{
			ft_move_toward(state, 1);
			if (state->a->content == 1)
				pb(state);
		}
		sort_3(state);
		while (state->size_b)
			pa(state);
	}
}
