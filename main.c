/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:08:44 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:23:51 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_useless(t_etat *etat)
{
	int				i;

	if (etat->p == 1)
		ft_print_state(etat);
	else
	{
		i = ft_strlen(etat->path) - 1;
		write(1, etat->path, i);
		write(1, "\n", 1);
	}
}

t_tabptr	*ft_get_functions(void)
{
	static t_tabptr	tab[11];

	if (!tab[0])
	{
		tab[0] = ft_sa;
		tab[1] = ft_sb;
		tab[2] = ft_ss;
		tab[3] = ft_pa;
		tab[4] = ft_pb;
		tab[5] = ft_ra;
		tab[6] = ft_rb;
		tab[7] = ft_rr;
		tab[8] = ft_rra;
		tab[9] = ft_rrb;
		tab[10] = ft_rrr;
	}
	return (tab);
}

int			ft_apply_functions(t_etat *to_test, t_etat **begin)
{
	int				i;
	t_etat			*cpy;
	t_tabptr		*tab;

	tab = ft_get_functions();
	i = -1;
	while (++i < 11)
	{
		cpy = ft_cpy_state(to_test);
		(*tab[i])(&(*cpy));
		if (cpy)
		{
			if (ft_tab_is_sorted(cpy->a, cpy->size_a) == 1)
			{
				ft_useless(cpy);
				return (1);
			}
			else if (cpy->size_a >= (cpy->size_a + cpy->size_b) / 2 &&
					ft_test_exist(cpy, begin) == 0)
				ft_add_to_lst(cpy, begin);
			else
				ft_clear(cpy);
		}
	}
	return (0);
}

void		ft_create_state(t_etat *etat)
{
	int				flag;
	t_etat			*begin;

	begin = etat;
	flag = 0;
	if (ft_tab_is_sorted(etat->a, etat->size_a) == 0)
	{
		while (!flag && etat)
		{
			flag = ft_apply_functions(etat, &begin);
			if (flag == 0)
				etat = etat->next;
			else
				ft_clear_list(&begin);
		}
	}
	else
		ft_putendl(etat->path);
}

int			main(int ac, char **av)
{
	t_etat			*etat_ini;

	if (ac > 1 && ft_check_entry(ac, av) == 1)
	{
		if (ac <= 9)
		{
			etat_ini = malloc(sizeof(t_etat));
			etat_ini->a = ft_tabcpy_atoi(&av[1], ac - 1);
			etat_ini->b = malloc(sizeof(int) * ac);
			ft_strcmp("-p", av[1]) == 0 ? etat_ini->size_a = ac - 2 : ac--;
			ft_strcmp("-p", av[1]) != 0 ? etat_ini->size_a = ac : ft_putstr("");
			ft_strcmp("-p", av[1]) == 0 ? etat_ini->p = 1 : ft_putstr("");
			ft_strcmp("-p", av[1]) != 0 ? etat_ini->p = 0 : ft_putstr("");
			etat_ini->size_b = 0;
			etat_ini->path = ft_strnew(1);
			etat_ini->next = NULL;
			ft_create_state(etat_ini);
		}
		else
			ft_do_magic(av, ac);
	}
	else if (ac > 1)
		ft_putendl("Error");
	return (0);
}
