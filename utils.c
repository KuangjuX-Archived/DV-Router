#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

int min(int a, int b) {
  return a<b ? a : b;
}

void panic(char* s) {
    fprintf(stderr, "\033[47;31m%s\033[0m\n", s);
    exit(0);
}

void printdt(struct distance_table *dtptr, int type) {
  printf("This is %d distance table.\n", type);
  for(int i=0; i<4; i++) {
    for(int j=0; j<4; j++) {
      printf("%d ", dtptr->costs[i][j]);
    }
    printf("\n");
  }
}

void printndt(struct distance_table *dtptr, int type) {
  printf("This is %d to other nodes' distances.\n", type);
  printf("---------------------------------------\n");
  printf("Node|- 0 ----- 1 ------ 2 ----- 3 ----------\n");
  printf("D%d  |  %d       %d        %d       %d         \n", type,
  dtptr->costs[type][0], dtptr->costs[type][1], 
  dtptr->costs[type][2], dtptr->costs[type][3]);
}
