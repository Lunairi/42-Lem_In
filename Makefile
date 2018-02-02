#* ************************************************************************** */
#*                                                                            */
#*    Makefile               _             _              :::      ::::::::   */
#*    By: mlu & anazar      | |           | |           :+:      :+:    :+:   */
#*     ___  __ _  __ _ _ __ | | __ _ _ __ | |_        +:+ +:+         +:+     */
#*    / _ \/ _` |/ _` | '_ \| |/ _` | '_ \| __|     +#+  +:+       +#+        */
#*   |  __/ (_| | (_| | |_) | | (_| | | | | |_    +#+#+#+#+#+   +#+           */
#*    \___|\__, |\__, | .__/|_|\__,_|_| |_|\__|        #+#    #+#             */
#*          __/ | __/ | |                             ###   ########.fr       */
#*         |___/ |___/|_|                                                     */
#* ************************************************************************** */

NAME	= lem_in

FILES	= main room_list_utils validation_utils add_to_table hash \
			node_utils print_table get_names bfs queue_utils ants parse \
			free_all
SRC		= $(patsubst %, %.c, $(FILES))
OBJ 	= $(addprefix ./objects/, $(SRC:.c=.o))
CFLAGS	= -Wall -Wextra -Werror -g
IFLAGS	= -I libft/includes -I includes

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(CFLAGS) -L libft -lft -I libft/includes -I includes $^ -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created lem_in"

./objects/%.o: ./src/%.c
	mkdir -p objects
	gcc $(IFLAGS) -c $< -o $@

clean:
	make fclean -C libft/
	/bin/rm -f *.o
	/bin/rm -rf ./objects/*.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned lem_in"

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned lem_in"

re: fclean all

.PHONY: clean fclean re all test
