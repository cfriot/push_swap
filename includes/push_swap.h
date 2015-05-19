/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfriot <cfriot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 07:00:02 by cfriot            #+#    #+#             */
/*   Updated: 2015/04/05 15:14:39 by cfriot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_etat
{
	int				*a;
	int				*b;
	int				size_a;
	int				size_b;
	char			*path;
	struct s_etat	*next;
	int				p;
}					t_etat;

typedef struct		s_lst
{
	int				key;
	struct s_lst	*next;
	struct s_lst	*previous;
}					t_lst;

typedef struct		s_magic
{
	int				size_a;
	int				size_b;
	t_lst			*begin_a;
	t_lst			*begin_b;
	char			*path;
	int				p;
}					t_magic;

typedef struct		s_min
{
	int				key;
	int				indice;
}					t_min;

typedef void		(*t_tablst)(t_magic *magic);
typedef void		(*t_tabptr)(t_etat *etat);
t_tabptr			*ft_get_functions();
t_tablst			*ft_get_functions_lst();
t_etat				*ft_cpy_state(t_etat *etat);
t_lst				*ft_add_list(char **tab, int size, t_lst *begin);
t_lst				*ft_create_list(char *str);
void				ft_useless(t_etat *etat);
void				ft_print(t_magic *magic, int nb);
void				ft_sa(t_etat *etat);
void				ft_sb(t_etat *etat);
void				ft_ss(t_etat *etat);
void				ft_pa(t_etat *etat);
void				ft_pb(t_etat *etat);
void				ft_ra(t_etat *etat);
void				ft_rb(t_etat *etat);
void				ft_rr(t_etat *etat);
void				ft_rra(t_etat *etat);
void				ft_rrb(t_etat *etat);
void				ft_rrr(t_etat *etat);
void				ft_pb_list(t_magic *magic);
void				ft_pb_bis(t_magic *magic);
void				ft_pa_list(t_magic *magic);
void				ft_pa_bis(t_magic *magic);
void				ft_ra_list(t_magic *magic);
void				ft_rra_list(t_magic *magic);
void				ft_add_to_lst(t_etat *etat, t_etat **begin);
void				ft_clear(t_etat *etat);
void				ft_clear_list(t_etat **begin);
void				ft_create_state(t_etat *etat);
void				ft_print_state(t_etat *etat);
void				ft_print_tab_int(int *tab, int size);
void				ft_print_list(t_etat **begin);
void				ft_update_path(t_etat *etat, char *to_add);
void				ft_update_path_magic(t_magic *magic, char *to_add);
void				ft_long_entry(t_magic *magic, int nb);
void				ft_do_magic(char **av, int ac);
void				ft_ini_magic(t_magic *magic, char **tab, int size);
int					*ft_tabcpy_atoi(char **tab, int size);
int					*ft_tabcpy(int *tab, int size);
int					*ft_merge_tab(int *tab_a, int size);
int					ft_tab_is_sorted(int *tab_a, int size);
int					ft_tabcmp(int *tab1, int *tab2, int size);
int					ft_test_exist(t_etat *etat, t_etat **begin);
int					ft_apply_functions(t_etat *to_test, t_etat **begin);
int					ft_check_entry(int size, char **tab);
int					ft_check_numbers(int size, char **tab);
int					ft_check_double(int size, char **tab);
int					ft_check_overflow(int size, char **tab);
int					ft_check_overflow_min(char *nb);
int					ft_check_overflow_max(char *nb);
#endif
