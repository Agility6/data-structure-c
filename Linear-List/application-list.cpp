#include <stdio.h>
#include <stdlib.h>
// 函数结果状态码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define NULL 0

/**
  注意：
    该代码是具体应用代码，逻辑内使用到的函数均是线性表所实现过的。
    如果需要完成运行，则需要自行完善
    仅仅是伪代码!!!
*/

// 1. 线性表的合并
/**
  La = (7,5,3,11) Lb = (2,6,3) ==> La = (7,5,3,11,2,6)  
*/
void union(List &La, List Lb) {
  
  // 获取长度
  La_len = ListLength(La);
  Lb_len = ListLength(Lb);

  // 遍历
  for( i = 1; i < Lb_len; i++) {

    // 获取元素
    GetElem(Lb,i,e);

    // 判断La是否已经存在了
    if(!LocateElem(La,e)) {
      // 插入
      ListInsert(&La, ++La_len, e);
    }
  }
}

// 2. 有序表的合并(顺序表)
/**
  La = (1,7,8) Lb = (2,4,6,8,10,11) ==> Lc = (1,2,4,6,7,8,8,10,11)
*/
void MergeList_Sq(SqList LA, SqList LB, SqList &LC) {

  // 两个指针指向第一个元素
  pa = LA.elem;
  pb = LB.elem;

  // 定义LC的长度
  LC.length = LA.length + LB.length;
  
  // 分配空间
  LC.elem = new ElemType[LC.length];

  pc = LC.elem;

  // 两个指针指向表的最后(基地址+长度-1 = 最后的地址)
  pa_last = LA.elem + LA.length - 1;
  pb_last = LB.elem + LB.length - 1;

  // 比较
  while(pa <= pa_last && pb <= pb_last) {
    if(*pa <= *pb) {
      *pc++ = *pa++;
    } else {
      *pc++ = *pb++;
    }
  }  

  // 剩余的直接加入
  while(pa <= pa_last) {
    *pc++ = *pa++;
  }
  while(pb <= pb_last) {
    *pc++ = *pb++;
  }

}

// 2. 有序表的合并(链表)
/**
  La = (1,7,8) Lb = (2,4,6,8,10,11) ==> Lc = (1,2,4,6,7,8,8,10,11)
*/
void MergeList_L(LinkList &La, LinkList &Lb, LinkList &Lc) {

  pa = La -> next;
  pb = Lb -> next;

  // 用La的头结点作为Lc的头结点
  pc = Lc = La;

  while(pa && pb) {
    if(pa -> data <= pb -> data) {    
      // pc指向pa
      pc -> next = pa;
      // 移动pc到pa
      pc = pa;
      // 移动pa到下一个结点中
      pa = pa -> next;
    } else {
      pc -> next = pb;
      pc = pb;
      pb = pb -> next;
    }

    // 把剩余的部分全部街道pc中
    pc -> next = pa ? pa : pb;

    // 释放Lb结点
    free(pb);
  }

}


int main() {

}