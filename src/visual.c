/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/12/21 21:19:17 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init_visual(t_visual *visual)
{
	visual->mlx = mlx_init();
	visual->win = mlx_new_window(visual->mlx, 1000, 1000, "Kill me please");
	visual->img = mlx_new_image(visual->mlx, 1000, 1000);
	visual->pix = (int*)mlx_get_data_addr(visual->img,
		&(visual->bits), &(visual->s_line), &(visual->endian));
	// mlx_put_image_to_window(visual->mlx, visual->win, visual->img, 0, 0);
	// mlx_destroy_image(visual->mlx, visual->img);
}

void	draw_node(int x, int y, t_visual *visual)
{
	int x2;
	int y2;

	x2 = x - 10;
	y2 = y - 10;
	while (x2 < (x + 10))
	{
		visual->pix[x2 + (y2 * visual->s_line / 4)] = 0x303030;
		if (++y2 > (y + 10))
		{
			y2 = y - 10;
			x2++;
		}
	}
}

void	plot_node(t_room *room, t_link *link, t_visual *visual)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (room->name != NULL)
	{
		x = room->x * 20;
		y = room->y * 20;
		draw_node(x, y, visual);
	}
	mlx_put_image_to_window(visual->mlx, visual->win, visual->img, 0, 0);
}

void	visualizer(t_room *room, t_link *link)
{
	t_visual *visual;

	visual = ft_memalloc(sizeof(t_visual));
	init_visual(visual);
	plot_node(room, link, visual);
}