/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_entry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/03 14:47:58 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:15:17 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_back(t_magic *magic, int nb)
{
	int			i;
	t_tablst	*tab;

	i = 0;
	tab = ft_get_functions_lst();
	while (magic->size_b > 0)
	{
		(*tab[0])(&(*magic));
		nb++;
		if (magic->size_b != 0)
			write(1, "pa ", 3);
		else
			write(1, "pa\n", 3);
	}
	if (magic->p)
		ft_print(magic, nb);
}

int		ft_make_left(t_magic *magic, int nb, t_min min)
{
	int			i;
	t_tablst	*tab;

	tab = ft_get_functions_lst();
	i = -1;
	while (++i < min.indice)
	{
		(*tab[2])(&(*magic));
		write(1, "ra ", 4);
		nb++;
	}
	(*tab[1])(&(*magic));
	write(1, "pb ", 3);
	nb++;
	return (nb);
}

int		ft_make_right(t_magic *magic, int nb, t_min min)
{
	int			i;
	int			y;
	t_tablst	*tab;

	tab = ft_get_functions_lst();
	y = magic->size_a - min.indice;
	i = -1;
	while (++i < y)
	{
		(*tab[3])(&(*magic));
		write(1, "rra ", 4);
		nb++;
	}
	(*tab[1])(&(*magic));
	write(1, "pb ", 3);
	nb++;
	return (nb);
}

int		ft_parse(t_magic *magic, int nb, t_min min)
{
	if (min.indice <= magic->size_a / 2)
		nb = ft_make_left(magic, nb, min);
	else
		nb = ft_make_right(magic, nb, min);
	return (nb);
}

void	ft_long_entry(t_magic *magic, int nb)
{
	t_min		min;
	int			i;
	t_lst		*cursor;

	min.key = 2147483647;
	cursor = magic->begin_a;
	i = -1;
	if (magic->size_a > 0)
	{
		while (++i < magic->size_a && cursor)
		{
			if (min.key >= cursor->key)
			{
				min.key = cursor->key;
				min.indice = i;
			}
			cursor = cursor->next;
		}
		nb = ft_parse(magic, nb, min);
		ft_long_entry(magic, nb);
	}
	else
		ft_push_back(magic, nb);
}
