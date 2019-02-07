/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:55:18 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/07 16:48:00 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	push_min(t_env *e)
{
	int		min;
	int		pos;

	min = stk_smallest(e->stk_a);
	pos = stk_smallest_pos(e->stk_a);
	if (pos == 0)
	{
		stk_push(&e->stk_a, &e->stk_b, 'b');
		lst_add_end(&e->buff, "pb\n");
	}
	else if (pos < (stk_len(e->stk_a) / 2))
		while (pos > 0)
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "ra\n");
			pos--;
		}
	else
		while (stk_len(e->stk_a) - pos >= 0)
		{
			stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "rra\n");
			pos++;
		}
}


void	sort_min(t_env *e)
{
	print_stack(e->stk_a, e->stk_b);
	while (!stk_is_sorted(e->stk_a, e->stk_b))
	{
		while (stk_len(e->stk_a) > 3)
			push_min(e);
		sort_three(e);
		while (e->stk_b)
			stk_push(&e->stk_a, &e->stk_b, 'a');
	}
}
