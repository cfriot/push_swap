/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 04:52:38 by cfriot            #+#    #+#             */
/*   Updated: 2015/02/15 03:18:02 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_clear(t_etat *etat)
{
	free(etat->path);
	free(etat->a);
	free(etat->b);
	free(etat);
}

void		ft_clear_list(t_etat **begin)
{
	t_etat	*cursor;
	t_etat	*next;

	cursor = *begin;
	if (cursor->next)
		next = cursor->next;
	while (cursor->next && cursor->next->next)
	{
		ft_clear(cursor);
		cursor = next;
		if (next->next)
			next = next->next;
	}
}
