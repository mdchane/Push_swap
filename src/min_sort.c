/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:55:18 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/12 14:56:52 by mdchane          ###   ########.fr       */
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
	mins = get_mins(e->stk_a, nb);
	maxs = get_maxs(e->stk_a, nb);
	while (e->stk_a)
	{
		mins = get_mins(e->stk_a, nb);
		maxs = get_maxs(e->stk_a, nb);
		// if (first_pos_maxmin(e->stk_a, mins, maxs, nb) == 0)
			while (!in_tab(maxs, e->stk_a->nbr, nb) && !in_tab(mins, e->stk_a->nbr, nb))
			{
				stk_rotate(&e->stk_a, &e->stk_b, 'a');
				lst_add_end(&e->buff, "ra\n");
			}
		// else
		// 	while (!in_tab(maxs, e->stk_a->nbr, nb) && !in_tab(mins, e->stk_a->nbr, nb))
		// 	{
		// 		stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
		// 		lst_add_end(&e->buff, "rra\n");
		// 	}
		stk_push(&e->stk_a, &e->stk_b, 'b');
		lst_add_end(&e->buff, "pb\n");
		if (in_tab(maxs, e->stk_b->nbr, nb))
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'b');
			lst_add_end(&e->buff, "rb\n");
		}
	}
}

void	re_push(t_env *e)
{
	while (e->stk_b)
	{
		if (stk_posmax(e->stk_b) < stk_len(e->stk_b) / 2)
			while (e->stk_b->nbr != stk_max(e->stk_b))
			{
				stk_rotate(&e->stk_a, &e->stk_b, 'b');
				lst_add_end(&e->buff, "rb\n");
			}
		else
			while (e->stk_b->nbr != stk_max(e->stk_b))
			{
				stk_rev_rotate(&e->stk_a, &e->stk_b, 'b');
				lst_add_end(&e->buff, "rrb\n");
			}
		stk_push(&e->stk_a, &e->stk_b, 'a');
		lst_add_end(&e->buff, "pa\n");
	}
}

void	sort_min(t_env *e)
{
	int		*mins;
	int		*maxs;
	int		nb;

	mins = NULL;
	maxs = NULL;
	nb = stk_len(e->stk_a) / 40;
	nb = (nb == 0) ? 1 : nb;
	push_maxs_mins(e, mins, maxs, nb);
	re_push(e);
}
