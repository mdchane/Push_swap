/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 14:14:28 by dchane            #+#    #+#             */
/*   Updated: 2019/02/21 14:41:34 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		stk_len(t_stack *stk)
{
	int		len;

	len = 0;
	while (stk)
	{
		stk = stk->next;
		len++;
	}
	return (len);
}

int		stk_max(t_stack *stk)
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

int		stk_posmax(t_stack *stk)
{
	int		max;
	int		posmax;
	int		i;

	i = 0;
	posmax = 0;
	if (stk)
	{
		max = stk->nbr;
		while (stk)
		{
			if (max < stk->nbr)
			{
				max = stk->nbr;
				posmax = i;
			}
			stk = stk->next;
			i++;
		}
		return (posmax);
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
