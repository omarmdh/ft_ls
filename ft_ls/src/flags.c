/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 22:52:18 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 18:10:33 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putstr_char(char *str, char c, char c1)
{
	ft_putstr(str);
	ft_putchar(c);
	ft_putchar(c1);
}

int		add_option(int *option, char **av)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (av[j])
	{
		i = 0;
		while (av[j][i] && av[j][0] == '-')
		{
			((av[j][i] == 'u') && (!(*option & u))) ? *option += u : 0;
			((av[j][i] == 'G') && (!(*option & G))) ? *option += G : 0;
			((av[j][i] == 'a') && (!(*option & a))) ? *option += a : 0;
			((av[j][i] == 'R') && (!(*option & R))) ? *option += R : 0;
			((av[j][i] == 'l') && (!(*option & l))) ? *option += l : 0;
			((av[j][i] == 'r') && (!(*option & r))) ? *option += r : 0;
			((av[j][i] == 'f') && (!(*option & f))) ? *option += f : 0;
			((av[j][i] == 't') && (!(*option & t))) ? *option += t : 0;
			((av[j][i] == 'S') && (!(*option & S))) ? *option += S : 0;
			((av[j][i] == 'g') && (!(*option & g))) ? *option += g : 0;
			i++;
		}
		j++;
	}
	return (1);
}

int		flags(char **av)
{
	int option;
	int i;
	int j;

	j = 0;
	option = 0;
	while (av[++j])
	{
		i = 1;
		while (av[j][i] && av[j][0] == '-')
		{
			if (av[j][i] != 'a' && av[j][i] != 'l' &&
			av[j][i] != 'R' && av[j][i] != 'r' &&
			av[j][i] != 'f' && av[j][i] != 't' && av[j][i] != 'u' &&
			av[j][i] != 'G' && av[j][i] != 'S' && av[j][i] != 'g')
			{
				ft_putstr_char("ft_ls: illegal option -- ", av[j][i], '\n');
				ft_putstr("usage: ./ft_ls [-alRruftGgS] [file ...]\n");
				exit(0);
			}
			i++;
		}
	}
	add_option(&option, av);
	return (option);
}
