/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:45:00 by anazar            #+#    #+#             */
/*   Updated: 2018/02/01 00:39:04 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <string.h>
# include <pthread.h>

# include "mlx.h"
# include "libft.h"

# define ZOOM_OUT 69
# define ZOOM_IN 78
# define MOVE_LEFT 86
# define MOVE_RIGHT 88
# define MOVE_DOWN 84
# define MOVE_UP 91
# define RESET_MLX 87
# define EXIT_MLX 53

typedef struct			s_room_info
{
	char				*name;
	int					x;
	int					y;
	int					flag;
	struct s_room_info	*next;
}						t_room;

typedef struct			s_node
{
	size_t				num;
	struct s_node		*next;
}						t_node;

typedef struct			s_queue
{
	t_node				*first;
	t_node				*last;
	int					size;
}						t_queue;

typedef struct			s_row
{
	int					checked;
	int					flag;
	t_node				*links;
	t_queue				*ants;
}						t_row;

typedef struct			s_visual
{
	void				*mlx;
	void				*win;
	void				*img;
	int					*pix;
	int					bits;
	int					s_line;
	int					endian;
	int					zoom;
	int					x;
	int					y;
}						t_visual;

typedef struct			s_lemin
{
	t_room				*rooms;
	char				**names;
	t_row				*table;
	t_visual			vis;
	size_t				start;
	size_t				end;
	size_t				len;
}						t_lemin;

void 	add_to_table(t_lemin *lemin, char *r1, char *r2);
void 	error(char *str);
t_room	*new_room(void);
size_t	list_len(t_room *room);
//void 	add_to_rooms(t_room *rooms, t_room room);
void 	add_to_rooms(t_lemin *lemin, t_room *room);
void 	add_node(t_row *row, t_node *node);
//void 	add_node(t_node *list, t_node *node);
size_t	hash(t_lemin *lemin, char *str, int *flag);
//void 	print_table(t_row *table, size_t len);
void 	print_table(t_lemin *lemin);
void 	get_names(t_lemin *lemin);
t_node	*bfs(t_lemin *lemin);

void enqueue(struct s_queue *queue, size_t num);
size_t dequeue(struct s_queue *queue);
int isEmpty(struct s_queue *queue);
struct s_queue *init(void);
size_t peek(struct s_queue *queue);

#endif
