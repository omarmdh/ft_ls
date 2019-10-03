/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_major.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:34:40 by ommadhi           #+#    #+#             */
/*   Updated: 2019/09/30 17:16:57 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		*ft_strnews(size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i < size)
	{
		str[i] = ' ';
		i++;
	}
	str[size] = '\0';
	return (str);
}

static int		get_max_lent(t_node *dr)
{
	int			max;
	int			lent;

	max = 0;
	while (dr->next)
	{
		lent = ft_strlen(dr->major);
		if (lent >= max)
			max = lent;
		dr = dr->next;
	}
	return (max);
}

int				spaces_major(t_node **dr)
{
	t_node		*ptr;
	char		*ps;
	int			max;
	char		*space;

	ptr = *dr;
	max = get_max_lent(ptr);
	while (ptr->next)
	{
		if (ptr->perm[0] == 'c' || ptr->perm[0] == 'b')
		{
			space = ft_strnews(max - ft_strlen(ptr->major));
			ps = ft_strjoin(space, ptr->major);
			free(ptr->major);
			free(space);
			ptr->major = ft_strdup(ps);
			free(ps);
		}
		else
			ptr->major = ft_strnews(max);
		ptr = ptr->next;
	}
	return (0);
}
