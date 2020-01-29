#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  struct Node *left;
  struct Node *right;
  struct Node *parent;
  int value; 
}node;

typedef struct Tree{
  struct Node *head;
}tree;

struct Node * initNode(){
  struct Node * node = (struct Node *) calloc(1,sizeof(struct Node));
  return node;
}

void insert(struct Tree *tree,int value){
  struct Node *node = tree->head;
  while(1){
    if(node == NULL){
      tree->head = initNode();
      tree->head->value = value;
      break;
    }
    if(node->value >= value && node->left == NULL){
      node->left = initNode();
      node->left->value = value;
      node->left->parent = node;
      break;
    }
    if(node->value < value && node->right == NULL){
      node->right = initNode();
      node->right->value = value;
      node->right->parent = node;
      break;
    }
    if(node->value >= value && node->left != NULL){
      node = node->left;
    }
    if(node->value < value && node->right != NULL){
      node = node->right;
    }
  }
}

int main(){
  struct Tree tree;
  tree.head = NULL;
  insert(&tree,1);
  insert(&tree,2);
  insert(&tree,3);
  printf("%d\n",tree.head->value);
  return 0;
}
