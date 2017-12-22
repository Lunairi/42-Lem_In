/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:45:00 by anazar            #+#    #+#             */
/*   Updated: 2017/12/21 17:01:55 by anazar           ###   ########.fr       */
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

typedef struct		s_node {
	int				num;
	struct s_node	*next;
}					t_node;

typedef struct		s_queue {
	t_node			*first;
	t_node			*last;
	int				size;
}					t_queue;

typedef struct		s_row {
	int				checked;
	int				is_start;
	int				is_end;
	t_node			*links;
}					t_row;

#endif
