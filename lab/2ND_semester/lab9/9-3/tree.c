#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
tree generate_tree()
{
	tree new;
	new = (tree)malloc(sizeof(TREE_));
	new->var = -1;
	new->lptr = NULL;
	new->rptr = NULL;
	return new;
}
void push(tree node, int var, int act)
{
	tree new = generate_tree();
	new->var = var;
	if (act)
	{
		node->rptr = new;
	}
	else
	{
		node->lptr = new;
	}
}
tree insert_tree(tree node, int var)
{
	if (node->var == -1)
	{
		node->var = var;
	}
	else
	{
		if (node->var < var)
		{
			if (node->rptr == NULL)
			{
				push(node, var, 1);
			}
			else
			{
				insert_tree(node->rptr, var);
			}
		}
		else
		{
			if (node->lptr == NULL)
			{
				push(node, var, 0);
			}
			else
			{
				insert_tree(node->lptr, var);
			}
		}
	}

}
void inOrder(tree treePtr)
{
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		inOrder(treePtr->lptr);
		printf("%3d", treePtr->var);
		inOrder(treePtr->rptr);
	}
}
void preOrder(tree treePtr)
{
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		printf("%3d", treePtr->var);
		preOrder(treePtr->lptr);
		preOrder(treePtr->rptr);
	}
}
void postOrder(tree treePtr)
{
	// if tree is not empty, then traverse
	if (treePtr != NULL) {
		postOrder(treePtr->lptr);
		postOrder(treePtr->rptr);
		printf("%3d", treePtr->var);
	}
}