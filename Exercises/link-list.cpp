#include <stdio.h>

/**
  注意：该代码是练习题的编程题!
*/

// 1. 统计出单链表HL中结点的值等于给定值X的结点数。
int CountX(LNode* HL,ElemType x) {

  LNode *p;
  p = HL;
  int count; // 记数

  // 单链表为空直接返回
  if(!p) return ERROR;

  // 遍历链表
  while(p != NULL) {
    // p结点的data等于x
    if(p -> data == x) {
      count++;
    } else {
      // 指向下一个
      p = p -> next;
    }
  }

  return count;

}

// 2. 编写算法,将一个头指针为head不带头结点的单链表改造为一个单向循环链表
void linkList_c(linkList *head) {

  LNode *p;
  p = head;

  if(!p) return ERROR;

  // 遍历单链表找到最后一个结点
  while(p -> next == NULL) {
    p = p -> next;
  }

  // 将最后的结点指向head结点
  p -> next = head;

}

// 3. 编写算法，实现带头结点单链表的逆置算法
void linkListInverse(linkList *L) {

  LNode *p, *q;

  // 空
  if(!L -> next) return ERROR;

  p = L -> next;
  q = p -> next;
  // 断开
  p -> next = NULL;

  while(q) {
    // 将p指针移动到准备逆置的结点
    p = q;
    // 移动q(为了不失去后面的链表)
    q = q -> next;
    // 这两步就是将L的第一个结点与需要逆置的结点调换循序(代码不可调换)
    p > next = L -> next;
    L -> next =p;
  } 

}

// 4. 有两个循环链表，链头指针分别为L1和L2，要求写出算法将L2链表链到L1链表之后，且连接后仍保持循环链表形式
void linkListC_merge(linkList *L1, linkList *L2) {

  LNode *p, *q;

  p = L1;
  q = L2;

  while( p -> next != L1) {
    p = p -> next;
  }
  while( q -> next = L2) {
    q = q -> next;
  }

  p -> next = L2;
  q -> next = L1;

}

// 5. 设一个带头结点的单向链表的头指针为head，设计算法，将链表的记录，按照data域的值递增排序。


int main() {}