/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirdie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:44:23 by mbirdie           #+#    #+#             */
/*   Updated: 2019/10/31 17:44:34 by mbirdie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*new_list_elem(const int fd)
{
	t_gnl		*new;

	if (!(new = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->remainder = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

static char			*check_remainder(char **pointer_to_n, char *remainder)
{
	char *tmp;

	if ((*pointer_to_n = ft_strchr(remainder, '\n')) != NULL)
	{
		tmp = ft_strsub(remainder, 0, *pointer_to_n - remainder);
		ft_strcpy(remainder, ++(*pointer_to_n));
	}
	else
	{
		tmp = ft_strnew(ft_strlen(remainder) + 1);
		ft_strcat(tmp, remainder);
		ft_strclr(remainder);
	}
	return (tmp);
}

static int			get_line(const int fd, char **line, char *remainder)
{
	char			buf[BUFF_SIZE + 1];
	char			*pointer_to_n;
	char			*tmp;
	int				bytes_read;

	pointer_to_n = NULL;
	bytes_read = 1;
	*line = check_remainder(&pointer_to_n, remainder);
	while (pointer_to_n == 0 && ((bytes_read = read(fd, buf, BUFF_SIZE)) != 0))
	{
		buf[bytes_read] = '\0';
		if ((pointer_to_n = ft_strchr(buf, '\n')) != NULL)
		{
			ft_strcpy(remainder, ++pointer_to_n);
			ft_strclr(--pointer_to_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buf)) || bytes_read < 0)
			return (-1);
		ft_strdel(&tmp);
	}
	return ((ft_strlen(*line) || ft_strlen(remainder) || bytes_read) ? 1 : 0);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*list;
	t_gnl			*tmp;

	if (fd < 0 || line == 0)
		return (-1);
	if (!list)
		list = new_list_elem(fd);
	tmp = list;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_list_elem(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, tmp->remainder));
}
