/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:27:20 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/20 12:44:13 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_H
# define LIBPUSH_H
# include "libft/libft.h"

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_env
{
	t_stack			*a;
	t_stack			*b;
	t_list			*buff;
}					t_env;


void				error(t_env *e);

void				init_e(t_env **e, int argc, char **argv);
void				stk_add_begin(t_stack **stk, int nbr);
void				stk_doublon(t_env *e, t_stack *stk, int nbr);
int					is_zero(char *str);

void				read_commands(t_env *e);
void				lst_add_end(t_list **lst, char *str);
void				is_command(t_env *e, char *str);

void				stk_swap(t_stack *a, t_stack *b, char c);
void				stk_push(t_stack **a, t_stack **b, char c);
void				stk_rotate(t_stack **a, t_stack **b, char c);
void				stk_rev_rotate(t_stack **a, t_stack **b, char c);
void				run_checker(t_env *e);

int					stk_is_sorted(t_stack *a, t_stack *b);

void				print_stack(t_stack *a, t_stack *b);
void				print_buff(t_list *buff);
void				stk_del(t_stack **stk);
void				free_all(t_env *e);
int					tab_len(char **tab);

int					stk_len(t_stack *stk);
int					*stk_to_tab(t_stack *stk);
void				tri_rapide (int *tableau, int taille);
void				print_tab(int *tab, int taille);
void				quick_sort(int *tab, int left, int right);
int					stk_mediane(t_stack *stk);
void 				command_buff(t_env *e, char *command, char c);

int					stk_min(t_stack *stk);
int					stk_posmin(t_stack *stk);
int					stk_max(t_stack *stk);
int					stk_posmax(t_stack *stk);
int					stk_posmax2(t_stack *stk, int *maxs);

int					*get_mins(t_stack *stk, int nb);
int					*get_maxs(t_stack *stk, int	nb);
int					in_tab(int *tab, int nb, int len);
void				sort_two(t_env *e);
void				sort_three(t_env *e);
void				sort_less_five(t_env *e);
int					first_pos_maxmin(t_stack *stk, int *mins, int *maxs, int nb);
void				sort_min(t_env *e);
void				sort(t_env *e);
void				optimize_buff(t_env *e);

#endif
