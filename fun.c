#include"head.h"
#include"queue.h"
void Preamble(tb* p) {  //前序
	if (p == NULL) {
		printf("NULL ");
		return;
	}
	printf("%c ", p->data);   //打印该指针下的data
	Preamble(p->left);    //将左子树递归
	Preamble(p->right);    //将右子树递归
}
void Middleorder(tb* p) {   //中序
	if (p == NULL) {
		printf("NULL ");
		return;
	}
	Preamble(p->left);    //将左子树递归
	printf("%c ", p->data);   //访问右子树之前先访问根，达到二叉树的中序
	Preamble(p->right);    //将右子树递归
}
void Postorder(tb* p) {   //后序
	if (p == NULL) {
		printf("NULL ");
		return;
	}
	Preamble(p->left);    //将左子树递归
	Preamble(p->right);    //将右子树递归
	printf("%c ", p->data); 
}
void Sizetb(tb* p, int* szp) {  //计算节点的个数
	if (p == NULL) {
		return;
	}
	(*szp)++;
	Sizetb(p->left,szp);
	Sizetb(p->right,szp);
}
int Leaftb(tb* p) {   //计算叶子节点的个数
	if (p == NULL) {
		return 0;
	}
	if (p->left == NULL && p->right == NULL) {  
		return 1;   //为叶子节点，返回1
	}
	return Leaftb(p->left) + Leaftb(p->right);
}
int depth(tb* p) {  //计算二叉树的深度
	if (p == NULL) {
		return 0;
	}
	return depth(p->left) > depth(p->right) ? depth(p->left) + 1 : depth(p->right) + 1;
}
bool BalanceTree(tb* p) {  //判断该树是否为平衡二叉树
	if (p == NULL) {
		return true;
	}
	int left = depth(p->left);
	int right = depth(p->right);
	return (abs(left - right) < 2) && BalanceTree(p->left) && BalanceTree(p->right);
}
void DestoryTree(tb* p) {  //销毁二叉树
	//因为根节点需要最后释放，所以用后序的方式遍历
	if (p == NULL) {
		return;
	}
	DestoryTree(p->left);
	DestoryTree(p->right);
	free(p);
}