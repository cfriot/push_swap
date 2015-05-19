/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 15:11:34 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:28:37 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_magic *magic, int nb)
{
	t_lst *cursor;

	cursor = magic->begin_a;
	ft_putstr("Pile a : ");
	while (cursor)
	{
		ft_putnbr(cursor->key);
		ft_putstr(" ");
		cursor = cursor->next;
	}
	ft_putendl("");
	ft_putstr("Nombre de coup : ");
	ft_putnbr(nb);
	ft_putendl("");
}
