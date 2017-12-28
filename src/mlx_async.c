/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_async.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/12/21 21:19:17 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

// mlx_do_sync(visual->mlx);
// mlx_hook(visual->win, 3, (1L << 0), hook_event, visual);

int		hook_event(int key, t_visual *visual)
{
	if (key == EXIT_MLX)
	{
		mlx_destroy_window(visual->mlx, visual->win);
		exit(EXIT_SUCCESS);
	}
	else if (key == ZOOM_OUT)
		visual->zoom += 5;
	else if (key == ZOOM_IN)
		visual->zoom -= 5;
	else if (key == MOVE_LEFT)
		visual->x -= 10;
	else if (key == MOVE_RIGHT)
		visual->x += 10;
	else if (key == MOVE_UP)
		visual->y -= 10;
	else if (key == MOVE_DOWN)
		visual->y += 10;
	else if (key == RESET_MLX)
	{
		visual->x = 0;
		visual->y = 0;
		visual->zoom = 0;
	}
	else
		return (0);
}
