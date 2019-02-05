/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchane <dchane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:35:41 by dchane            #+#    #+#             */
/*   Updated: 2019/02/05 15:20:42 by dchane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		stk_len(t_stack *stk)
{
    int     len;

	len = 0;
	while (stk)
	{
		stk = stk->next;
		len++;
	}
	return (len);
}

int		*stk_to_tab(t_stack *stk)
{
	int		tab[stk_len(stk)];
	int		i;

	i = 0;
	while(stk)
	{
		tab[i] = stk->nbr;
		stk = stk->next;
		i++;
	}
}

void print_tab(int *tab, int taille)
{
    int i = 0;

    while(i < taille)
    {
        printf("%d ", tab[i]);
        i++;
    }
    printf("\n");
}

void tri_rapide (int *tableau, int taille) {
    int mur, courant, pivot, tmp;
    print_tab(tableau, taille);
    if (taille < 2) return;
    // On prend comme pivot l element le plus a droite
    pivot = tableau[taille - 1];
    mur  = courant = 0;
    while (courant < taille) {
        if (tableau[courant] <= pivot) {
            if (mur != courant) {
                tmp=tableau[courant];
                tableau[courant]=tableau[mur];
                tableau[mur]=tmp;              
            }
            mur ++;
        }
        courant ++;
    }
    tri_rapide(tableau, mur - 1);
    tri_rapide(tableau + mur - 1, taille - mur + 1);
}
