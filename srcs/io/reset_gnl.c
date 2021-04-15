/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_gnl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:31:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/04/15 13:58:32 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	reset_gnl(int fd, char **buf)
{
	int	i;

	if (fd == -1)
	{
		i = 0;
		while (i < STATIC_MAX)
			free(buf[i++]);
	}
	return (-1);
}
