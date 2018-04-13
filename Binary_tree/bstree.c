#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "bstree.h"


bstree *bstree_create(char *key,int value)
{
	bstree *element;
	
	element = malloc( sizeof (*element) );
	if (element == NULL) 
	{ 
		printf("\nError of creating\n");
		return -1;

	} else {

		element -> key = strdup(key);;
		element -> left = NULL;
		element -> right = NULL;
		element -> value = value;
		
	}
	return element;

}

bstree_add(bstree *tree, char *key4f, int value)
{
	bstree *parent;
	bstree *element;
    printf("HERE WE GO its %d\n", strlen(key4f));	
	if(tree == NULL) {
		return;
	}
	
	for (parent = tree; tree != NULL;) {
		parent = tree;
		if (strcmp(key4f,tree-> key) < 0) {
			tree = tree -> left;
		}
		else if(strcmp(key4f, tree -> key) > 0){
			tree = tree -> right;
		}
		else
			return;
	}

	element = bstree_create(key4f, value);
	
	if (strcmp(key4f, parent-> key) < 0) {
		parent -> left = element;
	} else {
		parent -> right = element;
	}	
	
}

bstree *bstree_lookup(bstree *tree, char *key) {

	bstree *detector;
	detector = tree;
	while (detector != NULL) {
		if (strcmp(key, detector-> key) == 0 ) {
			return detector;
			printf("FIND");
		}
		else if (strcmp(key, detector-> key) < 0) {
			detector = detector -> left;
		} else {

			detector = detector -> right;
		}
	}
	return detector;
}

bstree *bstree_min (bstree *tree) {
	
	if(tree== NULL) {
		return NULL;
	}
	
	while (tree -> left != NULL) {
		tree = tree -> left;
	}
	return tree;
}

bstree *bstree_max (bstree *tree) {
	
	if(tree == NULL) {
		return NULL;
	}
	
	while (tree -> right != NULL) {
		tree = tree -> right;
	}
	return tree;
}
		
void treeprint(bstree *tree) {
	

	if (tree!=NULL) {
 
   	    treeprint(tree->left);
   	 	treeprint(tree->right); 
     	printf("%s\n", tree -> key); 
	
  }
}
