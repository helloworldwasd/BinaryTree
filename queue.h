#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//前置声明
struct tb;
typedef struct tb* type;

struct list {
	type data;
	struct list* next;
};
//因为队列只进行尾插和头删，所以定义一个结构体来保存头节点和尾节点的地址
struct queue {
	struct list* head;
	struct list* tail;
};
typedef struct list list;
typedef struct queue queue;
//实现队列的初始化，入队，出队，取队头和队尾，计算队的长度，销毁队列和判队空。
void iniqueue(queue* op);
void Pushqueue(queue* op, type n);
void Outqueue(queue* op);
type Topqueue(queue* op);
type Tailqueue(queue* op);
int Size(queue* op);
void freequeue(queue* op);
int judge(queue* op);

void print(queue* op);