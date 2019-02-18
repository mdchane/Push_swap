/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:55:18 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/18 15:40:30 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"



int		in_tab(int *tab, int nb, int len)
{
	while (--len >= 0)
	{
		if (nb == tab[len])
			return (1);
	}
	return (0);
}

void	push_maxs_mins(t_env *e, int *mins, int *maxs, int nb)
{
	mins = get_mins(e->a, nb);
	maxs = get_maxs(e->a, nb);
	while (e->a)
	{
		mins = get_mins(e->a, nb);
		maxs = get_maxs(e->a, nb);
		while (!in_tab(maxs, e->a->nbr, nb) && !in_tab(mins, e->a->nbr, nb))
			command_buff(e, "stk_rotate", 'a');
		command_buff(e, "stk_push", 'b');
		if (in_tab(maxs, e->b->nbr, nb))
			command_buff(e, "stk_rotate", 'b');
	}
}

void	re_push(t_env *e)
{
	while (e->b)
	{
		if (stk_posmax(e->b) < stk_len(e->b) / 2)
			while (e->b->nbr != stk_max(e->b))
				command_buff(e, "stk_rotate", 'b');
		else
			while (e->b->nbr != stk_max(e->b))
				command_buff(e, "stk_rev_rotate", 'b');
		command_buff(e, "stk_push", 'a');
	}
}

void	sort_min(t_env *e)
{
	int		*mins;
	int		*maxs;
	int		nb;

	mins = NULL;
	maxs = NULL;
	nb = stk_len(e->a) / 16;
	nb = (nb == 0) ? 1 : nb;
	push_maxs_mins(e, mins, maxs, nb);
	re_push(e);
}
