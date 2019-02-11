/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:54:04 by dchane            #+#    #+#             */
/*   Updated: 2019/02/11 15:14:17 by mdchane          ###   ########.fr       */
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
		stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
		stk_swap(e->stk_a, e->stk_b, 'a');
		lst_add_end(&e->buff, "rra\n");
		lst_add_end(&e->buff, "sa\n");
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
	{
		stk_swap(e->stk_a, e->stk_b, 'a');
		lst_add_end(&e->buff, "sa\n");
	}
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
		lst_add_end(&e->buff, "rra\n");
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
	{
		stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
		lst_add_end(&e->buff, "ra\n");
	}
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		stk_rotate(&e->stk_a, &e->stk_b, 'a');
		stk_swap(e->stk_a, e->stk_b, 'a');
		lst_add_end(&e->buff, "ra\n");
		lst_add_end(&e->buff, "sa\n");
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
		sort_med(e);
	}
	print_buff(e->buff);
}
