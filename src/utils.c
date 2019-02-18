/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:59:44 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/18 11:28:46 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		tab_len(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
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
	stk_del(&e->a);
	stk_del(&e->b);
	free(e);
}
