/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:43 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/06 17:07:19 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int	stk_getnum(t_stack *stk, int n)
{
	while (n > 0)
	{
		stk = stk->next;
		n--;
	}
	return (stk->nbr);
}

int		partition(t_env *e, int left, int right, int pivot)
{
	while (left <= right)
	{
		while (stk_getnum(e->stk_a, left) < pivot)
			left++;
		while (stk_getnum(e->stk_a, right) > pivot)
			right--;
		if
	}
}


void	quick_sort(t_env *e, int left, int right)
{
	int		pivot;
	int		index;

	if (left >= right)
	return ;
	pivot = stk_mediane(e->stk_a);
	index = partition(e, left, right, pivot);
	quick_sort(e, left, index - 1);
	quick_sort(e, index , right);
}
