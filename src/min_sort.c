/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:55:18 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/12 12:10:27 by mdchane          ###   ########.fr       */
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

void	sort_min(t_env *e)
{
	int		*mins;
	int		*maxs;
	int		nb;

	nb = stk_len(e->stk_a) / 40;
	while (e->stk_a)
	{
		mins = get_mins(e->stk_a, nb);
		maxs = get_maxs(e->stk_a, nb);
		while (!in_tab(maxs, e->stk_a->nbr, nb) && !in_tab(mins, e->stk_a->nbr, nb))
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "ra\n");
		}
		stk_push(&e->stk_a, &e->stk_b, 'b');
		lst_add_end(&e->buff, "pb\n");
		if (in_tab(maxs, e->stk_b->nbr, nb))
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'b');
			lst_add_end(&e->buff, "rb\n");
		}
	}
}
