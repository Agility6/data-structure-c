#include <stdio.h>

/**
    1. 设计在二叉排序树上查找结点X的算法。
    -  二叉排序树的特点：左子树结点值 < 根结点值 < 右子树结点值
*/
void *searchNode(BiTree *T, int key) {

  if(T == NULL) return NULL;
  

  if(T -> data == key) {
    return T;
  } else if(T -> key > key) {  // key的值大于的当前节点说明在左子树中
    return searchNode(T -> lchild, key);
  } else {
    return searchNode(T -> rchild, key);
  }
  
}

/**
  2. 设二叉树bt采用二叉链表结构存储，数据元素为字符类型。设计算法将二叉链表中所有data域为小写字母的结点改为大写字母。
  小写 -> 大写 (-32)
*/
void algo(BiTree *bt) {

  if(bt) {
    if(bt -> data >= 'a' && bt -> data <= 'z') {
      bt -> data -= 32;
    }
    algo(bt -> lchild);
    algo(bt -> rchild);
  }

}

/**
  编写算法，统计二叉树中叶子结点的个数
  - 叶子节点 = 度为零的
*/
int treeChildNode(BiTree *T) {
  
  int count = 0;

  if((T -> lchild == NULL) && (T -> rchild == NULL)) {
    count++;
  } else {
    treeChildNode(T -> lchild);
    treeChildNode(T -> rchild);
  }

  return count
}

int main() {}