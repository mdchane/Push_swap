/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:43 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/18 11:43:05 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void command_buff2(t_env *e, char *command, char c)
{
	if (ft_strcmp(command, "stk_rotate") == 0)
	{
		stk_rotate(&e->a, &e->b, c);
		if (c == 'a')
			lst_add_end(&e->buff, "ra\n");
		else
			lst_add_end(&e->buff, "rb\n");
	}
	else if ((ft_strcmp(command, "stk_rev_rotate") == 0))
	{
		stk_rev_rotate(&e->a, &e->b, c);
		if (c == 'a')
			lst_add_end(&e->buff, "rra\n");
		else
			lst_add_end(&e->buff, "rrb\n");
	}
	else
		exit(1);
}

void command_buff(t_env *e, char *command, char c)
{
	if (ft_strcmp(command, "stk_swap") == 0)
	{
		stk_swap(e->a, e->b, c);
		if (c == 'a')
			lst_add_end(&e->buff, "sa\n");
		else
			lst_add_end(&e->buff, "sb\n");
	}
	else if (ft_strcmp(command, "stk_push") == 0)
	{
		stk_push(&e->a, &e->b, c);
		if (c == 'a')
			lst_add_end(&e->buff, "pa\n");
		else
			lst_add_end(&e->buff, "pb\n");
	}
	else
		command_buff2(e, command, c);
}
