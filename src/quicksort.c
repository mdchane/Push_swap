/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:43 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/18 13:52:41 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

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
