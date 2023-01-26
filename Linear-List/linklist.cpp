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

typedef struct LNode {
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

// 1.单链表的初始化
Status InitList_L(LinkList &L) {
	// C++语法 L = new LNode;
	L = (LinkList)malloc(sizeof(LNode));
	L -> next = NULL;
	return OK;
}

// 2.判断链表是否为空(若L为空表，则返回1，否则返回0)
int ListEmpty(LinkList L) {
	if( L -> next ) {
		return 0;
	} else {
		return 1;
	}
}

// 3.单链表的销毁
Status DestroyList_L(LinkList &L) {
	LNode *p; // 或LinkList P;
	while(L) {
		p = L;
		L = L -> next;
		free(p); // C++: delete p;
	}
}

// 4. 清空链表
Status ClearList(LinkList &L) {
	LNode *p, *q;
	p = L -> next;
	while(p) {
		q = p -> next;
		free(p);
		p = q;	
	}
	L -> next = NULL;
	return OK;
}

// 5. 单链表的表长
int ListLength_L(LinkList L) {
	LNode *p;
	int i = 0;
	p = L -> next;
	while(p) {
		i++;
		p = p -> next;
	}
	return i;
}

// 6. 取单链表中第i个元素的内容
Status GetElem_L(LinkList L, int i, ElemType &e) {
	LNode *p;
	int j;
	p = L -> next;
	j = 1;

	// p存在并且i>j
	while( p && i > j ) {
		p = p -> next;
		j++;
	}

	if( !p || i < j) {
		return ERROR;
	} else {
		e = p -> data;	
	}
	return OK;
}

// 7.按值查找(返回地址)
LNode *LocateElem_L(LinkList L, ElemType e) {
	LNode *p;
	p = L -> next;

	while( p && p -> data != e ) {
		p = p -> next;
	}

	return p;
}

// 8.按值查找(返回位置序号)
int LocateElem_L2(LinkList L, ElemType e) {
	LNode *p;
	int j;
	
	p = L -> next;
	j = 1;

	while( p && p -> data != e ) {
		p = p -> next;
		j++;
	}

	if(p) {
		return j;
	} else {
		return 0;
	}
}

// 9.插入
Status ListInsert_L(LinkList &L, int i, ElemType e) {
	LNode *p, *s;
	int j;
	
	p = L;
	j = 0;

	/*
		j < i - 1
		排除i小于链表长度(即小于1) 和 大于链表长度+1
	*/
	while( p && j < i - 1 ) {
		p = p -> next;
		j++;
	}
	if( !p || j > i - 1 ) {
		return ERROR;
	}
	
	
	s = (LNode*)malloc(sizeof(LNode));
	s -> data = e;
	s -> next = p -> next;
	p -> next = s;
}

// 10. 删除某个元素
Status ListDelete_L(LinkList &L, int i, ElemType &e) {
	LNode *p, *q;
	int j;

	p = L;
	j = 0;

	while( p -> next && j < i - 1 ) {
		p = p -> next;
		j++;
	}

	if( !(p -> next) || j > i - 1 ) return ERROR;	

	q = p -> next; // 临时保存被删节点的地址已备释放
	p -> next = q -> next;
	e = q -> data;
	free(q);

	return OK;
}

// 11. 头插法
void CreateList_H(LinkList &L, int n) {
	L = (LinkList)malloc(sizeof(LNode));
	L -> next = NULL;

	int i;

	for( i = n; i > 0; --i) {
		LNode *p;
		p = (LNode*)malloc(sizeof(LNode));
		// 输出值给 p->data
		scanf("%d",&p -> data);
		p -> next = L -> next;
		L -> next = p;
	}
}

// 12. 尾插法	
void CreateList_R(LinkList &L, int n) {
		
	LNode *r;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	L -> next = NULL;
	
	r = L;

	for( i = 0; i < n; ++i) {
		LNode *p;
		p = (LNode*)malloc(sizeof(LNode));
		scanf("%d", &p -> data);
		p -> next = NULL;
		r -> next = p;
		r = p;
	}

	
}

void GetAllElem(LinkList L) {

	LNode *p;
	p = L -> next;

	while(p) {
		printf("LNode -> data = %d\n", p -> data);
		p = p -> next;
	}

}

int main()  {

	LinkList L;
	// 验证InitList_L
	int InitList_L_result;
	InitList_L_result = InitList_L(L);
	printf("InitList_L_result = %d\n", InitList_L_result);

	// 判断链表是否为空
	int ListEmpty_result;
	ListEmpty_result = ListEmpty(L);
	printf("ListEmpty_result = %d\n", ListEmpty_result);

	// 头插法
	CreateList_H(L, 5);

	// 单链表的表长
	int ListLength_L_result;
	ListLength_L_result = ListLength_L(L);
	printf("ListLength_L_result = %d\n", ListLength_L_result);


	// 打印链表
	GetAllElem(L);

	// 清空链表
	ClearList(L);

	// 尾插法
	CreateList_R(L, 5);

	// 打印链表
	GetAllElem(L);

	printf("\n");

	// 取单链表中第i个元素的内容
	ElemType GetElem_L_resultData;
	GetElem_L(L, 2, GetElem_L_resultData);
	printf("GetElem_L_result = %d\n", GetElem_L_resultData);

	printf("\n");

	// 按值查找(返回地址)
	LNode *LocateElem_L_result;
	LocateElem_L_result = LocateElem_L(L, 2);
	printf("LocateElem_L_result = %p\n", LocateElem_L_result);

	// 按值查找(返回位置序号)
	int LocateElem_L2_result;
	LocateElem_L2_result = LocateElem_L2(L, 2);
	printf("LocateElem_L2_result = %d\n", LocateElem_L2_result);

	printf("\n");

	// 插入元素
	ListInsert_L(L, 2, 22);

	// 打印链表
	GetAllElem(L);

	printf("\n");

	// 删除元素
	ElemType ListDelete_L_result; 
	ListDelete_L(L, 2, ListDelete_L_result);
	printf("ListDelete_L_result = %d\n", ListDelete_L_result);

	// 打印链表
	GetAllElem(L);
}