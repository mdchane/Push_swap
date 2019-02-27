/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:35:41 by dchane            #+#    #+#             */
/*   Updated: 2019/02/27 09:47:33 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	command_buff2(t_env *e, char *command, char c)
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

void	command_buff(t_env *e, char *command, char c)
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

void	optimize_buff(t_env *e)
{
	t_list	*tmp;
	t_list	*beg;

	beg = e->buff;
	while (e->buff)
	{
		if (ft_strcmp(e->buff->content, "rb\n") == 0
			&& ft_strcmp(e->buff->next->content, "ra\n") == 0)
		{
			ft_memcpy(e->buff->content, "rr\n", 3);
			tmp = e->buff->next;
			e->buff->next = e->buff->next->next;
			ft_lstdelone(&tmp);
		}
		e->buff = e->buff->next;
	}
	e->buff = beg;
}
