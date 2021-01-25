/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_esc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 08:58:15 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/01/25 08:58:56 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_parse_esc(char *src)
{
	if (!*(src + 1))
		return ('\0');
	else if (*(src + 1) == 'a')
		return ('\a');
	else if (*(src + 1) == 'b')
		return ('\b');
	else if (*(src + 1) == 't')
		return ('\t');
	else if (*(src + 1) == 'n')
		return ('\n');
	else if (*(src + 1) == 'v')
		return ('\v');
	else if (*(src + 1) == 'f')
		return ('\f');
	else if (*(src + 1) == 'r')
		return ('\r');
	else
		return (*(src + 1));
}
