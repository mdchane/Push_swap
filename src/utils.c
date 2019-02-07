/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:59:44 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/07 16:19:42 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		stk_smallest(t_stack *stk)
{
	int		min;

	if (stk)
	{
		min = stk->nbr;
		while (stk)
		{
			if (min > stk->nbr)
				min = stk->nbr;
			stk = stk->next;
		}
		return (min);
	}
	else
		return (0);
}

int		stk_smallest_pos(t_stack *stk)
{
	int		min;
	int		posmin;
	int		i;

	i = 0;
	posmin = 0;
	if (stk)
	{
		min = stk->nbr;
		while (stk)
		{
			if (min > stk->nbr)
			{
				min = stk->nbr;
				posmin = i;
			}
			stk = stk->next;
			i++;
		}
		return (posmin);
	}
	else
		return (0);
}

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

void	error(t_env *e)
{
	ft_putendl("Error");
	free_all(e);
	exit(1);
}

void	free_all(t_env *e)
{
	ft_lstdel(&e->buff);
	stk_del(&e->stk_a);
	stk_del(&e->stk_b);
	free(e);
}
