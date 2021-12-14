/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:07:18 by tjolivea          #+#    #+#             */
/*   Updated: 2021/12/14 16:12:55 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	multi_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv && argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_strchr("0123456789+-", argv[i][j]))
				return (0);
			if (argv[i][0] == '+' || argv[i][0] == '-')
				if (!argv[i][1] || !ft_isdigit(argv[i][1]))
					return (0);
		}
	}
	return (1);
}

int	single_argv(char **argv)
{
	int	i;

	i = -1;
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789+- ", argv[1][i]))
			return (0);
		if (ft_strchr("+-", argv[1][i]))
			if (!argv[1][i + 1] || !ft_isdigit(argv[1][i + 1]))
				return (0);
		if (argv[1][i] == ' ')
			if (!argv[1][i + 1] || !ft_strchr("0123456789+-", argv[1][i + 1]))
				return (0);
	}
	return (1);
}
