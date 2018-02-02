/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 18:45:33 by mlu               #+#    #+#             */
/*   Updated: 2018/02/01 18:45:52 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	free_list(t_node *path)
{
	t_node	*tmp;

	while (path)
	{
		tmp = path->next;
		free(path);
		path = tmp;
	}
}

void	free_str_list(char **lst, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		free(lst[i]);
		++i;
	}
	free(lst);
}

void	free_room_list(t_room *path)
{
	t_room	*tmp;

	while (path)
	{
		tmp = path->next;
		free(path);
		path = tmp;
	}
}

void	free_row(t_lemin *lemin)
{
	size_t	i;

	i = 0;
	while (i < lemin->len)
	{
		free_list(lemin->table[i].links);
		++i;
	}
	free(lemin->table);
}

void	free_all(t_lemin *lemin, t_node *path)
{
	free_str_list(lemin->names, lemin->len);
	free_room_list(lemin->rooms);
	free_row(lemin);
	free_list(path);
}
