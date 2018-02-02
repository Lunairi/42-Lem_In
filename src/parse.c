/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2018/01/31 18:15:05 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		parse_room(char *str, t_room *room)
{
	char		*x;
	char		*y;

	if ((x = ft_strchr(str, ' ')))
	{
		if ((y = ft_strchr(x + 1, ' ')))
		{
			room->name = ft_strsub(str, 0, x - str);
			room->x = ft_atoi(x);
			room->y = ft_atoi(y);
		}
	}
}

void		parse_link(char *str, t_lemin *lemin)
{
	char		*r2;
	char		*r1;

	if ((r2 = ft_strchr(str, '-')))
	{
		r1 = ft_strsub(str, 0, r2 - str);
		r2 = ft_strdup(ft_strchr(str, '-'));
		add_to_table(lemin, r1, r2 + 1);
		free(r1);
		free(r2);
	}
}

char		*parse_comment(char *str, t_room *room, t_lemin *lemin)
{
	if (*str == '#')
	{
		if (*(str + 1) == '#')
		{
			if (!ft_strcmp(str, "##end"))
			{
				lemin->finish++;
				room->flag = 2;
			}
			else if (!ft_strcmp(str, "##start"))
			{
				lemin->begin++;
				room->flag = 1;
			}
		}
		ft_strdel(&str);
		get_next_line(0, &str);
		if (room->flag >= 1 && !ft_general_validate("%s %d %d", str))
			error("Input is invalid");
	}
	return (str);
}

void		print_rooms(t_room *rooms)
{
	while (rooms)
	{
		ft_putendl(rooms->name);
		rooms = rooms->next;
	}
}
