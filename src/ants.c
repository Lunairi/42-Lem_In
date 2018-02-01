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

void	check_ants(t_lemin *lemin, t_node *tmp, int *i, int *q_ants)
{
	int x;

	x = 0;
	while (tmp) 
	{
		if (!tmp->next && tmp->ant)
			*i = *i + 1;
		else if (tmp->ant == 0)
		{
			tmp->ant = *i + 1;
			if (tmp->next && tmp->ant && x != 0)
				printf("L%zu-%s", tmp->ant, lemin->names[tmp->num]);
			break;
		}
		else
		{
			if (tmp->ant < *q_ants)
			{
				tmp->ant = tmp->ant + 1;
				if (x != 0)
					printf("L%zu-%s ", tmp->ant, lemin->names[tmp->num]);
			}
		}
		tmp = tmp->next;
		x++;
	}
	if (x != 0)
		printf("\n");
}

void	move_ants(t_lemin *lemin, t_node *path)
{
	t_node 	*tmp;
	char	**nodes;
	int 	q_ants;
	int		i;

	i  = 0;
	tmp = path;
	q_ants = lemin->ants;
	while (i != lemin->ants)
	{
		check_ants(lemin, tmp, &i, &q_ants);
	}
}

