/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/11 12:45:17 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		main(int argc, char **argv)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(1);
	init_stack(e, argc, argv);
	read_commands(e);
	run_checker(e);
	if (stk_is_sorted(e->stk_a, e->stk_b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_all(e);
	return (0);
}
