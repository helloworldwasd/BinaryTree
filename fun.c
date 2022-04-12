#include"head.h"
#include"queue.h"
void Preamble(tb* p) {  //ǰ��
	if (p == NULL) {
		printf("NULL ");
		return;
	}
	printf("%c ", p->data);   //��ӡ��ָ���µ�data
	Preamble(p->left);    //���������ݹ�
	Preamble(p->right);    //���������ݹ�
}
void Middleorder(tb* p) {   //����
	if (p == NULL) {
		printf("NULL ");
		return;
	}
	Preamble(p->left);    //���������ݹ�
	printf("%c ", p->data);   //����������֮ǰ�ȷ��ʸ����ﵽ������������
	Preamble(p->right);    //���������ݹ�
}
void Postorder(tb* p) {   //����
	if (p == NULL) {
		printf("NULL ");
		return;
	}
	Preamble(p->left);    //���������ݹ�
	Preamble(p->right);    //���������ݹ�
	printf("%c ", p->data); 
}
void Sizetb(tb* p, int* szp) {  //����ڵ�ĸ���
	if (p == NULL) {
		return;
	}
	(*szp)++;
	Sizetb(p->left,szp);
	Sizetb(p->right,szp);
}
int Leaftb(tb* p) {   //����Ҷ�ӽڵ�ĸ���
	if (p == NULL) {
		return 0;
	}
	if (p->left == NULL && p->right == NULL) {  
		return 1;   //ΪҶ�ӽڵ㣬����1
	}
	return Leaftb(p->left) + Leaftb(p->right);
}
int depth(tb* p) {  //��������������
	if (p == NULL) {
		return 0;
	}
	return depth(p->left) > depth(p->right) ? depth(p->left) + 1 : depth(p->right) + 1;
}
bool BalanceTree(tb* p) {  //�жϸ����Ƿ�Ϊƽ�������
	if (p == NULL) {
		return true;
	}
	int left = depth(p->left);
	int right = depth(p->right);
	return (abs(left - right) < 2) && BalanceTree(p->left) && BalanceTree(p->right);
}
void DestoryTree(tb* p) {  //���ٶ�����
	//��Ϊ���ڵ���Ҫ����ͷţ������ú���ķ�ʽ����
	if (p == NULL) {
		return;
	}
	DestoryTree(p->left);
	DestoryTree(p->right);
	free(p);
}