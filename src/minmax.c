/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:58:07 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/18 14:03:20 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		*stk_to_tab(t_stack *stk)
{
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * stk_len(stk));
	i = 0;
	while(stk)
	{
		tab[i] = stk->nbr;
		stk = stk->next;
		i++;
	}
	return (tab);
}


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
