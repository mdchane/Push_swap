/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 14:47:21 by mdchane           #+#    #+#             */
/*   Updated: 2019/02/27 10:01:03 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpush.h"

int		is_option(char c)
{
	if (c == 'v' || c == 'c' || c == 'n')
		return (1);
	return (0);
}

int		init_opt(t_env **e, int argc, char **argv)
{
	int		i;

	ft_bzero((*e)->opt, sizeof(int) * 3);
	i = 1;
	if (argc > 1)
		if (argv[1][0] == '-' && is_option(argv[1][1]))
		{
			while (argv[1][i])
			{
				if (argv[1][i] == 'v')
					(*e)->opt[0] = 1;
				else if (argv[1][i] == 'c')
					(*e)->opt[1] = 1;
				else if (argv[1][i] == 'n')
					(*e)->opt[2] = 1;
				else
					error(*e);
				i++;
			}
		}
	if ((*e)->opt[0] == 1 || (*e)->opt[1] == 1 || (*e)->opt[2] == 1)
		return (1);
	return (0);
}

size_t	ft_len_nbr(long n)
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

int		sign(char *str)
{
	if (str[0] == '+')
		return (1);
	return (0);
}

void	init_stack(t_env *e, char **argv, int begin, int last)
{
	int		nbr;
	t_stack	**stk;

	stk = &(e->a);
	*stk = NULL;
	while (begin <= --last)
	{
		nbr = ft_atoi(argv[last]);
		if (ft_strlen(argv[last]) != ft_len_nbr(nbr) + sign(argv[last]))
			error(e);
		stk_doublon(e, *stk, nbr);
		if (nbr != 0)
			stk_add_begin(stk, nbr);
		else if (is_zero(argv[last]))
			stk_add_begin(stk, 0);
		else
			error(e);
	}
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_e(t_env **e, int argc, char **argv)
{
	char	**tab;
	int		opt;

	if (!(*e = (t_env *)ft_memalloc(sizeof(t_env))))
		exit(1);
	opt = init_opt(e, argc, argv);
	if (argc == 2 + opt)
	{
		tab = ft_strsplit(argv[1 + opt], ' ');
		init_stack(*e, tab, 0, tab_len(tab));
		free_tab(tab);
	}
	else
		init_stack(*e, argv, 1 + opt, argc);
	(*e)->buff = NULL;
}
