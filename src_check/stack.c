/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:50:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/24 16:32:26 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpush.h"

t_stack	*stk_add_begin(t_stack *stk, int nbr)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
			return (NULL);
	new->nbr = nbr;
	new->next = stk;
	return (new);
}

t_list	*lst_add_end(t_list *lst, char *str)
{
	t_list	*new;
	t_list	*tmp;

	new = ft_lstnew(str, ft_strlen(str));
	if (lst == NULL)
	{
		lst = new;
		return (lst);
	}
	tmp = lst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return (lst);
}

void	print_stack(t_stack *stk)
{
	int		i;

	i = 0;
	while (stk)
	{
		printf("%d = %d\n", i, stk->nbr);
		i++;
		stk = stk->next;
	}
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
