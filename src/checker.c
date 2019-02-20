/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/20 14:13:55 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc < 2)
		return (0);
	init_e(&e, argc, argv);
	read_commands(e);
	run_checker(e);
	if (stk_is_sorted(e->a, e->b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_all(e);
	return (0);
}
