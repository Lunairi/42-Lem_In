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

/*
** Function: draw_node
** Description: This function is designed to draw the nodes themselves
** and apply any translations/zoom to it.
** To explain the math, the passed in value for X and Y is the center
** of the node that is to be drawn. The values x2 and y2 is in relation
** to setting up bresengham as well as plotting points. The idea of this
** is to allow the node to actually be drawn between x2 and
** ---
** (x + work space size), therefore x2 and y2 act as the starting point.
** x2 and y2 are given values based off a static size, than has zoom
** applied to determine how wide that node will be drawn.
** ---
** In order to apply translation, x2 and y2 are manipulated by the 
** translation variable when we are attempting to set a hex value
** at the address of the image. These translation values are not set
** before since they can skew the sizing of the nodes.
*/
void	draw_node(int x, int y, t_visual *visual)
{
	int x2;
	int y2;

	x2 = x - 10 + visual->zoom;
	y2 = y - 10 + visual->zoom;
	while (x2 < (x + 10 + visual->zoom))
	{
		visual->pix[(x2 + visual->x) + ((y2 + visual->y)
			* visual->s_line / 4)] = 0x303030;
		if (++y2 > (y + 10 + visual->zoom))
		{
			y2 = y - 10;
			x2++;
		}
	}
}

/*
** Function: plot_node
** Description: This function is designed to take in data structures
** setup prior with parsed information in order to setup and create
** a working space for the visualizer. Each node will have their own
** designated work space which will allow the visualizer to draw inside.
** This will prevent multiple nodes from colliding, keeping them
** separated. The X and Y coord is the position that is given from the
** lem_in map file. 
** ---
** This is what happens to create the node:
** X is set equal to the X coord parsed in, multiplied by a static size
** Y is set equal to the Y coord parsed in, muttiplied by a static size
** X than has zoom and translation added afterwards to find its new value
** Y than has zoom and translation added afterwards to find its new value
** In this case, visual->zoom will widen or shrink the work space
** visual->x is translation on x axis, while visual->y is translation
** on the y axis.
** ---
** At the end this information is passed to draw_node
*/
void	plot_node(t_room *room, t_link *link, t_visual *visual)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (room->name != NULL)
	{
		x = (room->x * 20) + visual->zoom + visual->x;
		y = (room->y * 20) + visual->zoom + visual->y;
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