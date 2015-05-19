/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:03:20 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/03 18:24:52 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_etat *etat)
{
	int		tmp;

	if (etat->size_a >= 2)
	{
		tmp = etat->a[0];
		etat->a[0] = etat->a[1];
		etat->a[1] = tmp;
	}
	ft_update_path(etat, "sa ");
}

void	ft_sb(t_etat *etat)
{
	int		tmp;

	if (etat->size_b >= 2)
	{
		tmp = etat->b[0];
		etat->b[0] = etat->b[1];
		etat->b[1] = tmp;
	}
	ft_update_path(etat, "sb ");
}

void	ft_ss(t_etat *etat)
{
	char	*tmp;

	ft_sa(etat);
	ft_sb(etat);
	tmp = ft_strsub(etat->path, 0, ft_strlen(etat->path) - 6);
	free(etat->path);
	etat->path = ft_strdup(tmp);
	free(tmp);
	ft_update_path(etat, "ss ");
}

void	ft_pb(t_etat *etat)
{
	int		i;
	int		*cpy;

	i = -1;
	cpy = malloc(sizeof(int) * etat->size_b + etat->size_a);
	if (etat->size_a >= 1)
	{
		while (++i < etat->size_b)
			cpy[i + 1] = etat->b[i];
		cpy[0] = etat->a[0];
		i = -1;
		while (++i < etat->size_a)
			etat->a[i] = etat->a[i + 1];
		etat->size_a--;
		etat->size_b++;
		free(etat->b);
		etat->b = cpy;
		ft_update_path(etat, "pb ");
	}
}

void	ft_pa(t_etat *etat)
{
	int		i;
	int		*cpy;

	i = -1;
	cpy = malloc(sizeof(int) * etat->size_a + etat->size_b);
	if (etat->size_b >= 1)
	{
		while (++i < etat->size_a)
			cpy[i + 1] = etat->a[i];
		cpy[0] = etat->b[0];
		i = -1;
		while (++i < etat->size_b)
			etat->b[i] = etat->b[i + 1];
		etat->size_a++;
		etat->size_b--;
		free(etat->a);
		etat->a = cpy;
		ft_update_path(etat, "pa ");
	}
}
