/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/23 14:54:46 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpush.h"

int		is_zero(char *str)
{
	int		i;

	i = 0;
	while (str[i] == '0')
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}


void	init_stack(t_stack **stk, int argc, char **argv)
{
	int		nbr;

	*stk = NULL;
	while (--argc > 0)
	{
		nbr = ft_atoi(argv[argc]);
		if (nbr != 0 )
			*stk = stk_add_begin(*stk, nbr);
		else if (is_zero(argv[argc]))
			*stk = stk_add_begin(*stk, 0);
		else
		{
			printf("Error\n");
		 	exit(1);
		}
		printf("%d = %d\n", argc, (*stk)->nbr);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	t_stack	*stk;

	init_stack(&stk, argc, argv);
	printf("haut %d\n", stk->nbr);
	return (0);
}
