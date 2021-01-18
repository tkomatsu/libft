/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnotformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:34:03 by tkomatsu          #+#    #+#             */
/*   Updated: 2020/08/13 16:12:30 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -----------------------------------------------------------------------------
** utility
**
** If character is format character, return 1. Otherwise return 0.
** -----------------------------------------------------------------------------
*/

int	ft_isnotformat(int c)
{
	if (ft_isconvert(c) || ft_isdigit(c) || ft_isspace(c) || ft_isflag(c)
		|| c == '.' || c == '*')
		return (0);
	return (1);
}
