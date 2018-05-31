#include <stdlib.h>
#include <stdio.h>
struct s_node {
        void *content;
        struct s_node *next;
    };
    struct s_queue {
        struct s_node *first;
        struct s_node *last;
    };
typedef struct s_node s_node;
typedef struct s_queue s_queue;

s_node	*init_node(void* item)
{
	s_node *tmp;
	tmp = malloc(sizeof(s_node));
	tmp->content = item;
	tmp->next=NULL;
	return(tmp);
}

s_queue	*init()
{
	s_queue *init;
	init = malloc(sizeof(s_queue));
	init->first = NULL;
	init->last = NULL;
	return (init);
}

void	enqueue(s_queue *queue, void *content)
{
	s_node *new_node;
	new_node = init_node(content);
	if (!queue->first || !queue->last )
	{
		queue->first = new_node;
		queue->last = new_node;
	return;
	}
	s_node *temp;
	temp = queue->last;
	temp->next = new_node;
	queue->last = new_node;
	return;
}
int isEmpty(s_queue *queue)
{
	if (!queue->first || !queue->last)
		return (1);
	return (0);
}

void *peek(struct s_queue *queue)
{
	if(isEmpty(queue))
		return (NULL);
	s_node *tmp;
	tmp = queue->first;
	void* item = tmp->content;
	return (item);
}

void	*dequeue(s_queue *queue)
{
	if(isEmpty(queue))
		return (NULL);
	s_node *tmp;
	tmp = queue->first;
	queue->first=tmp->next;
	void* item = tmp->content;
	free(tmp);
	if(!queue->first)
		queue->last = NULL;
	return (item);
}

int main()
{
	int item = 87;
	int item1 = 23;
	int item2 = 21;
	int tmp;
    void* deq;
    s_queue *queue = init();
    enqueue(queue,(void*)&item);
    enqueue(queue,(void*)&item1);
    deq = dequeue(queue);
    deq = dequeue(queue);
    deq = dequeue(queue);
    if (!tmp)
    	return(0);
    tmp= *((int*)deq);
	printf("%d\n",tmp);
	return (0);
}










