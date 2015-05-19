/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 19:11:43 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/04 17:16:19 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*ft_go_to_end(t_lst *begin)
{
	while (begin->next)
		begin = begin->next;
	return (begin);
}

void	ft_pb_list(t_magic *magic)
{
	t_lst	*tmp;

	tmp = magic->begin_a;
	if (tmp)
	{
		magic->begin_a = tmp->next;
		if (magic->begin_a)
			magic->begin_a->previous = NULL;
		tmp->next = magic->begin_b;
		if (magic->begin_b)
			magic->begin_b->previous = tmp;
		magic->begin_b = tmp;
		tmp->previous = NULL;
		magic->size_b++;
		magic->size_a--;
		if (magic->size_a == 0)
			magic->begin_a = NULL;
	}
}

void	ft_pa_list(t_magic *magic)
{
	t_lst	*tmp;

	tmp = magic->begin_b;
	if (tmp)
	{
		magic->begin_b = tmp->next;
		if (magic->begin_b)
			magic->begin_b->previous = NULL;
		tmp->next = magic->begin_a;
		if (magic->begin_a)
			magic->begin_a->previous = tmp;
		magic->begin_a = tmp;
		tmp->previous = NULL;
		magic->size_b--;
		magic->size_a++;
		if (magic->size_b == 0)
			magic->begin_b = NULL;
	}
}

void	ft_ra_list(t_magic *magic)
{
	t_lst		*tmp;
	t_lst		*cursor;

	cursor = NULL;
	tmp = magic->begin_a;
	if (tmp)
	{
		magic->begin_a = tmp->next;
		if (magic->begin_a)
			magic->begin_a->previous = NULL;
		cursor = ft_go_to_end(magic->begin_a);
		cursor->next = tmp;
		tmp->previous = cursor;
		tmp->next = NULL;
	}
}

void	ft_rra_list(t_magic *magic)
{
	t_lst		*tmp;

	tmp = magic->begin_a;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
	{
		if (tmp->previous)
			tmp->previous->next = NULL;
		tmp->previous = NULL;
		tmp->next = magic->begin_a;
		magic->begin_a->previous = tmp;
		magic->begin_a = tmp;
	}
}
