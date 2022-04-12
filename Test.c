#include"head.h"
#include"queue.h"
int main() {
	//������
	tb* a=(tb*)malloc(sizeof(tb));
	if (a == NULL) {
		printf("malloc error!\n");
		exit(-1);
	}
	else {
		a->data = 'A';
		a->left = NULL;
		a->right = NULL;
	}

	tb* b = (tb*)malloc(sizeof(tb));
	if (b == NULL) {
		printf("malloc error!\n");
			exit(-1);
	}
	else {
		b->data = 'B';
		b->left = NULL;
		b->right = NULL;
	}

	tb* c = (tb*)malloc(sizeof(tb));
	if (c == NULL) {
		printf("malloc error!\n");
			exit(-1);
	}
	else {
		c->data = 'C';
		c->left = NULL;
		c->right = NULL;
	}

	tb* d = (tb*)malloc(sizeof(tb));
	if (d == NULL) {
		printf("malloc error!\n");
			exit(-1);
	}
	else {
		d->data = 'D';
		d->left = NULL;
		d->right = NULL;
	}

	tb* e = (tb*)malloc(sizeof(tb));
	if (e == NULL) {
		printf("malloc error!\n");
			exit(-1);
	}
	else {
		e->data = 'E';
		e->left = NULL;
		e->right = NULL;
	}
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	//С�Ͷ�����

	//��������ǰ�к���
	Preamble(a);
	printf("\n");

	Middleorder(a);
	printf("\n");

	Postorder(a);
	printf("\n");

	//����ʵ�ֶ������ı���(�������)
	queue q;
	iniqueue(&q);     //��ʼ������
	Pushqueue(&q, a);  //���
	while(q.head != NULL){
		tb* t = Topqueue(&q);  //ȡ��ͷ������
		Outqueue(&q); //����
		printf("%c ", t->data);
		if (t->left) {
			Pushqueue(&q, t->left); 
		}
		if (t->right) {
			Pushqueue(&q, t->right);
		}
	}
	printf("\n");
	freequeue(&q);
	
	//����������Ľڵ����
	int asz = 0;
	Sizetb(a, &asz);
	printf("sz=%d\n", asz);

	int bsz = 0;
	Sizetb(b, &bsz);
	printf("sz=%d\n", bsz);

	//Ҷ�ӽڵ�ĸ���
	int leaf=Leaftb(a);
	printf("Ҷ�ӽڵ�ĸ���Ϊ:%d", leaf);

	//��������������
	int de = depth(a);
	printf("\n�����������Ϊ:%d\n", de);

	//�Ƿ�Ϊƽ����
	printf("�����Ƿ�Ϊƽ����?: %d\n", BalanceTree(a));
	//free
	DestoryTree(a);
	return 0;
}