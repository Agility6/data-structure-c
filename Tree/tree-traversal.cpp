#include <stdio.h>
#define OK 1

/**
  注意：该代码为伪代码!
*/


typedef int Status;
typedef int TElemType;

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode *BiTree;

void visit(BiTree T) {
  printf("%d", T -> data);
}

/**
  Per-Order-TRaverse
  DLR
*/
Status PerOrderTraverse(BiTree T) {

  // Tree Null 
  if(T == NULL) {
    return OK;
  }
  else {
    // Access the root node
    visit(T);
    // L
    PerOrderTraverse(T -> lchild);
    // R
    PerOrderTraverse(T -> rchild);
  }

} 

/**
  InOrderTraverse
  LDR
*/
Status InOrderTraverse(BiTree T) {
  
  // Tree Null
  if(T == Null) {
    return OK
  }

  // L
  InOrderTraverse(T -> lChild);
  // Access the root node
  visit(T);
  // R
  InOrderTraverse(T -> rchild)

}

/**
  PostOrderTraverse
  LRD
*/
Status PostOrderTraverse(BiTree T) {
  
  // Tree Null
  if(T == Null) {
    return OK
  }

  // L
  InOrderTraverse(T -> lChild);
  // R
  InOrderTraverse(T -> rchild)
  // Access the root node
  visit(T);
  
}

int main() {

}