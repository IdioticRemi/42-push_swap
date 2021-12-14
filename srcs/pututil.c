/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pututil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:04:08 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/14 15:51:44 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putlst(t_list *list)
{
	if (!list)
	{
		ft_putendl_fd("", 1);
		return ;
	}
	ft_putstr_fd("[ ", 1);
	while (list->next)
	{
		ft_putnbr_fd(list->content, 1);
		ft_putstr_fd(" ] -> [ ", 1);
		list = list->next;
	}
	ft_putnbr_fd(list->content, 1);
	ft_putendl_fd(" ]", 1);
}

void	ft_putstate(t_state *state)
{
	ft_putstr_fd("(", 1);
	ft_putnbr_fd(state->size_a, 1);
	ft_putstr_fd(")\t", 1);
	ft_putstr_fd("A: ", 1);
	ft_putlst(state->a);
	ft_putstr_fd("(", 1);
	ft_putnbr_fd(state->size_b, 1);
	ft_putstr_fd(")\t", 1);
	ft_putstr_fd("B: ", 1);
	ft_putlst(state->b);
}