/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lastaccess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:43:55 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/01 16:52:55 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int					get_acc_time(t_node *dr)
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
		dr->time_s = data.st_atime;
		mod_time = ctime(&data.st_atime);
		dr->mois = ft_strsub(mod_time, 4, 7);
		yearf = ft_strsub(ctime(&data.st_atime), 20, 4);
		yearn = ft_strsub(ctime(&curtime), 20, 4);
		if (ft_strcmp(yearf, yearn) != 0)
			dr->time = ft_strsub(ctime(&data.st_atime), 19, 5);
		else
			dr->time = ft_strsub(ctime(&data.st_atime), 11, 5);
		ft_strdel(&yearn);
		ft_strdel(&yearf);
		dr = dr->next;
	}
	return (0);
}
