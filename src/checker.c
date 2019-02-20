/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/20 14:47:52 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		main(int argc, char **argv)
{
	t_env	*e;
	int		opt;

	if (argc < 2)
		return (0);
	opt = init_e(&e, argc, argv);
	read_commands(e);
	run_checker(e, opt);
	if (stk_is_sorted(e->a, e->b))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_all(e);
	return (0);
}
