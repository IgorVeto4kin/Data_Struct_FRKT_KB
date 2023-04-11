#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct Node_ {
  Data data;
  struct Node_ * p_left;
  struct Node_ * p_right;
} Node, *PNode;

PNode insert(PNode proot, PNode z);
void inorder(PNode proot);

int main()
{
  PNode proot = NULL;
  int n ;
  Data curr;
  scanf("%d",&n);
  for(int i = 0; i<n;i++){
      scanf("%d", &curr);
      PNode z = (PNode) malloc(sizeof(Node));
      z->data = curr;
      z->p_left = NULL;
      z->p_right = NULL;
      proot = insert(proot, z);
    }
  //printf("%p \n%p", proot->p_left, proot->p_right);
  inorder(proot);
  return 0;
}

PNode insert(PNode proot, PNode z) {
  if (proot == NULL) {
    proot = (PNode) malloc(sizeof(Node));
    proot->data = z->data;
    //proot->p_left = NULL;
    //proot->p_right = NULL;
  } 
  else {
    PNode x = proot;
    while (x != NULL) {
      if (x->data > z->data) {
        if (x->p_left == NULL) {
          x->p_left = (PNode) malloc(sizeof(Node));
          x->p_left->data = z->data;
          x->p_left->p_left = NULL;
          x->p_left->p_right = NULL;
          break;  // Found the position for z, so exit loop
        }
        x = x->p_left;  // Move down the tree to the left
      } 
      else {
        if (x->p_right == NULL) {
          x->p_right = (PNode) malloc(sizeof(Node));
          x->p_right->data = z->data;
          x->p_right->p_left = NULL;
          x->p_right->p_right = NULL;
          break;  // Found the position for z, so exit loop
        }
        x = x->p_right;  // Move down the tree to the right
      }
    }
  }
  return proot;
}

void inorder(PNode proot)
{
  if (proot != NULL)
  {
    inorder(proot->p_left);
    printf("%d ", proot->data);
    inorder(proot->p_right);
  }
}