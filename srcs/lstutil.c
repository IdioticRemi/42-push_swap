/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:44:50 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/17 20:10:35 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_sort(t_list *lst)
{
	t_list	*tmp[2];
	int		lol[3];

	tmp[0] = lst;
	lol[0] = ft_lstsize(lst) - 1;
	while (tmp[0] && lol[0])
	{
		tmp[1] = tmp[0];
		lol[2] = lol[0];
		while (lol[2] > 0)
		{
			if (tmp[1]->content > tmp[1]->next->content)
			{
				lol[1] = tmp[1]->content;
				tmp[1]->content = tmp[1]->next->content;
				tmp[1]->next->content = lol[1];
			}
			tmp[1] = tmp[1]->next;
			lol[2]--;
		}
		lol[0]--;
	}
}

int	lst_index(t_list *lst, int val)
{
	int	index;

	index = -1;
	while (lst && lst->content != val + (0 * ++index))
		lst = lst->next;
	return (index);
}

int	is_sorted_asc(t_list *lst)
{
	while (lst && lst->next)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	ft_move_toward(t_state *state, int n)
{
	int	idx;

	if (state->a->content == n)
		return ;
	idx = lst_index(state->a, n);
	if (idx > state->size_a / 2)
		rra(state);
	else
		ra(state);
}
