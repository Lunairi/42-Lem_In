/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:45:00 by anazar            #+#    #+#             */
/*   Updated: 2018/02/01 00:39:04 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	add_to_path(t_node **path, size_t start)
{
	t_node	*tmp;
	t_node	*node;

	tmp = *path;
	node = (t_node *)ft_memalloc(sizeof(t_node));
	node->num = start;
	node->next = NULL;
	if (!tmp)
	{
		*path = node;
		return ;
	}
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

int		shuffle_queue(t_lemin *lemin, t_node *tmp, t_queue *queue, t_node *path)
{
	while (tmp)
	{
		if (tmp->num == lemin->end)
		{
			add_to_path(&path, tmp->num);
			return (1);
		}
		if (!lemin->table[tmp->num].checked)
		{
			lemin->table[tmp->num].checked = 1;
			enqueue(queue, tmp->num);
			while (not_in(peek(queue), tmp))
			{
				enqueue(queue, dequeue(queue));
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int		valid_path(t_node *path, size_t start, size_t end)
{
	if (path->num != start)
		return (0);
	while (path && path->next)
		path = path->next;
	if (path->num != end)
		return (0);
	return (1);
}

t_node	*ret(t_queue *queue, t_node *path)
{
	while (!is_empty(queue))
		dequeue(queue);
	free(queue);
	return (path);
}

t_node	*bfs(t_lemin *lemin, size_t start)
{
	t_node	*path;
	t_node	*tmp;
	t_queue	*queue;
	t_node	*tmp_path;

	path = NULL;
	start = lemin->start;
	lemin->table[start].checked = 1;
	queue = init();
	enqueue(queue, start);
	while (!is_empty(queue))
	{
		start = dequeue(queue);
		add_to_path(&path, start);
		tmp_path = path;
		while (tmp_path)
			tmp_path = tmp_path->next;
		tmp = lemin->table[start].links;
		if (shuffle_queue(lemin, tmp, queue, path))
			return (ret(queue, path));
	}
	if (!valid_path(path, lemin->start, lemin->end))
		error("Input is invalid");
	free(queue);
	return (path);
}
