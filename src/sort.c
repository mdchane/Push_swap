/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchane <dchane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 16:54:04 by dchane            #+#    #+#             */
/*   Updated: 2019/02/05 17:47:51 by dchane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void    sort_two(t_stack *stk)
{
    if (stk->nbr > stk->next->nbr)
        ft_putstr("ra\n");
}

void    sort_three(t_stack *stk)
{
    int     *tab;

    tab = stk_to_tab(stk);
    if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] < tab[2])
        ft_putstr("rra\nsa\n");
    else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
        ft_putstr("sa\n");
    else if (tab[0] < tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
        ft_putstr("rra\n");
    else if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] > tab[2])
        ft_putstr("ra\n");
    else if (tab[0] > tab[1] && tab[1] > tab[2] && tab[0] > tab[2])
        ft_putstr("ra\nsa\n");
}

void    sort(t_env *e)
{
    if (stk_len(e->stk_a) == 2)
        sort_two(e->stk_a);
    else if (stk_len(e->stk_a) == 3)
        sort_three(e->stk_a);
}