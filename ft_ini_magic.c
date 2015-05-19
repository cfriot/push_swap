/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini_magic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 19:41:04 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:17:34 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_ini_magic(t_magic *magic, char **tab, int size)
{
	magic->size_b = 0;
	if (ft_strcmp(tab[0], "-p") == 0)
	{
		magic->size_a = size - 1;
		magic->p = 1;
		magic->begin_a = ft_create_list(tab[1]);
		magic->begin_a = ft_add_list(&tab[1], size - 1, magic->begin_a);
	}
	else
	{
		magic->size_a = size;
		magic->p = 0;
		magic->begin_a = ft_create_list(tab[0]);
		magic->begin_a = ft_add_list(tab, size, magic->begin_a);
	}
	magic->begin_b = NULL;
	magic->path = ft_strnew(1);
}

t_lst		*ft_create_list(char *str)
{
	t_lst	*tmp;

	tmp = (t_lst *)malloc(sizeof(t_lst));
	tmp->key = ft_atoi(str);
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

t_lst		*ft_add_list(char **tab, int size, t_lst *begin)
{
	int		i;
	t_lst	*cursor;
	t_lst	*previous;

	cursor = begin;
	i = 0;
	while (++i < size)
	{
		cursor->next = ft_create_list(tab[i]);
		cursor = cursor->next;
	}
	cursor = begin->next;
	previous = begin;
	while (cursor->next)
	{
		cursor->previous = previous;
		cursor = cursor->next;
		previous = previous->next;
	}
	cursor->previous = previous;
	return (begin);
}
