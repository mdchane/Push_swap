/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:25:36 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/21 09:27:21 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int	ft_len_num(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	print_stack(t_env *e)
{
	int		i;
	int		j;

	// ft_printf("%-110s", "PILE A:");
	// ft_printf("%-110s\n", "PILE B:");
	while (e->a || e->b)
	{
		i = 0;
		if (e->a)
		{
			ft_putnbr(e->a->nbr);
			put_n_char(' ', 10 - ft_len_num(e->a->nbr));
			i = 10;
			i += put_n_char('-', e->a->nbr);
			e->a = e->a->next;
		}
		if (e->b)
		{
			put_n_char(' ', 110 - i);
			ft_putnbr(e->b->nbr);
			put_n_char(' ', 10 - ft_len_num(e->b->nbr));
			put_n_char('-', e->b->nbr);
			e->b = e->b->next;
		}
		ft_putchar('\n');
		j = 0;
		while (j < 100000000)
			j++;
	}
	put_n_char('\n', 10);
}

void	print_buff(t_list *buff)
{
	int		i;

	i = 0;
	while (buff)
	{
		ft_putstr(buff->content);
		buff = buff->next;
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
