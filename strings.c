#include "string.h"
#include <stdio.h>

int slen(char *c) {
  int i = 0;
  for (i; c[i] != NULL; i++)
    ;
  return i;
}

int scmp(char *first, char *second) {
  int i = 0, flag;
  if (slen(first) < slen(second)) {
    return -1;
  } else if (slen(first) > slen(second)) {
    return 1;
  } else if (slen(first) == slen(second)) {
    for (i; i < slen(first); i++) {
      if (first[i] == second[i]) {
        flag = 0;
      } else {
        flag = 1;
        return 2;
      }
    }
  }
  if (flag == 0)
    return 0;
}

int search_word(char *word, char *string) {
  if (slen(word) > slen(string)) {
    return -1;
  }
  int s = 0;
  int i = 0;
  while (i != (slen(word) - 1) || s < slen(string)) { \\ Ошибка где то в условии
    if (word[i] == string[s]) {
      i++;
      s++;
    }
    else {
      i = 0;
      s++;
    }
  }
  if (i == (slen(word) - 1)) {
    return 0;
  } else {
    return -1;
  }
}

int main() {
  char j[] = {"12345"};
  char k[] = {"say hello to my friend"};
  char f[] = {"23"};
  printf("%d\n", slen(f));
  printf("%s\n", j);
  printf("scmp %d\n", scmp(j, k));
  printf("strcmp %d\n", strcmp(j, k));
  printf("search %d\n", search_word(f, k));
  return 0;
}
