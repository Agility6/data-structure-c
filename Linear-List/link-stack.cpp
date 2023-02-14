#include <stdio.h>
#include <stdlib.h>
// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXSIZE 100
#define NULL 0

typedef int Status;
typedef int SElemType;

// 类型定义
typedef struct StackNode {
  SElemType data;
  struct StackNode *next;
} StackNode, *LinkStack;

// 1. 链栈初始化
void InitStack(LinkStack &S) {
  
  S = NULL;
  return OK;

}

// 2. 判断链栈是否为空
Status StackEmpty(LinkStack S) {

  if(S == NULL) return TRUE;
  else return FALSE;

}

// 3. 链栈入栈
Status Push(LinkStack &S, SElemType e) {

  StackNode *p;

  // 1.分配空间
  p = (StackNode*)malloc(sizeof(StackNode));

  // 2.将值赋值给p
  p -> data = e;

  // 3.将p的next指向S
  p -> next = S;

  // 修改top指针
  S = P;

  return OK;

}

// 4. 链栈出栈
Status Pop(LinkStack &S, SElemType &e) {

  StackNode *p;

  if(S == NULL) return ERROR;

  e = S -> data;
  p = S;
  S = S -> next;

  free(p);

  return OK;

}

// 5. 取栈顶元素
SElemType GetTop(LinkStack S) {
  
  if(S != NULL) {
    return S -> data;
  }
  
}

int main() {

}