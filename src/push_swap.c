/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:52:57 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/11 12:45:14 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		main(int argc, char **argv)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(1);
	init_stack(e, argc, argv);
	sort(e);

	free_all(e);
	return (0);
}
