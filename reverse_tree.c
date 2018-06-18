#include <stdio.h>
#include <stdlib.h>

struct s_node {
        int           value;
        struct s_node *right;
        struct s_node *left;
    };

typedef struct s_node s_node;

s_node *init(int val)
{
	s_node *tmp;
	tmp = malloc(sizeof(s_node));
	tmp->value = val;
	tmp->right=NULL;
	tmp->left=NULL;
	return(tmp);
}

s_node*	add_left(s_node *parent, int val)
{
	if(!parent)
		return(NULL);
	s_node *tmp = init(val);
	parent->left = tmp;
	return(parent->left);
}

s_node*	add_right(s_node *parent, int val)
{
	if(!parent)
		return(NULL);
	s_node *tmp = init(val);
	parent->right = tmp;
	return(parent->right);
}

void	printer(s_node *parent)
{
	if (!parent)
	{
		printf("node is null\n");
		return;
	}
	printf("Parent value: %d\n", parent->value);
	if (!parent->left)
		printf("left node is null\n");
	else
		printf("Left child: %d\n", parent->left->value);
	if (!parent->right)
		printf("right node is null\n");
	else
		printf("Right child: %d\n", parent->right->value);

}

void	printer_bot(s_node *parent,int level)
{
	printf("level :%d ",level);
	if (!parent)
	{
		printf("node is null\n");
		return;
	}
	printf("node value: %d\n", parent->value);
	printf("go left \n");
	printer_bot(parent->left,level+1);
	printf("go right \n");
	printer_bot(parent->right,level+1);
	printf("level up\n");
	
}


void	ft_swap(s_node *n1, s_node *n2)
{
	s_node *tmp = init(0);
	*tmp = *n1;
	*n1 = *n2;
	*n2 = *tmp;
	free(tmp);
}
void	reverse_tree(s_node *tree)
{
	if (!tree)
		return;
	if (!(tree->left || tree->right))
		return;
	if (!tree->left)
	{
		reverse_tree(tree->right);
		tree->left=tree->right;
		tree->right=NULL;
		return;
	}
	if (!tree->right)
	{
		reverse_tree(tree->left);
		tree->right = tree->left;
		tree->left=NULL;
		return;
	}
	reverse_tree(tree->left);
	reverse_tree(tree->right);
	ft_swap(tree->left, tree->right);
}

int main (void)
{
	s_node *tree = init(94);
	s_node *n1 = add_right(tree, 52);
	s_node *n2 = add_left(tree,34);
	s_node *n3 = add_left(n2, 1);
	s_node *n4 = add_right(n2, 99);
	s_node *n5 = add_left(n3, 20);
	s_node *n6 = add_left(n4, 83);
	s_node *n7 = add_right(n4, 39);
	s_node *n8 = add_right(n6, 61);
	s_node *n9 = add_right(n7, 67);
	s_node *n10 = add_left(n7, 37);
	
	printer_bot(tree,0);
	printf("++++++++++++++++++++++++++\n");

	reverse_tree(tree);
	printer_bot(tree,0);
	/*printer(n2);
	printer(n4);
	printer(n3);
	printer(n6);
	printer(n7);
	re*/
	return(0);
}




