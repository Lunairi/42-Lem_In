#include <lemin.h>

void	free_list(t_node *path)
{
	t_node	*tmp;

	while (path)
	{
		tmp = path->next;
		free(path);
		path = tmp;
	}
}

void	free_all(t_lemin *lemin, t_node *path)
{
	(void) lemin;
	free(path);
}