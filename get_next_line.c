/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdchane <mdchane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:32:40 by mdchane           #+#    #+#             */
/*   Updated: 2018/11/22 13:41:30 by mdchane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_it(char **str, int fd, int *error)
{
	int		nbread;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	while ((nbread = read(fd, (void *)buff, BUFF_SIZE)) > 0)
	{
		buff[nbread] = '\0';
		if (!(tmp = ft_strjoin(*str, buff)))
		{
			*error = -1;
			return (NULL);
		}
		ft_strdel(str);
		*str = tmp;
		if (ft_strchr(*str, '\n'))
			return (*str);
	}
	if (nbread < 0)
		*error = -1;
	return (*str);
}

int		ft_errors(char **str, int fd, char **line)
{
	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (1);
	if (!(*str))
	{
		if (!(*str = ft_strnew(0)))
			return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	int			i;
	char		*tmp;
	int			error;

	if (ft_errors(&str[fd], fd, line))
		return (-1);
	str[fd] = ft_read_it(&str[fd], fd, &error);
	if (error < 0)
		return (-1);
	i = 0;
	if (str[fd][i])
	{
		while (str[fd][i] && str[fd][i] != '\n')
			i++;
		if (!(*line = ft_strsub(str[fd], 0, i)))
			return (-1);
		if (!(tmp = ft_strsub(str[fd], i + 1, ft_strlen(str[fd] + i + 1))))
			return (-1);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		return (1);
	}
	ft_strdel(&str[fd]);
	return (0);
}
