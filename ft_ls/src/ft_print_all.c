/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:02:47 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/01 16:51:28 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	aff_list(t_node *dr, int option)
{
	while (dr->next)
	{
		if (dr->name)
			put_color(dr, option);
		dr = dr->next;
	}
}

void	put_color(t_node *dr, int option)
{
	if (dr->perm[0] == 'd' && option & G)
		ft_put4str("\033[1;36m", dr->name, "\n", "\033[0m");
	else if (dr->perm[0] == 's' && option & G)
		ft_put4str("\033[0;32m", dr->name, "\n", "\033[0m");
	else if (dr->perm[0] == '-' && dr->perm[9] == 'x' && option & G)
		ft_put4str("\033[0;31m", dr->name, "\n", "\033[0m");
	else if (dr->perm[0] == 'p' && option & G)
		ft_put4str("\033\e[33m", dr->name, "\n", "\033[0m");
	else if (dr->perm[0] == 'l' && option & G)
	{
		ft_put4str("\033[0;35m", dr->name, "\033[0m", "");
		(!(option & l)) ? ft_putchar('\n') : 0;
		if (option & l)
			ft_put4str("", " -> ", dr->linkto, "\n");
	}
	else
		ft_put2str(dr->name, "\n");
}

void	ft_print_total(t_node *dr, int option)
{
	if (option & l || option & g)
	{
		ft_putstr("total ");
		ft_putnbr(nblocks(dr));
		ft_putchar('\n');
	}
}

void	ft_print_all(t_node *dr, int option, int tot)
{
	(tot == 0) ? ft_print_total(dr, option) : 0;
	while (dr->next)
	{
		ft_put2str(dr->perm, "  ");
		ft_put2str(dr->nlink, " ");
		(!(option & g)) ? ft_put2str(dr->usr, "  ") : 0;
		ft_put2str(dr->grp, "  ");
		if (dr->perm[0] != 'b' && dr->perm[0] != 'c')
			ft_put2str(dr->size_c, " ");
		if (dr->perm[0] == 'c' || dr->perm[0] == 'b')
		{
			ft_put2str(dr->major, " ");
			ft_put2str(dr->minor, " ");
		}
		ft_putstr(dr->mois);
		ft_put2str(dr->time, " ");
		put_color(dr, option);
		dr = dr->next;
	}
}
