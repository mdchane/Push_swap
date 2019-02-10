/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchane <dchane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:43 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/10 14:18:25 by dchane           ###   ########.fr       */
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
void	push_to_b(t_env *e, int med)
{
	while (stk_min(e->stk_a) < med)
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

void	push_to_a(t_env *e, int med)
{
	if (!e->stk_b)
		return ;
	while (stk_max(e->stk_b) >= med)
	{
		if (e->stk_b->nbr >= med)
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
	print_stack(e->stk_a, e->stk_b);
	push_to_b(e, stk_mediane(e->stk_a));
	print_stack(e->stk_a, e->stk_b);
	push_to_a(e, stk_mediane(e->stk_b));
	print_stack(e->stk_a, e->stk_b);

}


