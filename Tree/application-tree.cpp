#include <stdio.h>
#define OK 1
#define NULL 0
#define OVERFLOW -2

/**
  注意：该代码为伪代码!
*/


typedef int Status;
typedef int TElemType;

typedef struct BiNode {
    TElemType data;
    BiNode *lchild, *rchild;
} BiNode *BiTree;


// 1. 按先序遍历序列建立二叉树的二叉链表
/**
  输入二叉树的结点，空结点则用#
*/
Status CreateBiTree(BiTree &T) {

  char ch;
  scanf("%c", &ch);

  if(ch == "#") {
    T = NULL;
  } else {
    // 生成树
    if(!(T = (BiTNode*)malloc(sizeof(BiTNode)))) {
      exit(OVERFLOW)
    }
    T -> data = ch;
    CreateBiTree(T -> data) // 构造左子树
    CreateBiTree(T -> data) // 构造右子树
  }

  return OK; 
  
}

// 2. 复制二叉树
/**
  如果是空树，递归结束
  否则，申请新结点空间，复制根节点
    - 递归复制左子树
    - 递归复制右子树
*/ 
int Copy(BiTree T, BiTree &NewT) {

  if(T = NULL) {
    return NewT = NULL;
    return 0;
  } else {
    NewT = (BiTNode*)malloc(sizeof(BiTNode))
    NewT -> data = T -> data;
    Copy(T -> lchild, NewT -> lchild);
    Copy(T -> rchild, NewT -> rchild);
  }

}

// 3. 计算二叉树深度
/**
  如果是空树，则深度为0
  否则，递归计算左子树的深度记为m，递归计算右子树的深度记为n，
  二叉树的深度则为m与n的较大者+1
*/
int Depth(BiTree T) {

  int m, n;
  if(T == NULL) {
    return 0;
  } else {
    m = Depth(T -> lchild);
    n = Depth(T -> rchild);
    if(m>n) {
      return (m+1);
    } else {
      return n + 1;
    }
  }

}

// 4. 求二叉树的结点数
/**
  与计算深度类似
  1. 图解
*/
int CountNode(BiTree T) {
  
  int m,n;
  if(T == NULL) {
    return 0;
  }

  m = CountNode(T -> lchild);
  n = CountNode(T -> rchild);

  return m + n;
  // return CountNode(T -> lchild) + CountNode(T -> rchild);

}

// 5. 求二叉树的叶子结点
/**
  1. 判断左右孩子有没有结点
*/
int LeadCount(BiTree T) {
  
  if(T == NULL) {
    return 0;
  }

  // 左右孩子都应该是空
  if((T -> lchild == NULL) && (T -> rchild == NULL)) {
    return 1;
  } else {
    // 不为空说明左右有孩子
    LeadCount(T -> lchild);
    LeadCount(T -> rchild);
  }
}

int main() {

}