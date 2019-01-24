/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:27:20 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/24 16:31:32 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSH_H
# define LIBPUSH_H
# include "get_next_line.h"

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




t_stack				*stk_add_begin(t_stack *stk, int nbr);
t_list				*lst_add_end(t_list *lst, char *str);
void				print_stack(t_stack *stk);
void				print_buff(t_list *buff);
int					is_zero(char *str);

#endif
