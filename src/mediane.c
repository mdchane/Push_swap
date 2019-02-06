/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediane.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:35:41 by dchane            #+#    #+#             */
/*   Updated: 2019/02/06 16:27:33 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		stk_len(t_stack *stk)
{
	int		len;

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
	int		*tab;
	int		i;

	tab = (int *)malloc(sizeof(int) * stk_len(stk));
	i = 0;
	while(stk)
	{
		tab[i] = stk->nbr;
		stk = stk->next;
		i++;
	}
	return (tab);
}

void	tri_rapide(int *tableau, int taille)
{
	int mur;
	int	courant;
	int	pivot;
	int tmp;

	if (taille < 2)
		return;
	pivot = tableau[taille - 1];
	mur = 0;
	courant = 0;
	while (courant < taille)
	{
		if (tableau[courant] <= pivot)
		{
			if (mur != courant)
			{
				tmp = tableau[courant];
				tableau[courant] = tableau[mur];
				tableau[mur] = tmp;
			}
			mur++;
		}
		courant++;
	}
	print_tab(tableau, taille);
	tri_rapide(tableau, mur - 1);
	tri_rapide(tableau + mur - 1, taille - mur + 1);
}

int		stk_mediane(t_stack *stk)
{
	int	*tab;
	int	len;

	len = stk_len(stk);
	tab = stk_to_tab(stk);
	tri_rapide(tab, len);
	print_tab(tab, len);
	return (tab[(len / 2)]);
}
