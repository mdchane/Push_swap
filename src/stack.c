/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:50:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/11 08:29:22 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		is_zero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int		in_tab(int *tab, int nb, int len)
{
	while (--len >= 0)
	{
		if (nb == tab[len])
			return (1);
	}
	return (0);
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
		stk = stk->next;
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
