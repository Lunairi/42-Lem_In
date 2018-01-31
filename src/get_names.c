/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_names.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:38:59 by anazar            #+#    #+#             */
/*   Updated: 2018/01/30 21:02:48 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void    get_names(t_lemin *lemin)
{
    //char    **out;
    t_room  *tmp;
    int     i;

    lemin->names = (char **)ft_memalloc(sizeof(char *) * lemin->len);
    tmp = lemin->rooms;
    i = 0;
    while (i < lemin->len)
    {
        lemin->names[i] = tmp->name;
        tmp = tmp->next;
        ++i;
    }
    //return (out);
}
