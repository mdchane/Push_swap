/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:54:04 by dchane            #+#    #+#             */
/*   Updated: 2019/02/06 14:49:44 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	sort_two(t_env *e)
{
	if (e->stk_a->nbr > e->stk_a->next->nbr)
		lst_add_end(&e->buff, "ra\n");
}

void	sort_three(t_env *e)
{
	int		*tab;

	tab = stk_to_tab(e->stk_a);
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		lst_add_end(&e->buff, "rra\n");
		lst_add_end(&e->buff, "sa\n");
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		lst_add_end(&e->buff, "sa\n");
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		lst_add_end(&e->buff, "rra\n");
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		lst_add_end(&e->buff, "ra\n");
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		lst_add_end(&e->buff, "ra\n");
		lst_add_end(&e->buff, "sa\n");
	}
}
int		stk_smallest(t_stack *stk)
{
	int		min;

	min = stk->nbr;
	while (stk)
	{
		if (min > stk->nbr)
			min = stk->nbr;
		stk = stk->next;
	}
	return (min);
}

void	sort_mediane(t_env *e)
{
	int		med;

	print_stack(e->stk_a, e->stk_b);
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

void	sort(t_env *e)
{
	if (stk_len(e->stk_a) == 2)
		sort_two(e);
	else if (stk_len(e->stk_a) == 3)
		sort_three(e);
	else
	{
		sort_mediane(e);
	}
	print_buff(e->buff);
	print_stack(e->stk_a, e->stk_b);
}
