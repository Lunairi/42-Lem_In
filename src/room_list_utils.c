/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 12:10:14 by anazar            #+#    #+#             */
/*   Updated: 2018/01/01 12:33:04 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_room	new_room(void)
{
	t_room	new;

	new.name = NULL;
	new.x = 0;
	new.y = 0;
	new.flag = 0;
	new.next = NULL;
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

void	add_to_rooms(t_room *rooms, t_room room)
{
	while (rooms && rooms->next)
		rooms = rooms->next;
	rooms->next = &room;
}
