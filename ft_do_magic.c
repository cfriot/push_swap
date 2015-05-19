/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_magic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 20:28:11 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/04 20:28:28 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tablst	*ft_get_functions_lst(void)
{
	static t_tablst	tab[4];

	if (!tab[0])
	{
		tab[0] = ft_pa_list;
		tab[1] = ft_pb_list;
		tab[2] = ft_ra_list;
		tab[3] = ft_rra_list;
	}
	return (tab);
}

void		ft_do_magic(char **av, int ac)
{
	t_magic		magic;

	ft_ini_magic(&magic, &av[1], ac - 1);
	ft_long_entry(&magic, 0);
}
