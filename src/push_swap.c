/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:52:57 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/18 10:10:12 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc < 2)
		return (0);
	init_e(&e, argc, argv);
	sort(e);
	free_all(e);
	return (0);
}
