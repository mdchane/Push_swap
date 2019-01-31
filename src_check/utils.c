/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:59:44 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/31 16:20:00 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		stk_is_sorted(t_stack *a, t_stack *b)
{
	if (!b)
	{
		if (!a)
			return (1);
		while (a->next)
		{
			if (a->nbr > a->next->nbr)
					return (0);
			a = a->next;
		}
		return (1);
	}
	else
		return (0);
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

void	stk_del(t_stack **stk)
{
	if (!stk || !(*stk))
		return ;
	if ((*stk)->next != NULL)
		stk_del(&(*stk)->next);
	if (stk)
		ft_memdel((void **)stk);
}

void	free_all(t_env *e)
{
	ft_lstdel(&e->buff);
	stk_del(&e->stk_a);
	stk_del(&e->stk_b);
}
