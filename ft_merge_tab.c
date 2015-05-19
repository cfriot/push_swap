/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 18:37:45 by cfriot            #+#    #+#             */
/*   Updated: 2015/02/15 03:25:59 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_merge_tab(int *tab_a, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	j = 0;
	while (++i < size - 1)
	{
		while (++j < size)
		{
			if (tab_a[i] > tab_a[j])
			{
				tmp = tab_a[i];
				tab_a[i] = tab_a[j];
				tab_a[j] = tmp;
			}
		}
		j = i + 1;
	}
	return (tab_a);
}
