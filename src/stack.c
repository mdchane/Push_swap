/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:50:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/20 14:45:11 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	init_stack(t_env *e, char **argv, int begin, int last)
{
	int		nbr;
	t_stack	**stk;

	stk = &(e->a);
	*stk = NULL;
	while (begin <= --last)
	{
		nbr = ft_atoi(argv[last]);
		stk_doublon(e, *stk, nbr);
		if (nbr != 0 )
			stk_add_begin(stk, nbr);
		else if (is_zero(argv[last]))
			stk_add_begin(stk, 0);
		else
			error(e);
	}
}

int		init_e(t_env **e, int argc, char **argv)
{
	char	**tab;
	int		opt;

	if (!(*e = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(1);
	opt = 0;
	if (argc > 1)
	{
		if (ft_strcmp(argv[1], "-v") == 0)
			opt = 1;
	}
	if (argc == 2 + opt)
	{
		tab = ft_strsplit(argv[1 + opt], ' ');
		init_stack(*e, tab, 0, tab_len(tab));
	}
	else
		init_stack(*e, argv, 1 + opt, argc);
	(*e)->buff = NULL;
	return (opt);
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
