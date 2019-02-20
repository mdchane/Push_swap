/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:54:04 by dchane            #+#    #+#             */
/*   Updated: 2019/02/20 14:08:21 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	sort_two(t_env *e)
{
	if (e->a->nbr > e->a->next->nbr)
		command_buff(e, "stk_swap", 'a');
}

void	sort_three(t_env *e)
{
	int		*tab;

	tab = stk_to_tab(e->a);
	if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
	{
		command_buff(e, "stk_rev_rotate", 'a');
		command_buff(e, "stk_swap", 'a');
	}
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
		command_buff(e, "stk_swap", 'a');
	else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
		command_buff(e, "stk_rev_rotate", 'a');
	else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
		command_buff(e, "stk_rotate", 'a');
	else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
	{
		command_buff(e, "stk_rotate", 'a');
		command_buff(e, "stk_swap", 'a');
	}
}

void	sort_less_five(t_env *e)
{
	int		*mins;

	mins = get_mins(e->a, 2);
	while (stk_len(e->a) > 3)
	{
		while (!in_tab(mins, e->a->nbr, 2))
			command_buff(e, "stk_rotate", 'a');
		command_buff(e, "stk_push", 'b');
	}
	if (stk_len(e->a) == 3)
		sort_three(e);
	while (e->b)
		command_buff(e, "stk_push", 'a');
	sort_two(e);
}

void	sort(t_env *e)
{
	if (stk_is_sorted(e->a, e->b))
		return ;
	else if (stk_len(e->a) <= 5)
		sort_less_five(e);
	else
		sort_min(e);
	optimize_buff(e);
	print_buff(e->buff);
	// print_stack(e->a, e->b);
}
