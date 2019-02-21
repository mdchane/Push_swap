/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:25:36 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/21 15:10:32 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		ft_len_num(int n)
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

void	aff_piles(int max)
{
	ft_printf("\033[2J\033[H");
	ft_putstr("PILE A:");
	put_n_char(' ', max + max / 10 + 3);
	ft_putstr("PILE B:\n");
}

void	print_visu_buff(t_list *buff, int opt)
{
	if (opt == 1)
	{
		if (buff->next)
			ft_printf("\033[31;1;4mCommande: %s\033[0m\n", buff->content);
		else
			ft_printf("\033[32;1;4mLast action: %s\033[0m\n", buff->content);
	}
	usleep(180000);
}

void	print_visu(int max, t_stack *a, t_stack *b)
{
	int		i;

	aff_piles(max);
	while (a || b)
	{
		i = 0;
		if (a)
		{
			ft_putnbr(a->nbr);
			put_n_char(' ', 10 - ft_len_num(a->nbr));
			i = 10;
			i += put_n_char('-', a->nbr);
			a = a->next;
		}
		if (b)
		{
			put_n_char(' ', max + max / 10 + 10 - i);
			ft_putnbr(b->nbr);
			put_n_char(' ', 10 - ft_len_num(b->nbr));
			put_n_char('-', b->nbr);
			b = b->next;
		}
		ft_putchar('\n');
	}
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
