#include <stdio.h>
#include <stdlib.h>

typedef struct __tree
{
	int data;
	struct __tree *left;
	struct __tree *right;
} tree;

tree *get_tree_node(void)
{
	tree *tmp = (tree *)malloc(sizeof(tree));
	tmp->left = NULL;	
	tmp->right = NULL;
	return tmp;
}

void tree_ins(tree **root, int data)
{
	if(!(*root))
	{
		*root = get_tree_node();
		(*root)->data = data;
		return;
	}
	else if((*root)->data < data)
		tree_ins(&(*root)->right, data);
	else if((*root)->data > data)
		tree_ins(&(*root)->left, data);
}

void print_tree(tree *root)
{
	if(root)
	{
		printf("data = %d\n", root->data);
		print_tree(root->left);
		print_tree(root->right);
	} 
}

void chg_node(tree **root)
{
	tree *tmp = *root;
	if((*root)->left)
		*root = (*root)->left;
	if((*root)->right)
		*root = (*root)->right;
	free(tmp);
}

void find_max(tree **root, int *max)
{
	if((*root)->right == 0)
	{
		*max = (*root)->data;
		chg_node(root);
	}
	else
		find_max(&(*root)->right, max);
}


void del_tree(tree **root, int data)
{
	if(!(*root))
	{	
		printf("There is no node\n");	
		return;
	}
	else if((*root)->data < data)
		tree_ins(&(*root)->right, data);
	else if((*root)->data > data)
		tree_ins(&(*root)->left, data);
	else if((*root)->left && (*root)->right)	
		{
			int max;
			find_max(&(*root)->left, &max);
			(*root)->data = max;
		}
	else 
		chg_node(root);
}

int main(void)
{
	int i;
	int arr[5] = {10, 50, 40, 30, 60};
	tree *root = NULL;

	for(i=0; i<5; i++)
		tree_ins(&root, arr[i]);

	print_tree(root);
	del_tree(&root, 10);
	print_tree(root);
	return 0;
}
