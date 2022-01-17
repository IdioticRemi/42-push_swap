/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:16:35 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/17 20:12:41 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_state *state)
{
	int		tmp;

	if (state->size_a < 2)
		return ;
	tmp = state->a->content;
	state->a->content = state->a->next->content;
	state->a->next->content = tmp;
	ft_putendl_fd("sa", 1);
}

void	pa(t_state *state)
{
	t_list	*b;

	if (state->size_b < 1)
		return ;
	b = state->b;
	state->b = state->b->next;
	ft_lstadd_front(&state->a, b);
	state->size_a++;
	state->size_b--;
	ft_putendl_fd("pa", 1);
}

void	pb(t_state *state)
{
	t_list	*a;

	if (state->size_a < 1)
		return ;
	a = state->a;
	state->a = state->a->next;
	ft_lstadd_front(&state->b, a);
	state->size_a--;
	state->size_b++;
	ft_putendl_fd("pb", 1);
}

void	rra(t_state *state)
{
	t_list	*last;
	int		i;

	if (state->size_a < 2)
		return ;
	last = ft_lstlast(state->a);
	last->next = state->a;
	state->a = last;
	i = -1;
	while (++i < state->size_a - 1)
		last = last->next;
	last->next = 0;
	ft_putendl_fd("rra", 1);
}

void	ra(t_state *state)
{
	t_list	*tmp;

	if (state->size_a < 2)
		return ;
	tmp = state->a->next;
	ft_lstlast(state->a)->next = state->a;
	state->a->next = 0;
	state->a = tmp;
	ft_putendl_fd("ra", 1);
}
