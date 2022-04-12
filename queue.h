#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//ǰ������
struct tb;
typedef struct tb* type;

struct list {
	type data;
	struct list* next;
};
//��Ϊ����ֻ����β���ͷɾ�����Զ���һ���ṹ��������ͷ�ڵ��β�ڵ�ĵ�ַ
struct queue {
	struct list* head;
	struct list* tail;
};
typedef struct list list;
typedef struct queue queue;
//ʵ�ֶ��еĳ�ʼ������ӣ����ӣ�ȡ��ͷ�Ͷ�β������ӵĳ��ȣ����ٶ��к��жӿա�
void iniqueue(queue* op);
void Pushqueue(queue* op, type n);
void Outqueue(queue* op);
type Topqueue(queue* op);
type Tailqueue(queue* op);
int Size(queue* op);
void freequeue(queue* op);
int judge(queue* op);

void print(queue* op);