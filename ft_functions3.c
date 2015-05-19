/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:23:21 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/03 18:48:00 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_etat *etat)
{
	int		i;
	int		tmp;

	i = etat->size_a - 1;
	if (etat->size_a > 1)
	{
		tmp = etat->a[i];
		while (i >= 1)
		{
			etat->a[i] = etat->a[i - 1];
			i--;
		}
		etat->a[0] = tmp;
	}
	ft_update_path(etat, "rra ");
}

void	ft_rrb(t_etat *etat)
{
	int		i;
	int		tmp;

	i = etat->size_b - 1;
	if (etat->size_b > 1)
	{
		tmp = etat->b[i];
		while (i >= 1)
		{
			etat->b[i] = etat->b[i - 1];
			i--;
		}
		etat->b[0] = tmp;
	}
	ft_update_path(etat, "rrb ");
}

void	ft_rrr(t_etat *etat)
{
	char	*tmp;

	ft_rra(etat);
	ft_rrb(etat);
	tmp = ft_strsub(etat->path, 0, ft_strlen(etat->path) - 8);
	free(etat->path);
	etat->path = ft_strdup(tmp);
	free(tmp);
	ft_update_path(etat, "rrr ");
}
