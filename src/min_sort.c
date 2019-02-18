/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:55:18 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/18 11:28:44 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		*get_mins(t_stack *stk, int	nb)
{
	int		*mins;
	int		*tab;
	int		len;

	len = stk_len(stk);
	tab = stk_to_tab(stk);
	quick_sort(tab, 0, len - 1);
	mins = (int *)malloc(sizeof(int) * nb);
	while (--nb >= 0)
	{
		mins[nb] = tab[nb];
	}
	return (mins);
}

int		*get_maxs(t_stack *stk, int	nb)
{
	int		*maxs;
	int		*tab;
	int		len;

	len = stk_len(stk);
	tab = stk_to_tab(stk);
	quick_sort(tab, 0, len - 1);
	maxs = (int *)malloc(sizeof(int) * nb);
	while (--nb >= 0)
	{
		maxs[nb] = tab[len - nb - 1];
	}
	return (maxs);
}

int		in_tab(int *tab, int nb, int len)
{
	while (--len >= 0)
	{
		if (nb == tab[len])
			return (1);
	}
	return (0);
}

int		first_pos_maxmin(t_stack *stk, int *mins, int *maxs, int nb)
{
	int		*tab;
	int		i;
	int		j;
	int		len;

	len = stk_len(stk);
	tab = stk_to_tab(stk);
	i = 0;
	while (i < len)
	{
		if (in_tab(mins, tab[i], nb) || in_tab(maxs, tab[i], nb))
			break ;
		i++;
	}
	j = len - 1;
	while (j >= 0)
	{
		if (in_tab(mins, tab[j], nb) || in_tab(maxs, tab[j], nb))
			break ;
		j--;
	}
	if (i <= len - j)
		return (0);
	else
		return (1);
}

void	push_maxs_mins(t_env *e, int *mins, int *maxs, int nb)
{
	mins = get_mins(e->a, nb);
	maxs = get_maxs(e->a, nb);
	while (e->a)
	{
		mins = get_mins(e->a, nb);
		maxs = get_maxs(e->a, nb);
		// if (first_pos_maxmin(e->a, mins, maxs, nb) == 0)
		while (!in_tab(maxs, e->a->nbr, nb) && !in_tab(mins, e->a->nbr, nb))
			command_buff(e, "stk_rotate", 'a');
		// else
		// 	while (!in_tab(maxs, e->a->nbr, nb) && !in_tab(mins, e->a->nbr, nb))
		// 	{
		// 		stk_rev_rotate(&e->a, &e->b, 'a');
		// 		lst_add_end(&e->buff, "rra\n");
		// 	}
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
	nb = stk_len(e->a) / 40;
	nb = (nb == 0) ? 1 : nb;
	push_maxs_mins(e, mins, maxs, nb);
	re_push(e);
}
