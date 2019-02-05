/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchane <dchane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:27:20 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/05 15:22:29 by dchane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_H
# define LIBPUSH_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# define BUFF_SIZE 32

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_env
{
	t_stack			*stk_a;
	t_stack			*stk_b;
	t_list			*buff;
}					t_env;


void				error(t_env *e);

void				init_stack(t_env *e, int argc, char **argv);
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

int					stk_len(t_stack *stk);
int					*stk_to_tab(t_stack *stk);
void				 tri_rapide (int *tableau, int taille);
void 				print_tab(int *tab, int taille);

#endif
