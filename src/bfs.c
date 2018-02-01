/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 14:13:54 by anazar            #+#    #+#             */
/*   Updated: 2018/01/31 17:27:44 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void add_to_path(t_node *path, size_t start)
{
    t_node	*tmp;
    t_node  *node;

	tmp = path;
    node = (t_node *)ft_memalloc(sizeof(t_node));
    node->num = start;
    node->next = NULL;
	if (!tmp)
	{
		path = node;
		return ;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

t_node	*bfs(t_lemin *lemin)
{
    t_node  *path;
    t_node  *tmp;
    t_queue *queue;
    size_t  start;

    start = lemin->start;
    lemin->table[start].checked = 1;
    queue = init();
    enqueue(queue, start);
    while (!isEmpty(queue))
    {
        start = dequeue(queue);
        add_to_path(path, start);
        if (start == lemin->end)
            break;
        tmp = lemin->table[start].links;
        while (tmp)
        {
            if (!lemin->table[start].checked)
            {
                lemin->table[start].checked = 1;
                enqueue(queue, start);
            }
        }
    }
    return (path);
}
