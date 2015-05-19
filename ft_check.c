/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 03:30:44 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 14:44:38 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_entry(int size, char **tab)
{
	if (ft_check_numbers(size, tab) == 1 || ft_check_double(size, tab) == 1 ||
			ft_check_overflow(size, tab) == 1)
		return (0);
	else
		return (1);
}

int		ft_check_numbers(int size, char **tab)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strcmp("-p", tab[1]) == 0)
		i++;
	while (++i < size)
	{
		j = -1;
		while (++j < ft_strlen(tab[i]))
		{
			if (j == 0 && tab[i][0] == '-')
				j++;
			if (!tab[i][j] || tab[i][j] < '0' || tab[i][j] > '9')
				return (1);
		}
	}
	return (0);
}

int		ft_check_double(int size, char **tab)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strcmp("-p", tab[1]) == 0)
		i++;
	while (++i <= size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (ft_strcmp(tab[i], tab[j]) == 0)
				return (1);
		}
	}
	return (0);
}

int		ft_check_overflow(int size, char **tab)
{
	int		i;

	i = 0;
	if (ft_strcmp("-p", tab[1]) == 0)
		i++;
	while (++i < size)
	{
		if (tab[i][0] == '-')
		{
			if (ft_check_overflow_min(tab[i]) == 1)
				return (1);
		}
		else
		{
			if (ft_check_overflow_max(tab[i]) == 1)
				return (1);
		}
	}
	return (0);
}
