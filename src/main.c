/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2018/01/31 18:15:05 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	if (!ft_general_validate("%d", str) || str[0] == '-')
		return (0);
	ants = ft_atoi(str);
	ft_strdel(&str);
	return (ants);
}

t_lemin		init_lemin(void)
{
	t_lemin	l;

	l.rooms = NULL;
	l.table = NULL;
	l.len = 0;
	l.finish = 0;
	l.begin = 0;
	return (l);
}

void		switch_link(t_lemin *lemin, char *str)
{
	lemin->len = list_len(lemin->rooms);
	lemin->table = (t_row *)ft_memalloc(lemin->len * sizeof(t_row));
	get_names(lemin);
	parse_link(str, lemin);
	ft_strdel(&str);
}

void		setup_room(t_lemin *lemin, char *str, int flag)
{
	t_room	*room;

	while (get_next_line(0, &str))
	{
		room = new_room();
		if (ft_general_validate("#%s", str))
			str = parse_comment(str, room, lemin);
		if (ft_general_validate("%s %d %d", str))
			parse_room(str, room);
		else if (ft_general_validate("%s-%s", str) && ++flag)
		{
			switch_link(lemin, str);
			break ;
		}
		else
			error("Input is invalid");
		add_to_rooms(lemin, room);
		ft_strdel(&str);
	}
	free(room);
	if (lemin->begin != 1 || lemin->finish != 1 || !flag)
		error("Input is invalid");
}

int			main(void)
{
	char		*str;
	t_lemin		lemin;
	t_room		room;
	t_node		*path;

	lemin = init_lemin();
	lemin.ants = validate_ants();
	if (lemin.ants == 0)
		error("Input is invalid");
	setup_room(&lemin, str, 0);
	while (get_next_line(0, &str))
	{
		if (ft_general_validate("#%s", str))
			str = parse_comment(str, &room, &lemin);
		if (ft_general_validate("%s-%s", str))
			parse_link(str, &lemin);
		ft_strdel(&str);
	}
	if (lemin.begin != 1 || lemin.finish != 1)
		error("Input is invalid");
	find_start_end(&lemin);
	path = bfs(&lemin, 0);
	move_ants(&lemin, path);
	free_all(&lemin, path);
	return (0);
}
