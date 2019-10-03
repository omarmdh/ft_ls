/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:26:24 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 20:13:51 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					put_size(t_node *dr)
{
	while (dr->next)
	{
		if (dr->perm[0] == 'b' || dr->perm[0] == 'c')
			dr->size_c = ft_strnew(1);
		else
			dr->size_c = ft_itoa(dr->size);
		dr = dr->next;
	}
	return (0);
}

int					get_size(t_node *dr)
{
	struct stat		data;

	while (dr->next)
	{
		if (lstat(dr->path, &data) == 0)
			dr->size = data.st_size;
		dr = dr->next;
	}
	return (0);
}

int					ft_nlink(t_node *dr)
{
	struct stat		data;

	while (dr->next)
	{
		if (lstat(dr->path, &data) == 0)
			dr->nlink = ft_itoa(data.st_nlink);
		dr = dr->next;
	}
	return (0);
}

int					filetype(int mode)
{
	char			c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

int					permission(t_node *dr)
{
	struct stat		data;

	while (dr->next)
	{
		dr->perm = ft_strnew(11);
		if (lstat(dr->path, &data) == 0)
		{
			dr->perm[0] = filetype(data.st_mode);
			dr->perm[1] = (data.st_mode & S_IRUSR) ? 'r' : '-';
			dr->perm[2] = (data.st_mode & S_IWUSR) ? 'w' : '-';
			dr->perm[3] = (data.st_mode & S_IXUSR) ? 'x' : '-';
			dr->perm[4] = (data.st_mode & S_IRGRP) ? 'r' : '-';
			dr->perm[5] = (data.st_mode & S_IWGRP) ? 'w' : '-';
			dr->perm[6] = (data.st_mode & S_IXGRP) ? 'x' : '-';
			dr->perm[7] = (data.st_mode & S_IROTH) ? 'r' : '-';
			dr->perm[8] = (data.st_mode & S_IWOTH) ? 'w' : '-';
			dr->perm[9] = (data.st_mode & S_IXOTH) ? 'x' : '-';
			add_perm(data.st_mode, dr->perm);
		}
		dr = dr->next;
	}
	return (0);
}
