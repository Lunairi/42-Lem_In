/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlu <mlu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:45:00 by anazar            #+#    #+#             */
/*   Updated: 2018/02/01 21:32:21 by mlu              ###   ########.fr       */
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

# include "libft.h"

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
	size_t				ant;
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
}						t_row;

typedef struct			s_lemin
{
	t_room				*rooms;
	char				**names;
	t_row				*table;
	size_t				start;
	size_t				end;
	size_t				len;
	size_t				ants;
	int					print;
	int					count;
	int					begin;
	int					finish;
}						t_lemin;

/*
** parse.c
*/
void					parse_room(char *str, t_room *room);
void					parse_link(char *str, t_lemin *lemin);
char					*parse_comment(char *str, t_room *room,
							t_lemin *lemin);
void					print_rooms(t_room *rooms);

/*
** add_to_table.c
*/
void					mod(t_row *row, size_t to_add);
void					add_to_table(t_lemin *lemin, char *r1, char *r2);

/*
** ants.c
*/
void					move_ants(t_lemin *lemin, t_node *path);

/*
** bfs.c
*/
void					add_to_path(t_node **path, size_t start);
int						not_in(size_t val, t_node *tmp);
int						shuffle_queue(t_lemin *lemin, t_node *tmp,
							t_queue *queue, t_node *path);
t_node					*bfs(t_lemin *lemin, size_t start);

/*
** get_names.c
*/
void					get_names(t_lemin *lemin);

/*
** hash.c
*/
size_t					hash(t_lemin *lemin, char *str, int *flag);

/*
** node_utils.c
*/
void					add_node(t_row *row, t_node *node);
void					find_start_end(t_lemin *lemin);

/*
** print_table.c
*/
void					print_table(t_lemin *lemin);

/*
** queue_utils.c
*/
void					enqueue(struct s_queue *queue, size_t num);
size_t					dequeue(struct s_queue *queue);
size_t					peek(struct s_queue *queue);
int						is_empty(struct s_queue *queue);
struct s_queue			*init(void);

/*
** room_list_utils.c
*/
t_room					*new_room(void);
size_t					list_len(t_room *room);
void					add_to_rooms(t_lemin *lemin, t_room *room);
int						not_in(size_t val, t_node *tmp);

/*
** validation_utils.c
*/
void					error(char	*str);

void					free_all(t_lemin *lemin, t_node *path);

#endif
