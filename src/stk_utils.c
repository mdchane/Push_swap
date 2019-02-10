/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchane <dchane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:14:28 by dchane            #+#    #+#             */
/*   Updated: 2019/02/10 14:17:14 by dchane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int     stk_max(t_stack *stk)
{
    int		max;

	if (stk)
	{
		max = stk->nbr;
		while (stk)
		{
			if (max < stk->nbr)
				max = stk->nbr;
			stk = stk->next;
		}
		return (max);
	}
	else
		return (0);
}

int		stk_min(t_stack *stk)
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

int		stk_posmin(t_stack *stk)
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