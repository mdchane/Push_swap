/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:43 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/07 14:52:11 by mdchane          ###   ########.fr       */
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
void	push_mediane_to_b(t_env *e)
{
	int		med;

	med = stk_mediane(e->stk_a);
	while (stk_smallest(e->stk_a) < med)
	{
		if (e->stk_a->nbr < med)
		{
			stk_push(&e->stk_a, &e->stk_b, 'b');
			lst_add_end(&e->buff, "pb\n");
		}
		else
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "ra\n");
		}
	}
}

void	push_mediane_to_a(t_env *e)
{
	int		med;

	med = stk_mediane(e->stk_b);
	if (!e->stk_b)
		return ;
	while (stk_smallest(e->stk_b) < med)
	{
		if (e->stk_b->nbr < med)
		{
			stk_push(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "pa\n");
			stk_rotate(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "ra\n");
		}
		else
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'b');
			lst_add_end(&e->buff, "rb\n");
		}
	}
}

void	sort_med(t_env *e)
{
	int		i;

	i = -1;
	while (++i < 5)
	{
		print_stack(e->stk_a, e->stk_b);
		push_mediane_to_b(e);
	}
}

// int		partition(t_env *e, int left, int right, int pivot)
// {
// 	if ()
// }


// void	quick_sort(t_env *e, int left, int right)
// {
// 	int		pivot;
// 	int		index;

// 	if (left >= right)
// 		return ;
// 	pivot = stk_mediane(e->stk_a);
// 	index = partition(e, left, right, pivot);
// 	quick_sort(e, left, index - 1);
// 	quick_sort(e, index , right);
// }
