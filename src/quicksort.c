/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:28:43 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/11 15:21:37 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int	stk_getnum(t_stack *stk, int n)
{
	while (n > 0)
	{
		stk = stk->next;
		n--;
	}
	return (stk->nbr);
}
void	split_to_b(t_env *e, int med)
{
	while (stk_min(e->stk_a) < med)
	{
		if (e->stk_a->nbr < med)
		{
			stk_push(&e->stk_a, &e->stk_b, 'b');
			lst_add_end(&e->buff, "pb\n");
		}
		else
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "ra\n");
		}
	}
}

void	push_to_a(t_env *e)
{
	int		med;
	int		nb_push;

	while (e->stk_b)
	{
		nb_push = 0;
		med = stk_mediane(e->stk_b);
		while (stk_max(e->stk_b) >= med && e->stk_b)
		{
			if (e->stk_b->nbr >= med)
			{
				stk_push(&e->stk_a, &e->stk_b, 'a');
				lst_add_end(&e->buff, "pa\n");
				stk_rotate(&e->stk_a, &e->stk_b, 'a');
				lst_add_end(&e->buff, "ra\n");
				nb_push++;
			}
			else
			{
				stk_rotate(&e->stk_a, &e->stk_b, 'b');
				lst_add_end(&e->buff, "rb\n");
			}
		}
		printf("nb_push = %d\n", nb_push);
		print_stack(e->stk_a, e->stk_b);
	}
}

int		divntwo(int len, int n)
{
	while (n > 0)
	{
		len = len / 2;
		n--;
	}
	return (len);
}

void	mini_sort(t_env *e, int i)
{
	int		n;

	if (i == stk_len(e->stk_a) / 4 - 1)
		return;
	n = i * 2;
	printf("div = %d\n", i);
	while (i > 0)
	{
		stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
		lst_add_end(&e->buff, "rra\n");
		stk_push(&e->stk_a, &e->stk_b, 'b');
		lst_add_end(&e->buff, "pb\n");
		i--;
	}
	print_stack(e->stk_a, e->stk_b);
	while (e->stk_b)
	{
		if (e->stk_b->nbr == stk_min(e->stk_b))
		{
			stk_push(&e->stk_a, &e->stk_b, 'a');
			lst_add_end(&e->buff, "pa\n");
		}
		else
		{
			stk_rotate(&e->stk_a, &e->stk_b, 'b');
			lst_add_end(&e->buff, "rb\n");
		}
	}
	print_stack(e->stk_a, e->stk_b);
	mini_sort(e, n);
}

void	sort_med(t_env *e)
{
	int		med;

	med = stk_mediane(e->stk_a);
	print_stack(e->stk_a, e->stk_b);
	printf("----------------------------------------------------------\n");
	printf("split to b\n");
	split_to_b(e, med);
	print_stack(e->stk_a, e->stk_b);
	printf("----------------------------------------------------------\n");
	printf("push to a\n");
	push_to_a(e);
	print_stack(e->stk_a, e->stk_b);
	printf("----------------------------------------------------------\n");
	printf("mini sort\n");
	stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
	lst_add_end(&e->buff, "rra\n");
	stk_rev_rotate(&e->stk_a, &e->stk_b, 'a');
	lst_add_end(&e->buff, "rra\n");
	print_stack(e->stk_a, e->stk_b);
	mini_sort(e, 3);
	print_stack(e->stk_a, e->stk_b);
}


