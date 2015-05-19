/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 03:58:11 by cfriot            #+#    #+#             */
/*   Updated: 2015/02/15 04:21:28 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_overflow_min(char *nb)
{
	int		i;
	char	*min;

	min = "2147483648";
	i = 0;
	if (ft_strlen(nb) < 11)
		return (0);
	if (ft_strlen(nb) > 11)
		return (1);
	while (++i < ft_strlen(nb))
	{
		if (nb[i + 1] > min[i])
			return (1);
	}
	return (0);
}

int		ft_check_overflow_max(char *nb)
{
	int		i;
	char	*max;

	max = "2147483647";
	i = -1;
	if (ft_strlen(nb) < 10)
		return (0);
	if (ft_strlen(nb) > 10)
		return (1);
	while (++i < ft_strlen(nb))
	{
		if (nb[i] > max[i])
			return (1);
	}
	return (0);
}
