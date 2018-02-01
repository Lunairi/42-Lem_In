/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2018/01/31 18:15:05 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		print_ant(t_lemin *lemin, t_node *tmp)
{
	if (lemin->print > 0)
		write(1, " ", 1);
	write(1, "L", 1);
	ft_putnbr(tmp->ant);
	write(1, "-", 1);
	ft_putstr(lemin->names[tmp->num]);
	++lemin->print;
}

void		check_ants(t_lemin *lemin, t_node *tmp, int *i)
{
	while (tmp && ++lemin->count >= 0)
	{
		if (!tmp->next && tmp->ant)
			*i = *i + 1;
		else if (tmp->ant == 0)
		{
			tmp->ant = *i + 1;
			if (tmp->next && tmp->ant && lemin->count != 0)
				print_ant(lemin, tmp);
			break ;
		}
		else
		{
			if (tmp->ant < lemin->ants)
			{
				tmp->ant = tmp->ant + 1;
				if (lemin->count != 0)
					print_ant(lemin, tmp);
			}
		}
		tmp = tmp->next;
	}
}

void		move_ants(t_lemin *lemin, t_node *path)
{
	t_node	*tmp;
	char	**nodes;
	int		i;

	i = 0;
	tmp = path;
	while (i != lemin->ants)
	{
		lemin->count = -1;
		lemin->print = 0;
		check_ants(lemin, tmp, &i);
		if (lemin->print > 0)
			write(1, "\n", 1);
	}
}
