/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:59:44 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/30 16:48:21 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		stk_is_sorted(t_stack *a, t_stack *b)
{
	if (b)
}

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

	i = 0;
	while (buff)
	{
		printf("i = %d et buff =%s\n", i, buff->content);
		buff = buff->next;
		i++;
	}
}

int		is_zero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}
