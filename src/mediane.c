/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:35:41 by dchane            #+#    #+#             */
/*   Updated: 2019/02/07 14:52:59 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		stk_len(t_stack *stk)
{
	int		len;

	len = 0;
	while (stk)
	{
		stk = stk->next;
		len++;
	}
	return (len);
}

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

int		partition(int *tab, int left, int right, int pivot)
{
	int		tmp;

	while (left <= right)
	{
		while (tab[left] < pivot)
			left++;
		while (tab[right] > pivot)
			right--;
		if (left <= right)
		{
			tmp = tab[left];
			tab[left] = tab[right];
			tab[right] = tmp;
			left++;
			right--;
		}
	}
	return (left);
}

void	quick_sort(int *tab, int left, int right)
{
	int		pivot;
	int		index;

	if (left >= right)
		return ;
	pivot = tab[(left + right) / 2];
	index = partition(tab, left, right, pivot);
	quick_sort(tab, left, index - 1);
	quick_sort(tab, index , right);
}

int		stk_mediane(t_stack *stk)
{
	int	*tab;
	int	len;

	len = stk_len(stk);
	tab = stk_to_tab(stk);
	quick_sort(tab, 0, len - 1);
	return (tab[(len / 2)]);
}
