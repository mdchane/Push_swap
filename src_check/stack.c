/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:50:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/24 11:12:36 by mdchane          ###   ########.fr       */
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

void	print_stack(t_stack *stk)
{
	int		i;

	i = 0;
	while (stk)
	{
		printf("%d = %d\n", i, stk->nbr);
		i++;
		stk = stk->next;
	}
}

void	print_buff(char **buff)
{
	int		i;

	i = 0;
	while (buff[i])
	{
		ft_putendl(buff[i]);
		i++;
	}
}
