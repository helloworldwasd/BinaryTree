#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
// ��������ǰ�к���
struct tb {
	char data;
	struct tb* left;      //������
	struct tb* right;    //������
};
typedef struct tb tb;

//������ȱ���
void Preamble(tb* p);  //ǰ��
void Middleorder(tb* p);  //����
void Postorder(tb* p); //����
//����������Ľڵ����
void Sizetb(tb* p, int* szp);
//���������Ҷ�ӽڵ�ĸ���(��Ϊ0�Ľڵ�)
int Leaftb(tb* p);
//��������������
int depth(tb* p);
//����������Ƿ�Ϊƽ�������(��һ�ڵ��Ӧ���������������߶Ȳ�Ϊ1)
bool BalanceTree(tb* p);
//���ٶ�����
void DestoryTree(tb* p);