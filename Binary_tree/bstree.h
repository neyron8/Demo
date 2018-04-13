#ifndef BSTREE_C
#define BSTREE_C

typedef struct
{
	char *key;
	int value;
	struct bstree *left;
	struct bstree *right;

}bstree;

typedef struct
{
  char *field; 
  struct list *ptr; 

} list;

void treeprint(bstree *tree);
bstree *bstree_create(char *key,int value);
void bstree_add(bstree *tree, char *key, int value);
bstree *bstree_lookup(bstree *tree, char *key);
bstree *bstree_min (bstree *tree);
bstree *bstree_max(bstree *tree);

#endif
