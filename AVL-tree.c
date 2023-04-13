#include <stdio.h>
#include <stdlib.h>
typedef int Data;
typedef struct Node_ {
  Data data;
  int height;// показатель сбалансированности
  struct Node_ * p_left;
  struct Node_ * p_right;
} Node, *PNode;

PNode insert(PNode proot, Data key);
void inorder(PNode proot);
int get_balance(PNode root);
int height(PNode root);
PNode right_rotate(PNode root);
PNode left_rotate(PNode root);
int max (int a, int b);

int main()
{
  PNode proot = NULL;
  int n ;
  Data curr;
  scanf("%d",&n);
  for(int i = 0; i<n;i++){
      scanf("%d", &curr);
      proot = insert(proot, curr);
    }
  //printf("%p \n%p", proot->p_left, proot->p_right);
  inorder(proot);
  return 0;
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

PNode insert(PNode root, Data key) {
    if (root == NULL) {
        root = (PNode)malloc(sizeof(Node));
        root->data = key;
        root->height = 1;
        root->p_left = root->p_right = NULL;
    }
    else if (key < root->data) {
        root->p_left = insert(root->p_left, key);
    }
    else if (key > root->data) {
        root->p_right = insert(root->p_right, key);
    }

    root->height = max(height(root->p_left), height(root->p_right)) + 1;
    int balance = get_balance(root);

    if (balance > 1 && key < root->p_left->data) {
        return right_rotate(root);
    }
    if (balance < -1 && key > root->p_right->data) {
        return left_rotate(root);
    }
    if (balance > 1 && key > root->p_left->data) {
        root->p_left = left_rotate(root->p_left);
        return right_rotate(root);
    }
    if (balance < -1 && key < root->p_right->data) {
        root->p_right = right_rotate(root->p_right);
        return left_rotate(root);
    }

    return root;
}

int height(PNode root) {
    if (root == NULL) {
        return 0;
    } else {
        return root->height;
    }
}

int get_balance(PNode root) {
    if (root == NULL) {
        return 0;
    } else {
        return height(root->p_left) - height(root->p_right);
    }
}
PNode right_rotate(PNode root) {
    PNode new_root = root->p_left;
    root->p_left = new_root->p_right;
    new_root->p_right = root;

    root->height = max(height(root->p_left), height(root->p_right)) + 1;
    new_root->height = max(height(new_root->p_left), height(new_root->p_right)) + 1;

    return new_root;
}

PNode left_rotate(PNode root) {
    PNode new_root = root->p_right;
    root->p_right = new_root->p_left;
    new_root->p_left = root;

    root->height = max(height(root->p_left), height(root->p_right)) + 1;
    new_root->height = max(height(new_root->p_left), height(new_root->p_right)) + 1;

    return new_root;
}
int max (int a, int b){
  if(a>b){
    return a;
  }
  else{
    return b;
  }
}