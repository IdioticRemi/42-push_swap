/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op0.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:16:35 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/14 15:57:30 by tjolivea         ###   ########.fr       */
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

void	sb(t_state *state)
{
	int	tmp;

	if (state->size_b < 2)
		return ;
	tmp = state->b->content;
	state->b->content = state->b->next->content;
	state->b->next->content = tmp;
	ft_putendl_fd("sb", 1);
}

void	ss(t_state *state)
{
	int	tmp;

	if (state->size_a < 2 || state->size_b < 2)
		return ;
	tmp = state->a->content;
	state->a->content = state->a->next->content;
	state->a->next->content = tmp;
	tmp = state->b->content;
	state->b->content = state->b->next->content;
	state->b->next->content = tmp;
	ft_putendl_fd("ss", 1);
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
