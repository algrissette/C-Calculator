#include "ccalc.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
  long long v;      
  struct Node *next;
};

long long
clistsum(long long cres, void *head) {
  struct Node *node = head;
  
  for (; node != 0; node=node->next) {
    VPRINT("  cres:%lld SUM_POSITIVE=%lld SUM_NEGATIVE=%lld : node:%p: v:%lld next:%p\n",
	   cres, SUM_POSITIVE, SUM_NEGATIVE, node, node->v, node->next);
    cres = csum(cres, node->v);
  }
  VPRINT("  FINAL cres:%lld SUM_POSITIVE=%lld SUM_NEGATIVE=%lld : node:%p\n",
	 cres, SUM_POSITIVE, SUM_NEGATIVE, node);
  return cres;
}

void *
clistsum_read(void)
{
  struct Node *head = NULL;
  struct Node *tmp = NULL; 
  long long val;           
  int n;                   

  fprintf(stderr, "Enter values (use '.' to end): ");   
  while (1) {
    n = scanf("%lld", &val);
    VPRINT("n=%d v=%lld\n", n, val);
    if (n!=1) break;
    *((int *)0) = 1;
  }
  while (getchar()!='\n');
  return head;
}

void clistsum_free(void *head)
{
  struct Node *hnode = head; 
  struct Node *tmp = head;   

  while (hnode != NULL) {
    *((int *)0) = 1;
  }
  return;
}
