/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:50:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/04 14:25:15 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	init_stack(t_env *e, int argc, char **argv)
{
	int		nbr;
	t_stack **stk;

	stk = &(e->stk_a);
	*stk = NULL;
	while (--argc > 0)
	{
		nbr = ft_atoi(argv[argc]);
		stk_doublon(e, *stk, nbr);
		if (nbr != 0 )
			stk_add_begin(stk, nbr);
		else if (is_zero(argv[argc]))
			stk_add_begin(stk, 0);
		else
			error(e);
	}
}

void	stk_add_begin(t_stack **stk, int nbr)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
			exit(1);
	new->nbr = nbr;
	new->next = *stk;
	*stk = new;
}

void	stk_doublon(t_env *e, t_stack *stk, int nbr)
{
	if (!stk)
		return ;
	while (stk)
	{
		if (stk->nbr == nbr)
			error(e);
		stk= stk->next;
	}
	return ;
}

int		stk_is_sorted(t_stack *a, t_stack *b)
{
	if (!b)
	{
		if (!a)
			return (1);
		while (a->next)
		{
			if (a->nbr > a->next->nbr)
					return (0);
			a = a->next;
		}
		return (1);
	}
	else
		return (0);
}

void	stk_del(t_stack **stk)
{
	if (!stk || !(*stk))
		return ;
	if ((*stk)->next != NULL)
		stk_del(&(*stk)->next);
	if (stk)
		ft_memdel((void **)stk);
}
