/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/24 12:01:07 by mdchane          ###   ########.fr       */
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
	}
}

void	read_commands(t_env e)
{
	int		i;

	i = 0;
	e.buff = (char **)malloc(sizeof(char *) * 5);
	while (get_next_line(0, &e.buff[i]) > 0)
	{
		//printf("%s\n", e.buff[i]);
		//if (ft_strcmp(e.buff, ""))
		i++;
		if (i > 5)
			break;
	}
	print_buff(e.buff);
}

int		main(int argc, char **argv)
{
	int		i;
	t_env	e;

	i = 0;
	init_stack(&e.stk_a, argc, argv);
	print_stack(e.stk_a);
	read_commands(e);
	//print_buff(e.buff);
	return (0);
}
