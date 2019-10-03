/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 16:59:14 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 22:25:26 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char				*joinpath(char *dname, char *name)
{
	char			*path;
	char			*ptr;

	ptr = ft_strjoin(name, "/");
	path = ft_strjoin(ptr, dname);
	ft_strdel(&ptr);
	return (path);
}

int					ft_alloc(DIR *dir, t_node **dr, char *name, int op)
{
	t_node			*tmp;
	struct stat		data;

	new_node(dr);
	ft_store(dir, dr, name, op);
	if ((lstat((*dr)->path, &data) == -1))
	{
		while ((*dr)->next)
		{
			ft_strdel(&((*dr)->name));
			ft_strdel(&((*dr)->path));
			tmp = *dr;
			*dr = (*dr)->next;
			free(tmp);
		}
		free(*dr);
		closedir(dir);
		return (0);
	}
	get_all_data(dr, op);
	sort_list(dr, ft_lentlist(*dr), op);
	(op & l || op & g) ? ft_print_all(*dr, op, 0) : aff_list(*dr, op);
	closedir(dir);
	return (1);
}

void				listdir(char *name, int option)
{
	DIR				*dir;
	t_node			*dr;
	char			*path;
	t_node			*head;

	if ((!(dir = opendir(name))) || (ft_alloc(dir, &dr, name, option) == 0))
		return ;
	head = dr;
	while (dr->next)
	{
		if ((dr->perm[0] == 'd' || dr->perm[0] == 'l') &&
				ft_strcmp(dr->name, ".") && ft_strcmp(dr->name, ".."))
		{
			path = joinpath(dr->name, name);
			if (option & R && ft_put4str("\n", path, ":", "\n"))
			{
				if (dr->perm[7] != 'r' && option & R)
					ft_put4str("ft_ls:", dr->name, ":Permission denied", "\n");
				listdir(path, option);
			}
			ft_strdel(&path);
		}
		dr = dr->next;
	}
	free_node(&head);
}

int					ft_ifile(char **tab, int op)
{
	t_node			*dr;
	t_node			*head;
	int				i;
	struct stat		data;

	i = 0;
	new_node(&dr);
	head = dr;
	while (tab[i])
	{
		if (lstat(tab[i], &data) != -1 && !(data.st_mode & S_IFDIR))
		{
			dr->name = ft_strdup(tab[i]);
			dr->path = ft_strdup(dr->name);
			new_node(&(dr->next));
			dr = dr->next;
		}
		i++;
	}
	get_all_data(&head, op);
	(op & l || op & g) ? ft_print_all(head, op, 1) : aff_list(head, op);
	free_node(&head);
	return (0);
}

int					main(int ac, char **av)
{
	char			**tab;
	int				ik[3];
	struct stat		data;

	ik[0] = -1;
	ik[1] = 0;
	ik[2] = flags(av);
	tab = tab_args(ac, av, ik[2]);
	ft_ifile(tab, ik[2]);
	while (tab[++ik[0]])
	{
		if (lstat(tab[ik[0]], &data) != -1 && data.st_mode & S_IFDIR)
		{
			if (tab[1] != NULL && ik[1] == 0 && (ik[1] = 1))
				ft_put4str("", tab[ik[0]], ":", "\n");
			else if (tab[1] != NULL)
				ft_put4str("\n", tab[ik[0]], ":", "\n");
			if (!(data.st_mode & S_IROTH))
				ft_put4str("ft_ls: ", tab[ik[0]], ": Permission denied", "\n");
			listdir(tab[ik[0]], ik[2]);
		}
	}
	free_tab(tab);
	return (0);
}
