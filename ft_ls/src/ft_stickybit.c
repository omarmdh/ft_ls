/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stickybit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:59:46 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 18:22:34 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	add_perm(mode_t st_mode, char *perm)
{
	if (st_mode & S_ISUID)
		perm[3] = (st_mode & S_IXUSR) ? 's' : 'S';
	if (st_mode & S_ISGID)
		perm[6] = (st_mode & S_IXGRP) ? 's' : 'S';
	if (st_mode & S_ISVTX)
		perm[9] = (st_mode & S_IXOTH) ? 't' : 'T';
}
