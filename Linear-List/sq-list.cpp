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

// Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef int ElemType;

// 定义顺序表结构
typedef struct SqList {
	int *elem;
	int length;
}SqList;

// 1.线性表L的初始化(参数用引用)
Status InitList_Sq(SqList &L) {    // 构造一个空的顺序表L
	L.elem = (int*)malloc(MAXSIZE*sizeof(int));  // 为顺序表分配空间
	// 如果L.elem空
	if(!L.elem) exit(OVERFLOW);      // 存储分配失败
	L.length = 0;										 // 空表长度为0
	return OK;
}

// 2.销毁线性表L
void DestroyList(SqList &L) {
	if(L.elem) delete L.elem; // 释放存储空间
}

// 3.清空线性表L
void ClearList(SqList &L) {
	L.length = 0;
}

// 4.求线性表L的长度
int GetLength(SqList L) {
	return (L.length);
}

// 5.判断线性表L是否为空
int IsEmpty(SqList L) {
	if(L.length == 0) return 1;
	else return 0;
}

// 6.顺序表的取值(根据位置i获取相应位置数据元素的内容)
int GetElem(SqList L, int i, ElemType &e) {
	if( i < 1 || i > L.length) return ERROR;
	e = L.elem[i-1];
	return OK;
}

// 7.顺序表上的查找操作(指定值e相同的数据元素的位置)
int LocateELem(SqList L, ElemType e) {
	 int i; 
	for( i = 0; i < L.length; i++ ) {
		if( L.elem[i] == e ) {
			return i+1;
		}
	}
	
	return 0;
}

// 8.顺序表的插入
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	if( i < 1 || i > L.length + 1 ) return ERROR;
	if( L.length == MAXSIZE ) return ERROR;
	int j;
	for( j = L.length - 1; j >= i; j--) {
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i-1] = e;
	L.length++;
	return OK;
}

// 9.顺序表的删除
Status ListDelete_Sq(SqList &L, int i) {
	if( i<1 || i > L.length) return ERROR;
	int j;
	for( j = i - 1; j < L.length - 1; j++) {
		L.elem[j] = L.elem[j+1];
	}
	L.length--;
	return OK;
}

// 验证程序
int main() {
	
	// 定义顺序表L
	SqList L;
	
	// 验证InitList_Sq
	int InitList_Sq_result;
	InitList_Sq_result = InitList_Sq(L);
	printf("InitList_Sq_result = %d\n", InitList_Sq_result);
	
	// 插入链表
	int j;
	for ( j = 1; j < 5; j++) {
		ListInsert_Sq(L, j, j - 1);
	}
	
	// 查看链表的长度
	int GetLength_result;
	GetLength_result = GetLength(L);
	printf("GetLength_result = %d\n", GetLength_result);
	
	// 顺序表的取值
	ElemType GetElem_result;
	GetElem(L, 2, GetElem_result);
	printf("GetElem_result = %d\n", GetElem_result);
	
	return 0;
}