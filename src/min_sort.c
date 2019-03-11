/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:55:18 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/04 16:49:58 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int			best_nb(int len)
{
	int	nb;

	if (len < 50)
		nb = 1 + len / 10;
	else if (len < 100)
		nb = 2 + len / 10;
	else if (len < 150)
		nb = 8 + len / 100;
	else if (len < 300)
		nb = 12 + len / 100;
	else
		nb = 13 + len / 100;
	nb = (nb == 0) ? 1 : nb;
	return (nb);
}

void		push_maxs_mins(t_env *e, int *mins, int *maxs)
{
	int		nb;

	while (e->a)
	{
		nb = best_nb(stk_len(e->a));
		mins = get_mins(e->a, nb);
		maxs = get_maxs(e->a, nb);
		while (!in_tab(maxs, e->a->nbr, nb) && !in_tab(mins, e->a->nbr, nb))
			command_buff(e, "stk_rotate", 'a');
		command_buff(e, "stk_push", 'b');
		if (in_tab(maxs, e->b->nbr, nb))
			command_buff(e, "stk_rotate", 'b');
		ft_memdel((void **)&mins);
		ft_memdel((void **)&maxs);
	}
}

static void	re_smartpush(t_env *e, int *maxs, int i)
{
	if (i % 2 == 0)
	{
		if (stk_posmax2(e->b, maxs) < stk_len(e->b) / 2)
			while (!in_tab(maxs, e->b->nbr, 2))
				command_buff(e, "stk_rotate", 'b');
		else
			while (!in_tab(maxs, e->b->nbr, 2))
				command_buff(e, "stk_rev_rotate", 'b');
	}
	else
	{
		if (stk_posmax(e->b) < stk_len(e->b) / 2)
			while (e->b->nbr != stk_max(e->b))
				command_buff(e, "stk_rotate", 'b');
		else
			while (e->b->nbr != stk_max(e->b))
				command_buff(e, "stk_rev_rotate", 'b');
	}
}

void		re_push(t_env *e)
{
	int		*maxs;
	int		i;

	i = 0;
	while (stk_len(e->b) > 1)
	{
		maxs = get_maxs(e->b, 2);
		re_smartpush(e, maxs, i);
		i++;
		command_buff(e, "stk_push", 'a');
		if (stk_len(e->a) > 1)
			if (e->a->nbr > e->a->next->nbr)
				command_buff(e, "stk_swap", 'a');
		ft_memdel((void **)&maxs);
	}
	command_buff(e, "stk_push", 'a');
	if (stk_len(e->a) > 1)
		if (e->a->nbr > e->a->next->nbr)
			command_buff(e, "stk_swap", 'a');
}

void		sort_min(t_env *e)
{
	int		*mins;
	int		*maxs;

	mins = NULL;
	maxs = NULL;
	push_maxs_mins(e, mins, maxs);
	re_push(e);
}
