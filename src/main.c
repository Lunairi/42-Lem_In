/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/12/21 21:19:17 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		parse_room(char *str, t_room *room)
{
	char		*x;
	char		*y;

	if (x = ft_strchr(str, ' '))
	{
		if (y = ft_strchr(x, ' '))
		{
			room->name = ft_strsub(str, 0, x - str);
			room->x = ft_atoi(x);
			room->y = ft_atoi(y);
		}
	}
}

void		parse_links(char *str, t_link *link)
{
	char		*e;

	if ((e = ft_strchr(str, '-')))
	{
		link->start = ft_strsub(str, 0, e - str);
		link->end = ft_strdup(e + 1);
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
		free(str);
	}
}

void	parse_hub(char *str, ...)

/*
** Idea is to use GNL to take the input and store it into output
** However, if we parse the information while in GNL we may not need
** output, but for now we will leave until we decide if we should have
** a backup string of the input (aka output), or if we parse everything
** from input in GNL first and we don't need output
*/

int			validate_ants(void)
{
	char		*str_cpy;
	char		*str;

	while (get_next_line(0, &str))
	{
		if (!str)
			return (-1);
		str_cpy = str;
		while (*str)
		{
			if (!ft_isdigit(*str))
				break ;
			++str;
		}
		if (!*str)
			break ;
	}
	return (ft_atoi(str_cpy));
}

int			main(void)
{
	char		*str;
	int			n_ants;
	t_room		room;
	t_link		link;

	n_ants = validate_ants();
	while (get_next_line(0, &str) && n_ants != -1)
	{
		parse_comment(str, &room);
		parse_room(str, &room);
		parse_links(str, &link);
	}
	return (0);
}
