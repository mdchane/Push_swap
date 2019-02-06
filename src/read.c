/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:22:13 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/06 13:51:11 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	lst_add_end(t_list **lst, char *str)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew(str, ft_strlen(str));
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	is_command(t_env *e, char *str)
{
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb") &&
		ft_strcmp(str, "ss") && ft_strcmp(str, "pa") &&
		ft_strcmp(str, "pb") && ft_strcmp(str, "ra") &&
		ft_strcmp(str, "rb") && ft_strcmp(str, "rr") &&
		ft_strcmp(str, "rra") && ft_strcmp(str, "rrb") &&
		ft_strcmp(str, "rrr"))
		error(e);
	return ;
}

void	read_commands(t_env *e)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		is_command(e, line);
		lst_add_end(&e->buff, line);
		free(line);
	}
}
