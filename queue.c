#include"queue.h"
void iniqueue(queue* op) {  //初始化队列
	op->head = NULL;
	op->tail = NULL;
}
void Pushqueue(queue* q,type n) {  //入队
	list* newnode=(list*)malloc(sizeof(list));
	if (newnode == NULL) {
		printf("malloc error\n");
		exit(-1);
	}
	newnode->data = n;
	newnode->next = NULL;
	if (q->head == NULL && q->tail == NULL) {  //若没有节点
		q->head = q->tail = newnode;
	}
	else {
		q->tail->next = newnode;
		q->tail = newnode;  //将尾节点改为新节点
	}
}
void Outqueue(queue* op) {  //出队
	assert(op);
	if (op->head->next == NULL) {  //若只有一个节点
		free(op->head);
		op->head = NULL;
		op->tail = NULL;
	}
	else {
		list* phead = op->head->next;
		free(op->head);
		op->head = phead;
	}
}
type Topqueue(queue* op) {  //取队头
	assert(op);
	return op->head->data;
}
type Tailqueue(queue* op) {  //取队尾
	assert(op);
	return op->tail->data;
} 
int Size(queue* op) {   //返回队的长度
	assert(op);
	int sz = 0;
	list* tail = op->head;
	while (tail != NULL) {
		sz++;
		tail = tail->next;
	}
	return sz;
}
void freequeue(queue* op) { //销毁队
	list* phead = op->head;
	list* node = NULL;
	while (phead != NULL) {
		node = phead->next;
		free(phead);
		phead = node;
	}
}
int judge(queue* op) {  //判空
	if (op->head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}
void print(queue* op) {
	assert(op);
	list* phead = op->head;
	while (phead) {
		printf("%p ", phead->data);
		phead = phead->next;
	}
}