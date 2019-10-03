/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rev.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommadhi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:28:12 by ommadhi           #+#    #+#             */
/*   Updated: 2019/10/01 16:30:34 by ommadhi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static t_node	*swap2node(t_node *ptr1, t_node *ptr2)
{
	t_node		*tmp;

	tmp = ptr2->next;
	ptr2->next = ptr1;
	ptr1->next = tmp;
	return (ptr2);
}

void			sort_by_name_r(t_node **head, int count)
{
	t_node		**h;
	int			ij[3];
	t_node		*p1;
	t_node		*p2;

	ij[0] = 0;
	while (ij[0] <= count)
	{
		h = head;
		ij[2] = 0;
		ij[1] = 0;
		while (ij[1] < (count - ij[0] - 1))
		{
			p1 = *h;
			p2 = p1->next;
			if (ft_strcmp(p1->name, p2->name) < 0 && (ij[2] = 1))
				*h = swap2node(p1, p2);
			h = &(*h)->next;
			ij[1]++;
		}
		ij[0]++;
		if (ij[2] == 0)
			break ;
	}
}

void			sort_by_size_r(t_node **head, int count)
{
	t_node		**h;
	int			ij[3];
	t_node		*p1;
	t_node		*p2;

	ij[0] = -1;
	while (ij[0]++ <= count)
	{
		h = head;
		ij[2] = 0;
		ij[1] = 0;
		while (ij[1]++ < (count - ij[0] - 1))
		{
			p1 = *h;
			p2 = p1->next;
			if (p1->size > p2->size && (ij[2] = 1))
				*h = swap2node(p1, p2);
			if (p1->size == p2->size && ft_strcmp(p1->name, p2->name)
					< 0 && (ij[2] = 1))
				*h = swap2node(p1, p2);
			h = &(*h)->next;
		}
		if (ij[2] == 0)
			break ;
	}
}

void			sort_by_moditime_r(t_node **head, int count)
{
	t_node		**h;
	int			ij[3];
	t_node		*p1;
	t_node		*p2;

	ij[0] = -1;
	while (ij[0]++ <= count)
	{
		h = head;
		ij[2] = 0;
		ij[1] = 0;
		while (ij[1]++ < (count - ij[0] - 1))
		{
			p1 = *h;
			p2 = p1->next;
			if (p1->time_s > p2->time_s && (ij[2] = 1))
				*h = swap2node(p1, p2);
			if (p1->time_s == p2->time_s && ft_strcmp(p1->name, p2->name)
					< 0 && (ij[2] = 1))
				*h = swap2node(p1, p2);
			h = &(*h)->next;
		}
		if (ij[2] == 0)
			break ;
	}
}

void			sort_list_r(t_node **dr, int count, int option)
{
	if (option & f)
		return ;
	else if (option & t)
		sort_by_moditime_r(dr, count);
	else if (option & S)
		sort_by_size_r(dr, count);
	else
		sort_by_name_r(dr, count);
}
