#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtab.h"

#define HASH_MUL 31
#define SIZE 10000

unsigned int hashtab_hash(char *key)
{
	unsigned int hsh = 0;
	char *p;
	for (p = key; *p != '\0'; p++) {
		hsh = hsh * HASH_MUL + (unsigned int) *p;
	}

	return hsh % SIZE;
}

hash_table *hashtab_init ( hash_table *hashtab ) 
{
	hashtab = malloc(sizeof(hash_table));
	
	hashtab -> list = malloc(sizeof(hash_table) * SIZE);
	
	int i;
	
	for (i = 0; i < SIZE; i++) {
		hashtab -> list[i] = NULL;
	}
	return hashtab;
}

void hashtab_add(hash_table *hashtab, char *key, int value)
{
	node *hashnode;
	int index = hashtab_hash (key);

	hashnode = malloc(sizeof(node));
	if (hashnode != NULL) {
		hashnode -> key = strdup(key);
		hashnode -> value = value;
		hashnode -> next = hashtab -> list[index];
		hashtab -> list[index] = hashnode;
	}
}

node *hashtab_lookup(hash_table *hashtab, char *key)
{
	int index;
	node *hashnode;

	index = hashtab_hash(key);
	for (hashnode = hashtab -> list[index]; hashnode != NULL; hashnode = hashnode -> next) {
		if (strcmp (hashnode -> key, key) == 0) {
			return hashnode;
		}
	}
	return NULL;
}

hashtab_delete(hash_table *hashtab, char *key)
{
	node *delete;
	node *prev = NULL;
	int index;

	index = hashtab_hash(key);
	for (delete = hashtab -> list[index]; delete != NULL; delete = delete -> next) {
		if (strcmp (delete -> key, key) == 0) {
			if (prev == NULL) {
				hashtab -> list[index] = delete -> next;
			} else {
				prev -> next = delete -> next;
			}
			free(delete);
			printf("\nElement deleted\n");
			return;
						
		}
		prev = delete;
	}
}		








