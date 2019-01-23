/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:50:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/23 13:41:29 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpush.h"

t_stack	*stk_add_begin(t_stack *stk, int nbr)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
			return (NULL);
	new->nbr = nbr;
	new->next = stk;
	return (new);
}
