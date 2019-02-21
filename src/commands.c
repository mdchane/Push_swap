/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:27:33 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/21 15:04:06 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void		stk_swap(t_stack *a, t_stack *b, char c)
{
	int		tmp;

	if ((c == 'a' || c == 's') && (a && a->next))
	{
		tmp = a->nbr;
		a->nbr = a->next->nbr;
		a->next->nbr = tmp;
	}
	if ((c == 'b' || c == 's') && (b && b->next))
	{
		tmp = b->nbr;
		b->nbr = b->next->nbr;
		b->next->nbr = tmp;
	}
}

void		stk_push(t_stack **a, t_stack **b, char c)
{
	t_stack *tmp;

	if (c == 'a' && *b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
	if (c == 'b' && *a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
}

static void	stk_rot(t_stack **stk)
{
	int		first;
	t_stack	*begin;

	begin = (*stk);
	first = (*stk)->nbr;
	while ((*stk)->next)
	{
		(*stk)->nbr = (*stk)->next->nbr;
		(*stk) = (*stk)->next;
	}
	(*stk)->nbr = first;
	(*stk) = begin;
}

void		stk_rotate(t_stack **a, t_stack **b, char c)
{
	if ((c == 'a' || c == 'r') && (*a && (*a)->next))
		stk_rot(a);
	if ((c == 'b' || c == 'r') && (*b && (*b)->next))
		stk_rot(b);
}

void		stk_rev_rotate(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;
	t_stack	*begin;

	if ((c == 'a' || c == 'r') && (*a && (*a)->next))
	{
		begin = *a;
		while ((*a)->next->next)
			(*a) = (*a)->next;
		tmp = (*a)->next;
		(*a)->next = NULL;
		(*a) = begin;
		stk_add_begin(a, tmp->nbr);
		free(tmp);
	}
	if ((c == 'b' || c == 'r') && (*b && (*b)->next))
	{
		begin = *b;
		while ((*b)->next->next)
			(*b) = (*b)->next;
		tmp = (*b)->next;
		(*b)->next = NULL;
		(*b) = begin;
		stk_add_begin(b, tmp->nbr);
		free(tmp);
	}
}
