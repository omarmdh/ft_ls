/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloclist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:13:36 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 22:18:18 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					ft_readlink(t_node *dr)
{
	char	*buf;

	while (dr->next)
	{
		if (dr->perm[0] == 'l')
		{
			buf = ft_strnew(1024);
			readlink(dr->path, buf, sizeof(buf) - 1);
			dr->linkto = buf;
		}
		dr = dr->next;
	}
	return (0);
}

int					new_node(t_node **dr)
{
	*dr = (t_node *)malloc(sizeof(t_node));
	(*dr)->next = NULL;
	return (0);
}

int					ft_store(DIR *rep, t_node **origin, char *path, int option)
{
	struct dirent	*data;
	t_node			*head;
	struct stat		dt;
	char			*p;

	head = *origin;
	while ((data = readdir(rep)))
	{
		if (!(option & a || option & f) && data->d_name[0] == '.')
			continue;
		lstat(path, &dt);
		if (S_ISDIR(dt.st_mode))
		{
			p = ft_strjoin(path, "/");
			(*origin)->path = ft_strjoin(p, data->d_name);
			free(p);
		}
		else
			(*origin)->path = ft_strdup(data->d_name);
		(*origin)->name = ft_strdup(data->d_name);
		new_node(&(*origin)->next);
		(*origin) = (*origin)->next;
	}
	*origin = head;
	return (0);
}

int					get_all_data(t_node **dr, int op)
{
	permission(*dr);
	get_id(*dr);
	get_size(*dr);
	put_size(*dr);
	if (op & u)
		get_acc_time(*dr);
	else
		get_time(*dr);
	min_maj(*dr);
	ft_nlink(*dr);
	ft_readlink(*dr);
	add_all_spaces(dr);
	return (0);
}
