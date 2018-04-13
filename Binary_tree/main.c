#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main()
{
	int count = 0;
	bstree * test;
	bstree * find;
    test = bstree_create("jacko", 43);

	FILE *file;
   
    char str[50];
    char *estr;
    file = fopen ("test.txt","r");

    while (1)
    {
       estr = fgets (str,sizeof(str),file);
       bstree_add(test,str,12);
       count ++;
       if (estr == NULL)
          {
             if ( feof (file) != 0)
             {  
                 printf ("\nReading file is end\n");
                 break;
             } else {
                   printf ("\nERROR OF READING\n");
                   break;
             }
       }
      
    }

   fclose(file);
   printf("\n%d\n", count);
   treeprint(test);

    return 0;
}
