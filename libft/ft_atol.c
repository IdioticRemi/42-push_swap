/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjolivea <tjolivea@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:33:24 by tjolivea          #+#    #+#             */
/*   Updated: 2022/01/17 10:35:36 by tjolivea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	x;
	int		sign;

	x = 0;
	sign = 1;
	while (*nptr && ((*nptr >= 9 && *nptr <= 13) || *nptr == ' '))
		nptr++;
	if (*nptr && !ft_isdigit(*nptr))
	{
		sign *= ((*nptr == '+') * 1) + ((*nptr == '-') * -1);
		nptr++;
	}
	while (*nptr && ft_isdigit(*nptr))
		x = x * 10 + (*nptr++ - '0');
	return (sign * x);
}
