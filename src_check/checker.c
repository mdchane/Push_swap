/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:41 by mdchane           #+#    #+#             */
/*   Updated: 2019/01/15 14:47:45 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libpush.h"

void	init_stack(t_stack *stk, int argc, char **argv)
{
}

int		main(int argc, char **argv)
{
	int	i;
	i = 1;
	while (++i < argc)
		printf("%s -> %d\n", argv[i], ft_atoi(argv[i]));
	return (0);
}
