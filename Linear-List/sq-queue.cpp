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
typedef int QElemType;

typedef struct SqQueue {
  
  QElemType *base; // 初始化动态分配存储空间
  int front;  // 头指针
  int rear; // 尾指针

} SqQueue;

// 1. 初始化循环队列
Status InitQueue(SqQueue &Q) {

  Q.base = (QElemType*)malloc(MAXSIZE*sizeof(QElemType)); 
  if(!Q.base) exit(OVERFLOW); 
  Q.front = Q.rear = 0; // 头指针和尾指针均为零
}

// 2. 循环队列的长度
int QueueLength(SqQueue Q) {
  /**
    注意是循环队列不能直接rear-front
    当rear/front在尾部的时候我们让它返回零(rear + 1) % MAXSIZE
    J6
    J5        <--front 
    null[3]
    null[2]
    null[1]
    null[0]   <--rear
    (rear+front + MAXSIZE) % MAXSIZE;
  */
  return (rear + front + MAXSIZE) % MAXSIZE;
}

// 3. 循环链表入队
Status EnQueue(SqQueue &Q, QElemType e) {

  // 1. 判断是否队满
  if((Q.rear + 1) % MAXSIZE == Q.front) return ERROR;

  // 2. 直接放在尾指针位置
  Q.base[Q.rear] = e;

  // 3. rear指针后移一位(当移动到最后让其重新回到0)
  Q.rear = (Q.rear + 1) % MAXSIZE;
  
  return OK;

}

// 4. 循环链表出队
Status DeQueue(SqQueue &Q, QElemType &e) {

  // 1. 判断是否是对空
  if(Q.front == Q.rear) return ERROR;

  // 2. 出队保存
  e = Q.base[Q.front];

  // 3. front指针后移一位(当移动到最后让其重新回到0)
  Q.front = (Q.front + 1) % MAXSIZE;
  
  return OK;
   
}

// 5. 取队头元素
SElemType GetHead(SqQueue Q) {
  
  // 判断是否为队空
  if(Q.front != Q.rear)

  return Q.base[Q.front];
  
}

int main() {

}