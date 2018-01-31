/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:32:15 by anazar            #+#    #+#             */
/*   Updated: 2018/01/30 20:49:21 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

//void print_table(t_row *table, size_t len)
void print_table(t_lemin lemin)
{
    size_t i;
    t_node  *tmp;

    i = 0;
    while (i < lemin.len)
    {
        //ft_putnbr(i);
        ft_putstr(lemin.names[i]);
        if (lemin.table[i].flag == 1)
            ft_putstr("  Start\t");
        else if (lemin.table[i].flag == 2)
            ft_putstr("  End\t\t");
        else
            ft_putstr("\t\t");
        ft_putchar(':');
        tmp = lemin.table[i].links;
        while (tmp)
        {
            ft_putstr(lemin.names[tmp->num]);
            //ft_putnbr(tmp->num);
            ft_putstr("->");
            tmp = tmp->next;
        }
        ft_putstr("NULL\n");
        ++i;
    }
}
