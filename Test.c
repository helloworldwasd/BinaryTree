#include"head.h"
#include"queue.h"
int main() {
	//测试用
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
	//小型二叉树

	//二叉树的前中后序
	Preamble(a);
	printf("\n");

	Middleorder(a);
	printf("\n");

	Postorder(a);
	printf("\n");

	//队列实现二叉树的遍历(层序遍历)
	queue q;
	iniqueue(&q);     //初始化队列
	Pushqueue(&q, a);  //入队
	while(q.head != NULL){
		tb* t = Topqueue(&q);  //取队头并保存
		Outqueue(&q); //出队
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
	
	//计算二叉树的节点个数
	int asz = 0;
	Sizetb(a, &asz);
	printf("sz=%d\n", asz);

	int bsz = 0;
	Sizetb(b, &bsz);
	printf("sz=%d\n", bsz);

	//叶子节点的个数
	int leaf=Leaftb(a);
	printf("叶子节点的个数为:%d", leaf);

	//计算二叉树的深度
	int de = depth(a);
	printf("\n二叉树的深度为:%d\n", de);

	//是否为平衡树
	printf("该树是否为平衡树?: %d\n", BalanceTree(a));
	//free
	DestoryTree(a);
	return 0;
}