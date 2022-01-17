/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:57:37 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/17 20:14:01 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

// Structure
typedef struct s_state
{
	t_list	*a;
	t_list	*b;
	int		size_a;
	int		size_b;
}	t_state;

// Parsing
int		parse_argv(t_state *state, char **argv, int single);

// Operations
void	sa(t_state *state);
void	pa(t_state *state);
void	pb(t_state *state);
void	ra(t_state *state);
void	rra(t_state *state);

// Sort
void	radix(t_state *state);
void	small(t_state *state);

// Utils
int		is_sorted_asc(t_list *lst);
int		lst_index(t_list *lst, int val);
void	lst_sort(t_list *lst);
void	ft_move_toward(t_state *state, int n);

#endif