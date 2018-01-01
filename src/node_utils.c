/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 15:10:25 by anazar            #+#    #+#             */
/*   Updated: 2018/01/01 15:13:47 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void 	add_node(t_node *list, t_node *node)
{
	while (list && list->next)
		list = list->next;
	list->next = node;
}
