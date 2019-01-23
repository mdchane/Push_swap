/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:27:20 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/23 13:45:41 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

typedef struct		s_stack
{
	int				nbr;
	struct s_stack	*next;
}					t_stack;


t_stack				*stk_add_begin(t_stack *stk, int nbr);

int					is_zero(char *str);
