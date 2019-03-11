/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:58:07 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/04 13:12:12 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		*stk_to_tab(t_stack *stk)
{
	int		*tab;
	int		i;
	int		len;

	len = stk_len(stk);
	tab = (int *)ft_memalloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		tab[i] = stk->nbr;
		stk = stk->next;
		i++;
	}
	return (tab);
}

int		*get_mins(t_stack *stk, int nb)
{
	int		*mins;
	int		*tab;
	int		len;

	len = stk_len(stk);
	tab = stk_to_tab(stk);
	quick_sort(tab, 0, len - 1);
	mins = (int *)ft_memalloc(sizeof(int) * nb);
	while (--nb >= 0)
	{
		mins[nb] = tab[nb];
	}
	ft_memdel((void **)&tab);
	return (mins);
}

int		*get_maxs(t_stack *stk, int nb)
{
	int		*maxs;
	int		*tab;
	int		len;

	len = stk_len(stk);
	tab = stk_to_tab(stk);
	quick_sort(tab, 0, len - 1);
	maxs = (int *)ft_memalloc(sizeof(int) * nb);
	while (--nb >= 0)
	{
		maxs[nb] = tab[len - nb - 1];
	}
	ft_memdel((void **)&tab);
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

int		stk_posmax2(t_stack *stk, int *maxs)
{
	int		posmax1;
	int		posmax2;
	int		len;
	t_stack	*tmp;

	len = stk_len(stk);
	posmax1 = 0;
	posmax2 = 0;
	tmp = stk;
	while (stk && stk->nbr != maxs[0])
	{
		posmax1++;
		stk = stk->next;
	}
	while (tmp && tmp->nbr != maxs[1])
	{
		posmax2++;
		tmp = tmp->next;
	}
	if (posmax1 < posmax2 || (len - posmax1) < (len - posmax2))
		return (posmax1);
	else
		return (posmax2);
}
