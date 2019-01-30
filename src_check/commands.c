/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:27:33 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/30 15:20:36 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	stk_swap(t_stack *a, t_stack *b, char c)
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

void	stk_push(t_stack **a, t_stack **b, char c)
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

void	stk_rotate(t_stack **a, t_stack **b, char c)
{
	int		first;
	t_stack	*begin;

	if ((c == 'a' || c == 'r') && (*a && (*a)->next))
	{
		begin = (*a);
		first = (*a)->nbr;
		while ((*a)->next)
		{
			(*a)->nbr = (*a)->next->nbr;
			(*a) = (*a)->next;
		}
		(*a)->nbr = first;
		(*a) = begin;
	}
	if ((c == 'b' || c == 'r') && (*b && (*b)->next))
	{
		begin = (*b);
		first = (*b)->nbr;
		while ((*b)->next)
		{
			(*b)->nbr = (*b)->next->nbr;
			(*b) = (*b)->next;
		}
		(*b)->nbr = first;
		(*b) = begin;
	}
}

void	run_checker(t_env *e)
{
	print_stack(e->stk_a, e->stk_b);
	while (e->buff)
	{
		if (((char *)e->buff->content)[0] == 's')
			stk_swap(e->stk_a, e->stk_b, ((char *)e->buff->content)[1]);
		if (((char *)e->buff->content)[0] == 'p')
			stk_push(&e->stk_a, &e->stk_b, ((char *)e->buff->content)[1]);
		if (((char *)e->buff->content)[0] == 'r' && e->buff->content_size == 2)
			stk_rotate(&e->stk_a, &e->stk_b, ((char *)e->buff->content)[1]);

		e->buff = e->buff->next;
		print_stack(e->stk_a, e->stk_b);
	}
}