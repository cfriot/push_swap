/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:45 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:10:22 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_tabcpy_atoi(char **tab, int size)
{
	int		i;
	int		j;
	int		*cpy;

	i = -1;
	if (ft_strcmp(tab[0], "-p") == 0)
		i++;
	cpy = malloc(sizeof(int) * size);
	j = 0;
	while (++i < size)
	{
		cpy[j] = ft_atoi(tab[i]);
		j++;
	}
	return (cpy);
}

int		ft_tab_is_sorted(int *tab_a, int size)
{
	static int	*merged_tab;
	static int	merged_size;
	int			i;

	if (!merged_tab)
	{
		merged_tab = ft_merge_tab(ft_tabcpy(tab_a, size), size);
		merged_size = size;
	}
	if (merged_size == size)
	{
		i = 0;
		while (merged_tab[i] == tab_a[i] && i < size)
			i++;
		return (i == size ? 1 : 0);
	}
	else
		return (0);
}

int		ft_tabcmp(int *tab1, int *tab2, int size)
{
	int		i;

	i = 0;
	while (tab1[i] == tab2[i] && i < size)
		i++;
	if (i == size)
		return (1);
	else
		return (0);
}

int		*ft_tabcpy(int *tab, int size)
{
	int		i;
	int		*cpy;

	i = -1;
	cpy = malloc(sizeof(int) * size);
	while (++i < size)
		cpy[i] = tab[i];
	return (cpy);
}
