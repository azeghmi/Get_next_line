/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azeghmi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:08:53 by azeghmi           #+#    #+#             */
/*   Updated: 2019/10/09 19:08:55 by azeghmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_cut(char *str, int j, int f)
{
	char			*tmp;

	tmp = str;
	while (str && (str[j] && str[j] != '\n'))
		j++;
	if (str && f)
		return (ft_strsub(str, 0, j));
	if (str)
		str = ft_strsub(str, j + 1, ft_strlen(str) - j);
	ft_strdel(&tmp);
	return (str);
}

int					get_next_line(const int fd, char **line)
{
	char			tmp[BUFF_SIZE + 1];
	static char		*str[OPEN_MAX];
	int				ret;
	char			*tmp2;

	if (fd < 0 || fd >= OPEN_MAX || read(fd, tmp, 0) < 0 || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		!(str[fd]) ? str[fd] = ft_memalloc(BUFF_SIZE + 1) : str[fd];
		tmp2 = str[fd] ? str[fd] : 0;
		str[fd] = str[fd] ? ft_strjoin(str[fd], tmp) : 0;
		tmp2 ? ft_strdel(&tmp2) : 0;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	str[fd] ? *line = ft_cut(str[fd], 0, 1) : 0;
	str[fd] = str[fd] ? ft_cut(str[fd], 0, 0) : 0;
	if (str[fd])
	{
		(!(ft_strlen(str[fd]))) ? ft_strdel(&str[fd]) : str[fd];
		return (1);
	}
	return (0);
}
