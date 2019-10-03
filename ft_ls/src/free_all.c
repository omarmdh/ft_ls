/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 17:23:36 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/01 16:55:18 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			free_tab(char **tab)
{
	int			i;
	int			size;

	i = 0;
	size = 0;
	while (tab[size])
		size++;
	while (i < size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
}

void			free_content(t_node **d)
{
	t_node		*dr;

	dr = *d;
	if (dr->perm[0] == 'l')
		free(dr->linkto);
	ft_strdel(&dr->usr);
	ft_strdel(&dr->grp);
	ft_strdel(&dr->mois);
	ft_strdel(&dr->time);
	ft_strdel(&dr->major);
	ft_strdel(&dr->minor);
	ft_strdel(&dr->nlink);
	ft_strdel(&dr->size_c);
	ft_strdel(&dr->perm);
	ft_strdel(&dr->path);
	ft_strdel(&dr->name);
}

void			free_node(t_node **d)
{
	t_node		*dr;
	t_node		*ptr;

	dr = *d;
	while (dr->next)
	{
		ptr = dr->next;
		free_content(&dr);
		free(dr);
		dr = ptr;
	}
	free(dr);
}
