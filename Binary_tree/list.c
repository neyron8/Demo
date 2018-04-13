#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
  char *field; 
  struct list *ptr; 
}list;

list * init(char* a)
{
  list *head;
  
  head = (list*)malloc(sizeof(list));
  head->field = (char*)malloc(sizeof(char) * strlen(a));
  head->field = strcpy(head -> field , a);
  head->ptr = NULL; 
  return(head);
}

void printLinkedList(const list *head) {
    while(head) {
        printf("%s", head ->field);
        head = head -> ptr;
        printf("\n");
    }
}

void push(list **head, char* data) {
  
    list *tmp = (list*) malloc(sizeof(list)); 
    tmp->field = (char*)malloc(sizeof(char) * strlen(data));
    tmp->field = data;
    tmp->ptr = (*head);
    (*head) = tmp;
}

int main()
{
    list *y;
    y = init("kol");
    push(&y,"ioi");
    push(&y,"132");
    printLinkedList(y);


    return 0;
}
