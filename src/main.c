/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2018/01/01 15:12:35 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		parse_room(char *str, t_room *room)
{
	char		*x;
	char		*y;

	if ((x = ft_strchr(str, ' ')))
	{
		if ((y = ft_strchr(x, ' ')))
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
		add_to_table(lemin, r1, r2);
	}
}

void		parse_comment(char *str, t_room *room)
{
	if (*str == '#')
	{
		if (*(str + 1) == '#')
		{
			if (ft_strcmp(str, "##end"))
				room->flag = 2;
			else if (ft_strcmp(str, "##start"))
				room->flag = 1;
		}
		ft_strdel(&str);
	}
}

/*
** Idea is to use GNL to take the input and store it into output
** However, if we parse the information while in GNL we may not need
** output, but for now we will leave until we decide if we should have
** a backup string of the input (aka output), or if we parse everything
** from input in GNL first and we don't need output
*/

int			validate_ants(void)
{
	char		*str;
	int			ants;

	get_next_line(0, &str);
	if (!ft_general_validate("%d", str))
		return (-1);
	ants = ft_atoi(str);
	ft_strdel(&str);
	return (ants);
}

int			main(void)
{
	char		*str;
	int			n_ants;
	t_lemin		lemin;
	t_room		room;

	n_ants = validate_ants();
	if (n_ants == -1)
		error("Invalid number. Please provide a valid number of ants");
	while (get_next_line(0, &str))
	{
		room = new_room();
		if (ft_general_validate(str, "#%s"))
			parse_comment(str, &room);
		if (ft_general_validate(str, "%s %d %d"))
			parse_room(str, &room);
		if (ft_general_validate(str, "%d-%d"))
		{
			lemin.table = (t_row *)ft_memalloc(list_len(lemin.rooms) *
				sizeof(t_row));
			parse_link(str, &lemin);
			ft_strdel(&str);
			break ;
		}
		add_to_rooms(lemin.rooms, &room);
		ft_strdel(&str);
	}
	while (get_next_line(0, &str))
	{
		if (ft_general_validate(str, "#%s"))
			parse_comment(str, &room);
		if (ft_general_validate(str, "%d-%d"))
			parse_link(str, &lemin);
		ft_strdel(&str);
	}
	return (0);
}
