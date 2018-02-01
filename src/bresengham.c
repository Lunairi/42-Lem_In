/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresengham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:59:44 by mlu               #+#    #+#             */
/*   Updated: 2017/12/21 21:19:17 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	draw_color(int x, int y)
{
	visual->pix[x + (y * visual->s_line / 4)] = 0x303030;
}

void	draw_segment(int x, int y, int p, int swap)
{
	int i = -1;
	
	while (++i < x)
	{
		draw_color(x, y);
		while (p >= 0)
		{
			p = p - (2 * x);
			if (swap)
				x++;
			else
				y++;
		}
		p = p + (2 * dy);
		if (swap)
			y++;
		else
			x++;
	}
	draw_color(x, y);
}

void	draw_pixel(filler data structure)
{
	int tmp;
	int swap;
	int p;

	draw_color(x, y);
	if (y > x)
	{
		tmp = x;
		x = y;
		y = tmp;
		swap = 1;
	}
	p = 2 * y - x;
	draw_segment(x, y, p, swap);
}