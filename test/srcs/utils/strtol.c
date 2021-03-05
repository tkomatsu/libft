/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 18:36:12 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/03/04 18:45:33 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	test_strtol(char *str, char **endptr, int base)
{
	int		errno_original, errno_ft;
	long	ret_original, ret_ft;

	ret_original = strtol(str, endptr, base);
	errno_original = errno;
	ret_ft = ft_strtol(str, endptr, base);
	errno_ft = errno;
	if (ret_original != ret_ft)
		dprintf(stderr, "\"%s\" => %ld expected, but got %ld.\n", str, ret_original, ret_ft);
}
