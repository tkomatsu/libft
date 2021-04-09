/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 09:58:38 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/04/09 10:12:21 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	memerr(char **s1, char **s2, int flag)
{
	free(*s1);
	free(*s2);
	return (flag);
}

static int	rewrite(char **s1, char **s2)
{
	char	*tmp;

	tmp = ft_strjoin(*s1, *s2);
	free(*s1);
	if (tmp == NULL)
	{
		free(*s2);
		return (-1);
	}
	*s1 = tmp;
	return (0);
}

static int	save_line(int fd, char **line, char **buf)
{
	char	*tmp;

	tmp = ft_strchr(buf[fd], '\n');
	if (tmp)
	{
		*tmp = 0;
		*line = ft_strdup(buf[fd]);
		if (!*line)
			return (memerr(line, buf + fd, -1));
		tmp = ft_strdup(tmp + 1);
		if (!tmp)
			return (memerr(line, buf + fd, -1));
		free(buf[fd]);
		buf[fd] = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(buf[fd]);
		if (!*line)
			return (memerr(line, buf + fd, -1));
		free(buf[fd]);
		buf[fd] = NULL;
		return (0);
	}
}

static int	finish(int fd, char **line, char **buf, int rdno)
{
	if (rdno < 0)
		return (-1);
	if (!buf[fd])
	{
		*line = ft_strdup("");
		return (0);
	}
	return (save_line(fd, line, buf));
}

int	get_next_line(int fd, char **line)
{
	static char	*buf[STATIC_MAX];
	char		*rdbuf;
	int			rdno;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	rdbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!rdbuf)
		return (-1);
	rdno = read(fd, rdbuf, BUFFER_SIZE);
	while (rdno > 0)
	{
		rdbuf[rdno] = 0;
		if (rewrite(&buf[fd], &rdbuf) < 0)
			return (-1);
		if (ft_strchr(buf[fd], '\n'))
		{
			free(rdbuf);
			return (save_line(fd, line, buf));
		}
		rdno = read(fd, rdbuf, BUFFER_SIZE);
	}
	free(rdbuf);
	return (finish(fd, line, buf, rdno));
}
