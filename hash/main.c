#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtab.h"

#define HASH_MUL 31
#define SIZE 10000

int main() 
{
	hash_table *man;
	node *look;
	man = hashtab_init (man);
	printf("dfdfd");
	hashtab_add(man,"you",12);
	hashtab_add(man,"yu",12);
    hashtab_add(man,"youdfssdf",12);
    hashtab_add(man,"you323",12);
	look = hashtab_lookup(man,"yu");
	printf("%s", look -> key);
	hashtab_delete(man,"yu");
	printf("%s", look -> key);

	return 0;
}
