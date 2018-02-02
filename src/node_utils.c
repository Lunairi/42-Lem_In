/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 15:10:25 by anazar            #+#    #+#             */
/*   Updated: 2018/01/30 18:24:38 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int			not_in(size_t val, t_node *tmp)
{
	while (tmp)
	{
		if (val == tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void		add_node(t_row *row, t_node *node)
{
	t_node	*tmp;

	tmp = row->links;
	if (!tmp)
	{
		row->links = node;
		return ;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void		find_start_end(t_lemin *lemin)
{
	t_room *tmp;
	size_t i;

	i = 0;
	tmp = lemin->rooms;
	while (tmp)
	{
		if (tmp->flag == 1)
			lemin->start = i;
		else if (tmp->flag == 2)
			lemin->end = i;
		i++;
		tmp = tmp->next;
	}
}
