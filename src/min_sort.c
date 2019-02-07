/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:55:18 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/07 15:20:09 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"


// 1) tant que la pile contient plus de 3 valeurs
// 	1.1) on définit b et pos.
// 	1.2.a) si b est en haut de la pile A, on le push dans la pile B.
// 	1.2.b) sinon, is la position de b est après le milieu de la pile, on rotate la pile A.
// 	1.2.c) sinon, on reverse rotate la pile A.
// 2) on trie les trois nombres restants dans la pile A grâce à une fonction pour cas particulier
// 3) on vide la pile B dans la pile A
// 4) si la pile est toujours pas triée, on recommence

void	sort_min(t_env *e)
{
	int		min;
	int		pos;

	print_stack(e->stk_a, e->stk_b);
	while (!stk_is_sorted(e->stk_a, e->stk_b))
	{
		while (stk_len(e->stk_a) > 3)
		{
			min = stk_smallest(e->stk_a);
			pos = stk_smallest_pos(e->stk_a);
			printf("min = %d et posmin = %d\n", min, pos);
			if (pos == 0)
				stk_push(&e->stk_a, &e->stk_b, 'b');
			else if (pos > (stk_len(e->stk_a) / 2))
				stk_rotate(&e->stk_a, &e->stk_b, 'a');
			else
				stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
			print_stack(e->stk_a, e->stk_b);
			sleep(1);
		}
		sort_three(e);
		print_stack(e->stk_a, e->stk_b);
		while (e->stk_b)
		{
			stk_push(&e->stk_a, &e->stk_b, 'a');
		}
		print_stack(e->stk_a, e->stk_b);
	}
}
