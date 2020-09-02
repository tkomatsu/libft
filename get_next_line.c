/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 09:58:38 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/27 19:42:04 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -----------------------------------------------------------------------------
** エラー処理
**
** s1,s2をフリーしてflagを返す
** -----------------------------------------------------------------------------
*/

static int	gnl_memerr(char **s1, char **s2, int flag)
{
	free(*s1);
	free(*s2);
	return (flag);
}

/*
** -----------------------------------------------------------------------------
** 追記処理
**
** srcをdstの末尾に追記して、srcのメモリを開放する
** メモリエラー時は-1を返し、成功したら0を返す
** -----------------------------------------------------------------------------
*/

static int	gnl_rewrite(char **s1, char **s2)
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

/*
** -----------------------------------------------------------------------------
** 最終処理
**
** flag == 0の時、lineにbuf[fd]をコピーして、buf[fd]をフリーして0を返す
** flag > 0の時、lineにbuf[fd]の改行までをコピーして、buf[fd]を改行以降にし、1を返す
** -----------------------------------------------------------------------------
*/

static int	gnl_return(int fd, char **line, char **buf, int flag)
{
	char	*tmp;

	if (flag > 0)
	{
		tmp = ft_strchr(buf[fd], '\n');
		*tmp = 0;
		if (!(*line = ft_strdup(buf[fd])))
			return (gnl_memerr(line, buf + fd, -1));
		if (!(tmp = ft_strdup(tmp + 1)))
			return (gnl_memerr(line, buf + fd, -1));
		free(buf[fd]);
		buf[fd] = tmp;
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(buf[fd])))
			return (gnl_memerr(line, buf + fd, -1));
		free(buf[fd]);
		buf[fd] = NULL;
		return (0);
	}
}

/*
** -----------------------------------------------------------------------------
** 例外処理
**
** 空文字を返す
** -----------------------------------------------------------------------------
*/

static int	gnl_empty(char **line)
{
	*line = ft_strdup("");
	return (0);
}

/*
** -----------------------------------------------------------------------------
** 全体の流れ
**
** rdbufのメモリを確保する
** malloc失敗や初期条件がエラーの場合、return (-1)
** readを繰り返す
** readの返り値が1以上の時、
**   readで読みこんだstringをNULL終端処理する
**   buf[fd]の末尾にrdbufを結合する
**   buf[fd]に改行が含まれてたら、lineに格納して処理終了
** read bufferを解放する
** readが失敗した時、エラーを返す
** buf[fd]がNULLポインタだった時（初期値）空文字をlineに格納して終了
** 改行が含まれる場合と含まれない場合で分けてgnl_returnに渡して終了
** -----------------------------------------------------------------------------
*/

int			get_next_line(int fd, char **line)
{
	static char *buf[OPEN_MAX];
	char		*rdbuf;
	int			rdno;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(rdbuf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rdno = read(fd, rdbuf, BUFFER_SIZE)) > 0)
	{
		rdbuf[rdno] = 0;
		if (gnl_rewrite(&buf[fd], &rdbuf) < 0)
			return (-1);
		if (ft_strchr(buf[fd], '\n'))
		{
			free(rdbuf);
			return (gnl_return(fd, line, buf, 1));
		}
	}
	free(rdbuf);
	if (rdno < 0)
		return (-1);
	if (!buf[fd])
		return (gnl_empty(line));
	return (gnl_return(fd, line, buf, (ft_strchr(buf[fd], '\n') ? 1 : 0)));
}
