/* 
  The header containing the necessary tools.
*/
#include <stdio.h>
int len = 0;

int strLenght(char *str) {
   int i = 0;
    for(; str[i] != '\x00'; i++) {
      len++;
    }
}


char *concStr(char *str, char *addStr) {
/*
    This is Function, concatenates two sent strings. 
    Like strcat command. 
*/
   int x = 0;
   int y = 0;
    for(; str[x] != '\x00'; x++);
    if (str[x] == '\x00') {
       for (; addStr[y] != '\x00'; y++) {
         str[x] = addStr[y];
         x++;
       }
    }
}
