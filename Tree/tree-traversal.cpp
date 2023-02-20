#include <stdio.h>
#define OK 1
#define NULL 0

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

/**
  InOrderTraverse_2
  use Stack
*/
Status InOrderTraverse_2(BiTree T) {
   
   // InitStack
   InitStack(S);
   BiTree *p, *q;
   p = T;

  /**
    StackEmpty: TRUE
    NotStackEmpty: FALSE
  */
  while(p || !StackEmpty(S)) {
    if(p) {
      Push(S,p);
      p = p -> lchild;
    } else {
      Pop(S, q);
      printf("%d", q -> data);
      p = q -> rchild;
    }
  }

  return OK;
}

/**
  将根节点进队
  对不空時循环：从队列中出列一个结点*p,访问
    1. 若有左孩子结点，将左孩子结点进队
    2. 若由右孩子结点，将右孩子结点进队
*/
void LevelOrder(BTNode *b) {

  BTNode *p;
  SqQueue *qu;

  // Init
  InitQueue(qu);
  enQueue(qu,b); // 根结点入队

  // 队不为空
  while(!QueueEmpty(qu)) {
    // 出队结点p
    deQueue(qu, p);
    printf("%d", p -> data);
    if(p -> lchild != NULL) {
      // 左孩子入队
      enQueue(qu, p -> lchild)''
    }
    if(p -> rchild != NULL) {
      enQueue(qu, p -> rchild);
    }
  }
  
}

int main() {

}