/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:27:20 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/31 10:09:42 by mdchane          ###   ########.fr       */
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


void				error();
int					get_next_line(const int fd, char **line);

void				stk_add_begin(t_stack **stk, int nbr);
void				stk_doublon(t_stack *stk, int nbr);
int					is_zero(char *str);

void				read_commands(t_env *e);
void				lst_add_end(t_list **lst, char *str);
void				is_command(char *str);

void				stk_swap(t_stack *a, t_stack *b, char c);
void				run_checker(t_env *e);

void				print_stack(t_stack *a, t_stack *b);
void				print_buff(t_list *buff);
void				free_all(t_env *e);

#endif
