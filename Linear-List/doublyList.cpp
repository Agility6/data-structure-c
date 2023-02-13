#include <stdio.h>
#include <stdlib.h>
// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define NULL 0

typedef int Status;
typedef int ElemType;

/**
  头结点的前驱指针指向链表的最后一个结点
  让最后一个结点的后继指针指向头结点
*/


// 定义
typedef struct DuLNode {
  ElemType data;
  struct DuLNode *prior, *next;
} DuLNode, *DuLinkList;

// 双向链表的插入
/**
  GetElemP_Dul函数与单链表类似查找
*/
void ListInsert_DuL(DuLinkList &L, int i, ElemType e) {

  DuLNode *p, *s;

  // 找到i位置上的元素
  if(!(p=GetElemP_Dul(L,i))) return ERROR;

  s = (DuLNode*)malloc(sizeof(DuLNode));
  s -> data = e;
  
  // 1. s的prior指向p的前一个元素
  s -> prior = p -> prior;
  // 2. p的前一个元素的next指向s
  p -> prior -> next = s;
  // 3. s的next指向p
  s -> next = p;
  // 4. p的prior指向s
  p -> prior = s;

  return OK;

}

// 双向链表的删除
void ListDelete_DuL(DuLinkList &L, int i, ElemType &e) {
  
  DuLNode *p;

  // 找到i位置上的元素
  if(!(p=GetElemP_Dul(L,i))) return ERROR;

  // 存储删除的值
  e = p -> data

  // 1. p的前一个元素的next指向p的后一个元素
  p -> prior -> next = p -> next;

  // 2. p的后一个元素的prior指向p的前一个元素
  p -> next -> prior = p -> prior;
  
  // 3. free P
  free(p);

  return OK;

}

int main() {
  
}