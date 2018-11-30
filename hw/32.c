#include <stdio.h>
#include <stdlib.h>
#define LL 2
#define LR 3
#define RR 4
#define RL 5

#define ABS(n) 	(n<0) ? (-n) : (n)

typedef struct __avl
{
	int data;
	int lev;
	struct __avl *left;
	struct __avl *right;
} avl;

void print_avl(avl *head)
{
	avl *tmp = head;
	if(tmp)
	{
		printf("%d\n", tmp->data);
		if((tmp->left) != NULL)
			print_avl(tmp->left);
		if((tmp->right) != NULL)
			print_avl(tmp->right);
		else if((tmp->right) != NULL)
			print_avl(tmp);
	}

}

avl *get_avl_node(void)
{
	avl *tmp = (avl *)malloc(sizeof(avl));
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->lev = 1;
	return tmp;
}

int chg_lev(avl *root)
{
	int left, right;
	left = root->left > 0 ? root->left->lev : 0;
	right = root->right > 0 ? root->right->lev : 0;
	if(left>right)
		return left + 1;
	return right + 1;
}

int check_lev(avl *root)
{
	int right = root->right > 0 ? root->right->lev : 0;
	int left = root->left > 0 ? root->left->lev : 0;
	return right - left;
}

int check_rotation(avl *root, int data)
{
	if(check_lev(root)<0)
	{
		if(check_lev(root->left) > -1 && root->left->data < data)
			return LR;
		return LL;
	}
	else
	{
		if(check_lev(root->right) < 1 && root->right->data > data)
			return RL;
		return RR;
	}

	return 0;
}

avl *rr_rot(avl *first, avl *second)
{
        first->right = second->left;
        second->left = first;
        first->lev = chg_lev(first);
        second->lev = chg_lev(second);
        return second;
}

avl *ll_rot(avl *first, avl *second)
{
        first->left = second->right;
        second->right = first;
        first->lev = chg_lev(first);
        second->lev = chg_lev(second);
        return second;
}

avl *rl_rot(avl *first, avl *second)
{
        second = ll_rot(second, second->left);
        return rr_rot(first, second);
}

avl *lr_rot(avl *first, avl *second)
{
        second = rr_rot(second, second->right);
        return ll_rot(first, second);
}


avl *rotation(avl *root, int ret)
{
	switch(ret)
	{
		case LL:
			return ll_rot(root, root->left);
			break;
		case LR:
			return lr_rot(root, root->left);
			break;
		case RR:
			return rr_rot(root, root->right);
			break;
		case RL:
			return rl_rot(root, root->right);
			break;
	}
}

void chg_node(avl **node)
{
        avl *tmp = *node;
        if(!(*node)->right)
                *node = (*node)->left;
        else if(!(*node)->left)
                *node = (*node)->right;
        free(tmp);
}


void find_max(avl **node, int *max)
{
        if((*node)->right)
                find_max(&(*node)->right, max);
        else
        {
                *max = (*node)->data;
                chg_node(node);
        }
}

void delete_avl(avl **root, int data)
{
        // node 판정 part
        if(!(*root))
        {
                printf("There are no node!\n");
                return;
        }
        // data 찾는 part
        if((*root)->data > data)
                delete_avl(&(*root)->left, data);
        else if((*root)->data < data)
                delete_avl(&(*root)->right, data);

        else if((*root)->left && (*root)->right) // 17이나 50 
        {
                int max;
                find_max(&(*root)->left, &max);
                (*root)->data = max;
        }
	else
		chg_node(root);
        (*root)->lev = chg_lev(*root);

        if((ABS(check_lev(*root))) > 1 )
                *root = rotation(*root, check_rotation(*root, data));

}

void avl_ins(avl **root, int data)
{
	if(!(*root))
	{
		*root = get_avl_node();
		(*root)->data = data;
		return;
	}

	if((*root)->data > data)
		avl_ins(&(*root)->left, data);
	else
		avl_ins(&(*root)->right, data);
	// 재귀호출로부터 복귀 했을 때
	(*root)->lev = chg_lev(*root);

	if((ABS(check_lev(*root))) > 1 )
		*root = rotation(*root, check_rotation(*root, data));
}


int main(void)
{
	int i;
	int data[13] = {45,17,2,62,57,73,52,65,76,69,63,64,71};
	avl *root = NULL;
    	for(int i=0; i<13; i++)
		avl_ins(&root, data[i]);
	print_avl(root);
	printf("\n");
	delete_avl(&root, 57);
	print_avl(root);
	return 0;
}



