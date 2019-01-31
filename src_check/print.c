/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:25:36 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/31 16:26:03 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

void	print_stack(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
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
		printf("i = %d et buff =%s\n", i, buff->content);
		buff = buff->next;
		i++;
	}
	buff = tmp;
}
