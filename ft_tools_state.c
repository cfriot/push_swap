/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:46:52 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:25:27 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_etat		*ft_cpy_state(t_etat *etat)
{
	t_etat		*cpy;

	cpy = malloc(sizeof(t_etat));
	if (cpy)
	{
		cpy->size_a = etat->size_a;
		cpy->size_b = etat->size_b;
		cpy->a = ft_tabcpy(etat->a, etat->size_a);
		cpy->b = ft_tabcpy(etat->b, etat->size_b);
		cpy->path = ft_strdup(etat->path);
		cpy->next = NULL;
		cpy->p = etat->p;
		return (cpy);
	}
	return (NULL);
}

int			ft_test_exist(t_etat *etat, t_etat **begin)
{
	t_etat		*cursor;

	cursor = *begin;
	while (cursor)
	{
		if (etat->size_a == cursor->size_a && etat->size_b == cursor->size_b)
		{
			if (ft_tabcmp(etat->a, cursor->a, cursor->size_a) == 1 &&
					ft_tabcmp(etat->b, cursor->b, cursor->size_b) == 1)
				return (1);
		}
		cursor = cursor->next;
	}
	return (0);
}

void		ft_add_to_lst(t_etat *etat, t_etat **begin)
{
	t_etat		*cursor;

	cursor = *begin;
	while (cursor->next)
		cursor = cursor->next;
	if (etat)
		cursor->next = etat;
}

void		ft_print_state(t_etat *etat)
{
	ft_putstr("pile a : ");
	ft_print_tab_int(etat->a, etat->size_a);
	ft_putstr("pile b : ");
	ft_print_tab_int(etat->b, etat->size_b);
	ft_putstr("size a : ");
	ft_putnbr(etat->size_a);
	ft_putendl("");
	ft_putstr("size b : ");
	ft_putnbr(etat->size_b);
	ft_putendl("");
	etat->p = 0;
	ft_useless(etat);
}

void		ft_print_tab_int(int *tab, int size)
{
	int			i;

	i = -1;
	while (++i < size)
	{
		ft_putnbr(tab[i]);
		ft_putstr("   ");
	}
	ft_putstr("\n");
}
