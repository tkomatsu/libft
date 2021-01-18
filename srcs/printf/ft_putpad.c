/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 19:30:39 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/13 16:55:54 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** utility
**
** put padding character the length of len
** -----------------------------------------------------------------------------
*/

void	ft_putpad(size_t len, char padchar)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		ft_putchar_fd(padchar, 1);
		i++;
	}
}