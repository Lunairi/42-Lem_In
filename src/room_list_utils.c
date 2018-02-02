/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 12:10:14 by anazar            #+#    #+#             */
/*   Updated: 2018/02/01 21:19:22 by mlu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_room	*new_room(void)
{
	t_room	*new;

	new = (t_room *)ft_memalloc(sizeof(t_room));
	new->name = NULL;
	new->x = 0;
	new->y = 0;
	new->flag = 0;
	new->next = NULL;
	return (new);
}

size_t	list_len(t_room *room)
{
	size_t	i;

	i = 0;
	while (room)
	{
		room = room->next;
		++i;
	}
	return (i);
}

void	add_to_rooms(t_lemin *lemin, t_room *room)
{
	t_room	*rp;

	rp = lemin->rooms;
	if (!rp)
	{
		lemin->rooms = room;
		return ;
	}
	while (rp && rp->next)
		rp = rp->next;
	rp->next = room;
}
