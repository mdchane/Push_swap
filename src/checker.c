/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/21 14:56:25 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	run_checker(t_env *e)
{
	t_list	*beg;
	int		max;

	max = stk_max(e->a);
	beg = e->buff;
	while (e->buff)
	{
		if (((char *)e->buff->content)[0] == 's')
			stk_swap(e->a, e->b, ((char *)e->buff->content)[1]);
		if (((char *)e->buff->content)[0] == 'p')
			stk_push(&e->a, &e->b, ((char *)e->buff->content)[1]);
		if (((char *)e->buff->content)[0] == 'r' && e->buff->content_size == 2)
			stk_rotate(&e->a, &e->b, ((char *)e->buff->content)[1]);
		else
			stk_rev_rotate(&e->a, &e->b, ((char *)e->buff->content)[2]);
		if (e->opt[0])
		{
			print_visu(max, e->a, e->b);
			print_visu_buff(e->buff, e->opt[1]);
		}
		e->buff = e->buff->next;
	}
	e->buff = beg;
	if (e->opt[2])
		ft_printf("Nombre de commande = %d\n", lst_len(e->buff));
}

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
