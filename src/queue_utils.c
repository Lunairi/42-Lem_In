#include <lemin.h>

struct s_queue *init(void)
{
	struct s_queue	*new;

	new = (struct s_queue *)malloc(sizeof(struct s_queue));
	new->first = NULL;
	new->last = NULL;
	return (new);
}

void enqueue(struct s_queue *queue, size_t num)
{

	struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->num = num;
	new->next = NULL;
	if (!queue->first)
		queue->first = new;
	//else if (!queue->last)
    if (!queue->last)
		queue->last = new;
	else
	{
		queue->last->next = new;
		queue->last = queue->last->next;
	}

/*
    struct s_node	*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->num = num;
    new->next = queue->first;
    queue->first = new;
    */
}

size_t dequeue(struct s_queue *queue)
{
	struct s_node	*tmp;
	size_t          tmp_num;

	if (!queue->first)
		return (0);
	tmp = queue->first;
	tmp_num = queue->first->num;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	free(tmp);
	tmp = NULL;
	return (tmp_num);
}

size_t peek(struct s_queue *queue)
{
	if (!queue->first)
		return (0);
	return (queue->first->num);
}

int isEmpty(struct s_queue *queue)
{
	return (!queue->first && !queue->last);
}
