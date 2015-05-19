/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 02:29:43 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/03 19:32:34 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_update_path(t_etat *etat, char *to_add)
{
	char	*tmp;

	tmp = ft_strdup(etat->path);
	free(etat->path);
	etat->path = ft_strjoin(tmp, to_add);
	free(tmp);
}

void	ft_update_path_magic(t_magic *magic, char *to_add)
{
	char *tmp;

	tmp = ft_strdup(magic->path);
	free(magic->path);
	magic->path = ft_strjoin(tmp, to_add);
	free(tmp);
}
