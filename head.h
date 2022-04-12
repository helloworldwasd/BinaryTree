#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
// 二叉树的前中后序。
struct tb {
	char data;
	struct tb* left;      //左子序
	struct tb* right;    //右子序
};
typedef struct tb tb;

//深度优先遍历
void Preamble(tb* p);  //前序
void Middleorder(tb* p);  //中序
void Postorder(tb* p); //后序
//计算二叉树的节点个数
void Sizetb(tb* p, int* szp);
//计算二叉树叶子节点的个数(度为0的节点)
int Leaftb(tb* p);
//计算二叉树的深度
int depth(tb* p);
//计算二叉树是否为平衡二叉树(任一节点对应的两棵子树的最大高度差为1)
bool BalanceTree(tb* p);
//销毁二叉树
void DestoryTree(tb* p);