/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:32:15 by anazar            #+#    #+#             */
/*   Updated: 2018/01/30 18:28:59 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void print_table(t_row *table, size_t len)
{
    size_t i;
    t_node  *tmp;

    i = 0;
    while (i < len)
    {
        ft_putnbr(i);
        ft_putchar(':');
        tmp = table[i].links;
        while (tmp)
        {
            ft_putnbr(tmp->num);
            ft_putstr("->");
            tmp = tmp->next;
        }
        ft_putstr("NULL\n");
        ++i;
    }
}
