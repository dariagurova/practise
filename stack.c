#include <stdlib.h>
#include <stdio.h>
struct s_node {
        void          *content;
        struct s_node *next;
    };
struct s_stack {
        struct s_node *top;
    };

typedef struct s_stack s_stack; 
typedef struct s_node s_node; 


s_stack	*init()
{
	s_stack *temp;

	temp = malloc(sizeof(s_stack));
	temp->top = NULL;
	return (temp);
}

void push(s_stack *stack, void *item)
{
	s_node * node;
	node=malloc(sizeof(s_node));
	node->content = item;
	node->next = stack->top;
	stack->top = node;
}

void* pop(s_stack *stack)
{
	s_node *tmp;
	void *c;
	if (!stack || !stack->top )
	{	printf("Error:stack\n");
		exit(0);
	}
	tmp = stack->top;
	c = tmp->content;
	stack->top = tmp->next;
	free(tmp);
	return (c);
}
void* peek(struct s_stack *stack) 
{	
	if (!stack || !stack->top )
	{	printf("Error:stack\n");
		exit(0);
	}
	return stack->top->content;
}

int isEmpty(struct s_stack *stack) 
{
	if (!stack->top)
		return 1;
	return 0;
}


int main()
{
	s_stack *st;
	st=init();
	
	void *tmp;
	int i=666;
	tmp= (void*)(&i);
	push(st,tmp);
	
	void *tmp2;
	int i2=667;
	tmp2= (void*)(&i2);
	push(st,tmp2);
	
	void *tmp3;
	int i3=668;
	tmp3= (void*)(&i3);
	push(st,tmp3);

	void *tmp1;
	tmp1=pop(st);
	printf("output %d\n", (*(int *)tmp1));

	tmp1=pop(st);
	printf("output %d\n", (*(int *)tmp1));

	tmp1=peek(st);
	printf("output %d\n", (*(int *)tmp1));

	tmp1=pop(st);
	printf("output %d\n", (*(int *)tmp1));

	tmp1=pop(st);
	printf("output %d\n", (*(int *)tmp1));
	

	return (0);
}
