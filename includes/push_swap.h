/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:57:37 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/14 15:49:32 by tjolivea         ###   ########.fr       */
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

// Put util
void	ft_putstate(t_state *state);

// Checker functions
int	multi_argv(char **argv);
int	single_argv(char **argv);

// Parsing
void	parse_argv(t_state *state, char **argv, int single);

// Operations
void	sa(t_state *state);
void	sb(t_state *state);
void	ss(t_state *state);
void	pa(t_state *state);
void	pb(t_state *state);

#endif