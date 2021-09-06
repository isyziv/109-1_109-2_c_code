struct stacktree {
	int var;
	struct stacktree* lptr;
	struct stacktree* rptr;
}TREE_;
typedef struct stacktree* tree;
tree generate_tree();
tree insert_tree(tree tree, int var);
void inOrder(tree treePtr);
void preOrder(tree treePtr);
void postOrder(tree treePtr);
