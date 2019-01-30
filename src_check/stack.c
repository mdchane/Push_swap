/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 11:50:51 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/30 11:26:43 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

t_stack	*stk_add_begin(t_stack *stk, int nbr)
{
	t_stack		*new;

	if (!(new = (t_stack *)malloc(sizeof(*new))))
			return (NULL);
	new->nbr = nbr;
	new->next = stk;
	return (new);
}

void	stk_doublon(t_stack *stk, int nbr)
{
	if (!stk)
		return ;
	while (stk)
	{
		if (stk->nbr == nbr)
			error();
		stk= stk->next;
	}
	return ;
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

void	is_command(char *str)
{
	if (ft_strcmp(str, "sa") && ft_strcmp(str, "sb") &&
		ft_strcmp(str, "ss") && ft_strcmp(str, "pa") &&
		ft_strcmp(str, "pb") && ft_strcmp(str, "ra") &&
		ft_strcmp(str, "rb") && ft_strcmp(str, "rr") &&
		ft_strcmp(str, "rra") && ft_strcmp(str, "rrb") &&
		ft_strcmp(str, "rrr"))
		error();
	return ;
}
