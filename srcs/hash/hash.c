/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomatsu <tkomatsu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:06:43 by tkomatsu          #+#    #+#             */
/*   Updated: 2021/05/21 16:31:13 by tkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_hash(char *key)
{
	int	len;
	int	ret;

	len = ft_strlen(key);
	ret = key[0];
	ret += key[len - 1];
	ret += key[(len - 1) / 2];
	return (ret % HASHSIZE);
}

void	set_value(t_hash **list, char *key, char *value)
{
	t_hash	*add;
	int		hash;
	t_hash	*at;

	hash = get_hash(key);
	if (list[hash] == NULL)
	{
		add = malloc(sizeof(t_hash));
		add->name = ft_strdup(key);
		add->value = ft_strdup(value);
		add->next = NULL;
		list[hash] = add;
	}
	else
	{
		at = list[hash];
		while (at)
		{
			if (ft_strcmp(at->name, key) == 0)
			{
				at->value = ft_strdup(value);
				return ;
			}
			at = at->next;
		}
		add = malloc(sizeof(t_hash));
		add->name = ft_strdup(key);
		add->value = ft_strdup(value);
		add->next = list[hash];
		list[hash] = add;
	}
}

char	*get_value(t_hash **list, char *key)
{
	int		hash;
	t_hash	*at;

	hash = get_hash(key);
	if (list[hash] == NULL)
	{
		return (NULL);
	}
	else
	{
		at = list[hash];
		while (at)
		{
			if (ft_strcmp(at->name, key) == 0)
			{
				return (at->value);
			}
			at = at->next;
		}
		return (NULL);
	}
}
