/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:21:22 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/01 16:47:02 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					nlink(t_node *dr)
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

int					get_id(t_node *dr)
{
	struct group	*grp;
	struct passwd	*usr;
	struct stat		data;

	while (dr->next)
	{
		if (lstat(dr->path, &data) == 0)
		{
			usr = getpwuid(data.st_uid);
			grp = getgrgid(data.st_gid);
			dr->usr = ft_strdup(usr->pw_name);
			dr->grp = ft_strdup(grp->gr_name);
		}
		dr = dr->next;
	}
	return (0);
}

int					get_time(t_node *dr)
{
	char			*mod_time;
	struct stat		data;
	time_t			curtime;
	char			*yearn;
	char			*yearf;

	time(&curtime);
	while (dr->next)
	{
		lstat(dr->path, &data);
		dr->time_s = data.st_mtime;
		mod_time = ctime(&data.st_mtime);
		dr->mois = ft_strsub(mod_time, 4, 7);
		yearf = ft_strsub(ctime(&data.st_mtime), 20, 4);
		yearn = ft_strsub(ctime(&curtime), 20, 4);
		if (ft_strcmp(yearf, yearn) != 0)
			dr->time = ft_strsub(ctime(&data.st_mtime), 19, 5);
		else
			dr->time = ft_strsub(ctime(&data.st_mtime), 11, 5);
		ft_strdel(&yearn);
		ft_strdel(&yearf);
		dr = dr->next;
	}
	return (0);
}

long				nblocks(t_node *dr)
{
	long			n;
	struct stat		data;

	n = 0;
	while (dr->next)
	{
		lstat(dr->path, &data);
		n = n + data.st_blocks;
		dr = dr->next;
	}
	return (n);
}

int					min_maj(t_node *dr)
{
	int				maj;
	int				min;
	char			*strmaj;
	struct stat		data;

	while (dr->next)
	{
		lstat(dr->path, &data);
		if (dr->perm[0] == 'c' || dr->perm[0] == 'b')
		{
			maj = major(data.st_rdev);
			min = minor(data.st_rdev);
			strmaj = ft_itoa(maj);
			dr->major = ft_strjoin(strmaj, ",");
			dr->minor = ft_itoa(min);
			free(strmaj);
		}
		else
		{
			dr->major = "\0";
			dr->minor = "\0";
		}
		dr = dr->next;
	}
	return (0);
}
