/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:22:13 by mdchane           #+#    #+#             */
/*   Updated: 2019/03/11 16:10:48 by mdchane          ###   ########.fr       */
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
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb")
		&& ft_strcmp(str, "ss") && ft_strcmp(str, "pa")
		&& ft_strcmp(str, "pb") && ft_strcmp(str, "ra")
		&& ft_strcmp(str, "rb") && ft_strcmp(str, "rr")
		&& ft_strcmp(str, "rra") && ft_strcmp(str, "rrb")
		&& ft_strcmp(str, "rrr"))
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

int		is_option(char c)
{
	if (c == 'v' || c == 'c' || c == 'n')
		return (1);
	return (0);
}

int		init_opt(t_env **e, int argc, char **argv)
{
	int		i;

	ft_bzero((*e)->opt, sizeof(int) * 3);
	i = 1;
	if (argc > 1)
		if (argv[1][0] == '-' && is_option(argv[1][1]))
		{
			while (argv[1][i])
			{
				if (argv[1][i] == 'v')
					(*e)->opt[0] = 1;
				else if (argv[1][i] == 'c')
					(*e)->opt[1] = 1;
				else if (argv[1][i] == 'n')
					(*e)->opt[2] = 1;
				else
					error(*e);
				i++;
			}
		}
	if ((*e)->opt[0] == 1 || (*e)->opt[1] == 1 || (*e)->opt[2] == 1)
		return (1);
	return (0);
}
