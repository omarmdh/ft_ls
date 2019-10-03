/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_all_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:28:40 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 22:27:15 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		add_all_spaces(t_node **dr)
{
	if (*dr != NULL && (*dr)->next != NULL)
	{
		spaces_size_c(dr);
		spaces_usr(dr);
		spaces_grp(dr);
		spaces_minor(dr);
		spaces_major(dr);
		spaces_nlink(dr);
	}
	return (0);
}
