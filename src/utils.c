/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchane <dchane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:59:44 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/05 15:06:05 by dchane           ###   ########.fr       */
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
