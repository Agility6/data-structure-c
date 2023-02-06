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

typedef struct CLNode {
  ElemType data;
  struct CLNode *next;
} CLNode, *CircList;

// 1.循环链表的初始化
Status InitList_C(CircList &C) {
  C = (CircList)malloc(sizeof(CLNode));
  // 循环链表
  C -> next = C;
  return OK;
}

// 2.判断链表是否为空(若L为空表，则返回1，否则返回0)
int CircEmpty(CircList C) {
  if( C -> next != C) {
    return 0;
  } else {
    return 1;
  }
}

// 3.单链表的销毁
Status DestroyList_C(CircList &C) {
  CLNode *p;
  while(C) {
    p = C;
    C = C -> next;
    free(C);
  }
}

// 4. 清空链表
Status ClearList_C(CircList &C) {
  CLNode *p, *q;
  p = C -> next;
  while(p!=C) {
    q = p -> next;
    free(p);
    p = q;
  }
  C -> next = NULL;
  return OK;
}

// 5. 循环链表的表长
int ListLength_C(CircList C) {

  CLNode *p;
  int i = 0;
  p = C -> next;

  while( p != C ) {
    i++;
    p = p -> next;
  }
  return i;

}

// 6. 取单链表中第i个元素的内容
Status GetElem_C(CircList C, int i, ElemType &e) {
  
  CLNode *p;
  int j;

  p = C;
  j = 0;

  while( p != C && j < i) {
    p = p -> next;
    j++;
  }

  if( p == C || j > i) {
    return ERROR;
  } else {
    e = p -> data;
  }

  return OK;
  
}

// 7.按值查找(返回地址)
CLNode *LocateElem_C(CircList C, ElemType e) {
  
  CLNode *p;
  p = C -> next;
  
  while( p != C && p -> data != e) {
    p = p -> next;
  }

  return p;

}

// 8.按值查找(返回位置序号)
int LocateElem_C2(CircList C, ElemType e) {

  CLNode *p;
  int j;

  p = C -> next;
  j = 1;

  while( p != C && p -> data != e) {
     p = p -> next;
     j++;
  }

  if( p == C ) {
    return 0;
  } else {
    return j;
  }
}

// 9.插入
/**
  1. 找到待插入节点的前一个节点
  2. 插入
*/
Status ListInsert_C(CircList &C, int i, ElemType e) {
  
  CLNode *p, *s;
  int j;

  p = C;
  j = 0;

  while( p -> next != C && j < i - 1 ) {
    p = p -> next;
    j++;
  }

  if( p == C || j > i - 1 ) {
    return ERROR;
  }

  s = (CLNode*)malloc(sizeof(CLNode));
  s -> data = e;
  s -> next = p -> next;
  p -> next = s;
  return OK;

}

// 10. 删除某个元素
Status ListDelete_C(CircList &C, int i , ElemType &e) {
  
  CLNode *p, *q;
  int j;

  p = C;
  j = 0;

  while( p -> next != C && j < i - 1 ) {
    p = p -> next;
    j++;
  }

  if( p == C || j > i - 1 ) {
    return ERROR;
  }

  q = p -> next;
  p -> next = q -> next;
  e = q -> data;
  free(q);
  
  return OK;

}

// 头插法
void CreateCircList_H(CircList &C, int n) {
  C = (CircList)malloc(sizeof(CLNode));
  C -> next = C;

  int i;

  for( i = n; i > 0; --i) {
    CLNode *p;
    p = (CLNode*)malloc(sizeof(CLNode));
    scanf("%d", &p -> data);
    p -> next = C -> next;
    C -> next = p;
  }
}

// 尾插法
void CreateCircList_R(CircList &C , int n) {

  CLNode *r;
  C = (CircList)malloc(sizeof(CLNode));

  C -> next = C;
  r = C;

  int i;

  for( i = 0; i < n; i++) {
    CLNode *p;
    p = (CLNode*)malloc(sizeof(CLNode));
    scanf("%d", &p -> data);
    r -> next = p;
    p -> next = C;
    r = p;
  }
}

void GetAllElem(CircList C) {

	CLNode *p;
	p = C -> next;

	while(p != C) {
		printf("CLNode -> data = %d\n", p -> data);
		p = p -> next;
	}

}

int main() {
  
  CircList C;

  // InitList_C
  int InitList_C_result;
  InitList_C_result = InitList_C(C);
  printf("InitList_C_result = %d\n", InitList_C_result);

  // CircEmpty
  int CircEmpty_result;
  CircEmpty_result = CircEmpty(C);
  printf("CircEmpty_result = %d\n", CircEmpty_result);

  // CreateCircList_R
  CreateCircList_R(C, 5);
  GetAllElem(C);
  printf("- - -\n");

  // ListInsert_C
  ListInsert_C(C, 7, 1013);
  GetAllElem(C);

  // ListDelete_C
  ElemType ListDelete_C_result;
  ListDelete_C(C, 6, ListDelete_C_result);
  GetAllElem(C);
  printf("ListDelete_C_result = %d\n", ListDelete_C_result);
 

}