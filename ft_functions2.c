/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:17:23 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/03 18:50:16 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_etat *etat)
{
	int		i;
	int		tmp;

	i = 0;
	if (etat->size_a > 1)
	{
		tmp = etat->a[0];
		while (i < etat->size_a - 1)
		{
			etat->a[i] = etat->a[i + 1];
			i++;
		}
		etat->a[i] = tmp;
	}
	ft_update_path(etat, "ra ");
}

void	ft_rb(t_etat *etat)
{
	int		i;
	int		tmp;

	i = 0;
	if (etat->size_b > 1)
	{
		tmp = etat->b[0];
		while (i < etat->size_b - 1)
		{
			etat->b[i] = etat->b[i + 1];
			i++;
		}
		etat->b[i] = tmp;
	}
	ft_update_path(etat, "rb ");
}

void	ft_rr(t_etat *etat)
{
	char	*tmp;

	ft_ra(etat);
	ft_rb(etat);
	tmp = ft_strsub(etat->path, 0, ft_strlen(etat->path) - 6);
	free(etat->path);
	etat->path = ft_strdup(tmp);
	free(tmp);
	ft_update_path(etat, "rr ");
}
