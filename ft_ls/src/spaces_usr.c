/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_usr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:35:35 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 22:34:08 by ommadhi          ###   ########.fr       */
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
		lent = ft_strlen(dr->usr);
		if (lent >= max)
			max = lent;
		dr = dr->next;
	}
	return (max);
}

int				spaces_usr(t_node **dr)
{
	t_node		*ptr;
	ptr = *dr;
	char		*ps;
	int			max;
	char		*space;

	ptr = *dr;
	max = get_max_lent(ptr);
	while (ptr->next)
	{
		space = ft_strnews(max - ft_strlen(ptr->usr));
		ps = ft_strjoin(ptr->usr, space);
		free(ptr->usr);
		free(space);
		ptr->usr = ft_strdup(ps);
		free(ps);
		ptr = ptr->next;
	}
	return (0);
}
