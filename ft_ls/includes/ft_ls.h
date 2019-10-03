/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:08:28 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/03 18:10:41 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# include <grp.h>
# include <pwd.h>
# include <time.h>

# define a 1
# define l 2
# define R 4
# define r 8
# define f 16
# define t 32
# define G 64
# define S 128
# define g 256
# define u 512

typedef struct		s_node
{
	char			*name;
	char			*perm;
	char			*usr;
	char			*grp;
	char			*mois;
	char			*time;
	char			*path;
	char			*minor;
	char			*major;
	char			*nlink;
	char			*linkto;
	char			*size_c;
	int				time_s;
	int				size;
	struct s_node	*next;
}					t_node;

void				add_perm(mode_t st_mode, char *perm);
void				sort_list_r(t_node **dr, int count, int option);
int					get_acc_time(t_node *dr);
void				put_color(t_node *dr, int option);
void				ft_putstr_char(char *str, char c, char c1);
int					ft_lentlist(t_node *dr);
void				aff_list(t_node *dr, int option);
void				free_tab(char **tab);
void				ft_print_one(t_node *dr, int option);
char				**tab_args(int ac, char **av, int option);
void				sort_list(t_node **dr, int count, int option);
void				free_node(t_node **d);
void				free_content(t_node **d);
int					ft_put4str(char *s1, char *s2, char *s3, char *s4);
int					permission(t_node *dr);
int					new_node(t_node **dr);
int					ft_store(DIR *rep, t_node **origin, char *path, int option);
void				listdir(char *name, int option);
int					add_all_spaces(t_node **dr);
int					spaces_size_c(t_node **dr);
int					spaces_usr(t_node **dr);
int					spaces_grp(t_node **dr);
int					spaces_minor(t_node **dr);
int					spaces_major(t_node **dr);
int					spaces_nlink(t_node **dr);
void				ft_print_all(t_node *dr, int option, int tot);
int					get_id(t_node *dr);
int					get_time(t_node *dr);
long				nblocks(t_node *dr);
int					min_maj(t_node *dr);
int					put_size(t_node *dr);
int					get_size(t_node *dr);
int					ft_nlink(t_node *dr);
int					filetype(int mode);
int					get_all_data(t_node **dr, int option);
int					ft_readlink(t_node *dr);
int					flags(char **av);

#endif
