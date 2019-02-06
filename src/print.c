/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:25:36 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/06 12:35:54 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	print_stack(t_stack *a, t_stack *b)
{
	printf("a : ");
	while (a)
	{
		printf("%d ", a->nbr);
		a = a->next;
	}
	printf("\nb : ");
	while (b)
	{
		printf("%d ", b->nbr);
		b = b->next;
	}
	printf("\n\n");
}

void	print_buff(t_list *buff)
{
	int		i;
	t_list	*tmp;

	tmp = buff;
	i = 0;
	while (buff)
	{
		ft_putstr(buff->content);
		buff = buff->next;
		i++;
	}
	buff = tmp;
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
