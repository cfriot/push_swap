/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 02:08:40 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:24:36 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_etat **begin)
{
	t_etat	*cursor;
	int		i;

	i = 0;
	cursor = *begin;
	while (cursor->next)
	{
		i++;
		ft_print_state(cursor);
		cursor = cursor->next;
	}
	ft_print_state(cursor);
	ft_putendl("");
}
