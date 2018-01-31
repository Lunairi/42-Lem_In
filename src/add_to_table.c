/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 13:16:36 by anazar            #+#    #+#             */
/*   Updated: 2018/01/30 18:23:36 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void 	mod(t_row *row, size_t to_add)
{
	t_node	*node;

	node = (t_node *)ft_memalloc(sizeof(t_node));
	node->num = to_add;
	node->next = NULL;
	add_node(row, node);
}

void 	add_to_table(t_lemin *lemin, char *r1, char *r2)
{
	size_t	r1_i;
	size_t	r2_i;
	int		flag1;
	int		flag2;

	r1_i = hash(lemin, r1, &flag1);
	r2_i = hash(lemin, r2, &flag2);
	lemin->table[r1_i].flag = flag1;
	lemin->table[r2_i].flag = flag2;
	mod(&lemin->table[r1_i], r2_i);
	mod(&lemin->table[r2_i], r1_i);
}
