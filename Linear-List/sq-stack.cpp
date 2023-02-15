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

typedef int Status;
typedef int SElemType;

typedef struct SqStack {
  SElemType *base;
  SElemType *top;
  int stackSize;
}SqStack;

// 1. 顺序栈的初始化
Status InitStack(SqStack &S) {
  
  // 分配空间
  S.base = (SElemType*)malloc(MAXSIZE*sizeof(SElemType));
  // 存储分配失败
  if(!S.base) exit(OVERFLOW);
  
  // 栈顶指针等于栈底指针
  S.top = S.base;
  S.stackSize = MAXSIZE;

  return OK;

}

// 2. 判断栈是否为空
Status StackEmpty(SqStack S) {

  // 栈顶等于栈底则为空
  if(S.top == S.base) {
    return TRUE;
  } else {
    return FALSE;
  }

}

// 3. 求顺序栈长度
int StackLength(SqStack S) {
  return S.top - S.base;
}

// 4. 清空顺序栈
/**
  直接让top指向base
*/
Status ClearStack(SqStack S) {
  
  if(S.base) S.top = S.base;

  return OK;

}

// 5. 销毁顺序栈
Status DestroyStack(SqStack &S) {

  if(S.base) {
    // 释放S.base的空间
    free(S.base);
    S.stackSize = 0;
    // 指针变量设空
    S.base = S.top = NULL;
  }

  return 0;
  
}

// 6. 顺序栈的入栈
/**
  1. 检查是否上溢
  2. 将元素e压入栈顶
  3. top+1
*/
Status Push(SqStack &S, SElemType e) {

  if(S.top - S.base == S.stackSize) return ERROR;

  *S.top++ = e;

  return OK; 

}

// 7. 顺序栈的出栈
/**
  1. 检查是否下溢
  2. 获取栈顶元素e
  3. 栈顶指针减1
*/
Status Pop(SqStack &S, SElemType &e) {

  if(S.top == S.base) return ERROR;

  // top是在栈顶元素的上一个，需要--
  e = *--S.top

  return OK;

}

int main() {

}