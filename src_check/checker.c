/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/30 14:42:19 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	error()
{
	ft_putendl("Error");
	exit(1);
}

void	init_stack(t_stack **stk, int argc, char **argv)
{
	int		nbr;

	*stk = NULL;
	while (--argc > 0)
	{
		nbr = ft_atoi(argv[argc]);
		stk_doublon(*stk, nbr);
		if (nbr != 0 )
			*stk = stk_add_begin(*stk, nbr);
		else if (is_zero(argv[argc]))
			*stk = stk_add_begin(*stk, 0);
		else
			error();
	}
}

void	read_commands(t_env *e)
{
	char	*line;

	e->buff = NULL;
	while (get_next_line(0, &line) > 0)
	{
		is_command(line);
		e->buff = lst_add_end(e->buff, line);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_env	e;

	i = 0;
	init_stack(&e.stk_a, argc, argv);
	read_commands(&e);
	print_buff(e.buff);
	run_checker(&e);
	//print_stack(e.stk_a, e.stk_b);
	return (0);
}
