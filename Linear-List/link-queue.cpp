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
typedef int QElemType;

typedef struct QNode {
  QElemType data;
  struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
  QueuePtr front; // 队头指针
  QueuePtr rear; // 队尾指针
} LinkQueue;

// 1. 链队列的初始化
Status InitQueue(LinkQueue &Q) {

  Q.front = Q.rear = (QueuePtr)malloc(sizeof(QNode));
  if(!Q.front) exit(OVERFLOW);
  Q.front -> next = NULL;

  return OK; QNode

}

// 2. 链队列的销毁
Status DestroyQueue(LinkQueue &Q) {
  
  Qnode *p;

  while(Q.front) {
    p = Q.front -> next;
    free(Q.front)
    Q.front = p;
  }

}

// 3. 链队列的入队
Status EnQueue(LinkQueue &Q, QElemType e) {

  QNode *p;
  p = (QueuePtr)malloc(sizeof(QNode));

  // 没有空间 
  if(!p) exit(OVERFLOW);
  
  p -> data = e;
  p -> next = NULL;

  Q.rear -> next = p;
  Q.rear = p; 

  return OK;

} 

// 4. 链队列的出队
Status DeQueue(LinkQueue &Q, QElemType &e) {
  
  QNode *p;

  if(Q.front == Q.rear) return ERROR;

  p = Q.front -> next
  e = p -> data;
  Q.front -> next = p -> next

  // 恰好是尾结点，删除完就没有元素了尾指针就应指向头结点
  if(Q.rear == p) Q.rear = Q.front;
  
  free(p);

  return OK;

}

// 5. 链队列的队头元素
Status GetHead(LinkQueue Q, QElemType &e) {

  if(Q.front == Q.rear) return ERROR;
  e = Q.front -> data;
  return OK;

}


int main()  {

}