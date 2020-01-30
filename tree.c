#include<stdio.h>
#include<stdlib.h>

#define COUNT 10 

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

void print(struct Node *node,int space){
  //struct Node * node = tree->head;
  if (node == NULL) 
        return; 
  
    // Increase distance between levels 
    space += COUNT; 
  
    // Process right child first 
    print(node->right, space); 
  
    // Print current node after space 
    // count 
    printf("\n"); 
    for (int i = COUNT; i < space; i++) 
        printf("  "); 
    printf("%d\n", node->value); 
  
    // Process left child 
    print(node->left, space);  
}

void del(struct Tree *tree,int value){
  struct Node *node = tree->head;
  while(1){
    if(node == NULL){
      printf("didn't find the value");
      break;
    }
    if(node->value > value && node->left != NULL){
      //no child
      if(node->left->value == value && node->left->left == NULL && node->left->right ==NULL){
	node->left = NULL;
	free(node->left);
	break;
      }
      //one child
      if(node->left->value == value && node->left->left != NULL){
	node->left->value = node->left->left->value;
	node->left->left = NULL;
	free(node->left->left);
	break;
      }
      if(node->left->value == value && node->left->right != NULL){
        node->left->value = node->left->right->value;                                 
        node->left->right = NULL;
        free(node->left->right);
	break;
      } 
      node = node->left;
    }
    if(node->value < value && node->right != NULL){
      //no child
      if(node->right->value == value && node->right->left == NULL && node->right->right ==NULL){
        node->right = NULL;
        free(node->right);
        break;
      }
      //one child
      if(node->right->value == value && node->right->left != NULL){
        node->right->value = node->right->left->value;
        node->right->left = NULL;
        free(node->right->left);
	break;
      }
      if(node->right->value == value && node->right->right != NULL){
        node->right->value = node->right->right->value;
        node->right->right = NULL;
        free(node->right->right);
	break;
      }                
      node = node->right;
    }
  }
}

int main(){
  struct Tree tree;
  tree.head = NULL;
  insert(&tree,50);
  insert(&tree,30);
  insert(&tree,70);
  insert(&tree,20);                                                                                                                    
  insert(&tree,40);                                                                                                                    
  insert(&tree,60);                                                                                                                    
  insert(&tree,80);                                                                                                                    
  del(&tree,20);
  del(&tree,30);
  del(&tree,1);
  print(tree.head,0);
  return 0;
}
