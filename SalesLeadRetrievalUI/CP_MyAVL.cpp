#include"CP_MyAVL.h"

myAVL::myAVL()
{
	tree = NULL;

}

myAVL::~myAVL()
{
	deleteAVLTree(tree);
}

void myAVL::deleteAVLTree(myAVLTree T)
{
	if (!T)
		return;
	myAVLNode *pLeft = T->left;
	myAVLNode *pRight = T->right;
	delete T;
	T = NULL;
	if (pLeft)
	{
		deleteAVLTree(pLeft);
	}
	if (pRight)
	{
		deleteAVLTree(pRight);
	}
	return;
}

void myAVL::adjustParentH_add(myAVLNode *q1)
{
	myAVLNode *q3 = q1, *q2 = q1->pa;
	while (q2)//存在双亲结点
	{
		if (q2->right == q3)//插入结点为右子树
		{
			q2->h--;
			if (q2->h >= 0)//对祖先结点没有影响
				return;
		}
		else//插入结点为左子树
		{
			q2->h++;
			if (q2->h <= 0)//对祖先结点没有影响
				return;
		}
		q3 = q2;
		q2 = q2->pa;//继续向上搜索。
	}
}

void myAVL::adjustParentH_rotate(myAVLNode *q1)
{
	myAVLNode *q3 = q1, *q2 = q1->pa;
	while (q2)//存在双亲结点
	{
		if (q2->right == q3)
		{
			q2->h++;
			if (q2->h >= 0)//对祖先结点没有影响
				return;
		}
		else
		{
			q2->h--;
			if (q2->h <= 0)//对祖先结点没有影响
				return;
		}
		q3 = q2;
		q2 = q2->pa;
	}
	return;
}

void myAVL::adjustParentH_delete(myAVLNode *q1, int flag)
{
	if (q1)
	{
		if (flag == 1)//删除的是左孩子
			q1->h--;
		else
			q1->h++;
		if (flag == 1 && q1->right != NULL || flag == 0 && q1->left != NULL)
			return;
		adjustParentH_rotate(q1);
	}
	return;
}

myAVLTree myAVL::rightRotate(myAVLNode *a)
{
	myAVLNode*b = a->left;
	a->left = b->right;
	if (b->right)
		b->right->pa = a;//b的右子树成为a的左子树
	if (a == tree)//a是根
	{
		tree = b;
		tree->pa = NULL;
	}
	else
	{
		b->pa = a->pa;
		if (a->pa->right == a)
			a->pa->right = b;
		else
			a->pa->left = b;
	}
	a->pa = b;
	b->right = a;
	return b;
}

myAVLTree myAVL::leftRotate(myAVLNode *a)
{
	myAVLNode*b = a->right;
	a->right = b->left;
	if (b->left)
		b->left->pa = a;
	if (a == tree)//a是根结点
	{
		tree = b;
		tree->pa = NULL;
	}
	else
	{
		b->pa = a->pa;
		if (a->pa->left == a)
			a->pa->left = b;
		else
			a->pa->right = b;
	}
	a->pa = b;
	b->left = a;
	return b;
}

void myAVL::LLRotate(myAVLNode *a)
{
	myAVLNode *b = a->left;
	if (!a->right&&b->right)//调整将要旋转的子树的平衡因子
	{
		b->h = -1;
		a->h = 1;
	}
	else
	{
		b->h = a->h = 0;
	}
	myAVLNode *c = rightRotate(a);//进行右单旋转
	adjustParentH_rotate(c);
}

void myAVL::RRRotate(myAVLNode *a)
{
	myAVLNode *b = a->right;
	if (!a->left&&b->left)
	{
		b->h = 1;
		a->h = -1;
	}
	else
	{
		b->h = a->h = 0;
	}
	myAVLNode *c = leftRotate(a);
	adjustParentH_rotate(c);
}

void myAVL::LRRotate(myAVLNode *a)
{
	myAVLNode *b = a->left, *c = b->right;
	if (b->left)
	{
		if (!c->left)
			b->h = 1;
		else
			b->h = 0;
		if (!c->right)
			c->h = 2;
		else
			c->h = 1;
	}
	else
	{
		b->h = 0;
		c->h = 1;
	}
	c = leftRotate(b);
	adjustAVLTree(c);
}

void myAVL::RLRotate(myAVLNode *a)
{
	myAVLNode *b = a->right, *c = b->left;
	if (b->right)
	{
		if (!c->right)
			b->h = -1;
		else
			b->h = 0;
		if (!c->left)
			c->h = -2;
		else
			c->h = -1;
	}
	else
	{
		b->h = 0;
		c->h = -1;
	}
	c = rightRotate(b);
	adjustAVLTree(c);
}

int myAVL::adjustAVLTree(myAVLNode *p)
{
	while (p)
	{
		if (p->h == 2 || p->h == -2)//需要进行调整
			break;
		p = p->pa;
	}
	if (!p)
		return 1;
	if (p->h == 2 && p->left&&p->left->h == 1 || p->h == 2 && p->left&&p->left->h == 0)
		LLRotate(p);//左左形式
	else if (p->h == 2 && p->left&&p->left->h == -1)
		LRRotate(p);//左右形式
	else if (p->h == -2 && p->right&&p->right->h == -1 || p->h == -2 && p->right&&p->right->h == 0)
		RRRotate(p);//右右形式
	else if (p->h == -2 && p->right&&p->right->h == 1)
		RLRotate(p);//右左形式
	return 1;
}

int myAVL::insertNode(myAVLNode *avlNode)
{
	myAVLNode *q1 = NULL, *q2 = NULL;
	myAVLTree p = tree;
	avlNode->pa = avlNode->left = avlNode->right = NULL;
	avlNode->h = 0;
	if (!tree)
	{
		tree = avlNode;
		return 0;
	}
	while (p)
	{
		q1 = p;
		if (p->No < avlNode->No)
			p = p->right;//向右子树搜寻
		else
			p = p->left;//向左子树搜寻
	}
	avlNode->pa = q1;
	if (!q1->left && !q1->right)
		adjustParentH_add(q1);//长度增加，进行调整
	if (q1->No < avlNode->No)//新结点插为右子树
	{
		q1->h--;
		q1->right = avlNode;
	}
	else//插为左子树
	{
		q1->h++;
		q1->left = avlNode;
	}
	adjustAVLTree(avlNode);//对插入结点后的平衡树进行调整
	return 1;
}

myAVLNode* myAVL::nextNode(myAVLNode *p)
{
	myAVLNode *q = p->right;
	while (q)
	{
		p = q;
		q = q->left;
	}
	return p;
}

int myAVL::removeNode(int No)
{
	myAVLNode *p = tree, *q = NULL, *child = NULL;
	int flag = 0;//删除点为左孩子还是右孩子，0为右孩子，1为左孩子
	while (p&&p->No != No)
	{
		if (p->No < No)
			p = p->right;
		else
			p = p->left;
	}//找到删除结点

	if (!p)//p结点不存在
		return 0;//删除失败
	if (!p->left || !p->right)
		q = p;
	else
		q = nextNode(p);
	if (q->left)
		child = q->left;
	else
		child = q->right;
	if (child)
		child->pa = q->pa;
	if (q == tree)//删除结点为根结点
		tree = child;
	else
	{
		if (q->pa->left == q)//q是左结点
		{
			flag = 1;
			q->pa->left = child;
		}
		else//q是右结点
			q->pa->right = child;
	}
	if (q != p)//相当于删除p的下一个结点
	{
		p->doc_list = q->doc_list;
		p->No = q->No;
		p->word = q->word;
	}
	adjustParentH_delete(q->pa, flag);
	adjustAVLTree(q->pa);
	delete q;
	return 1;
}

myAVLNode* myAVL::searchNode(int No)
{
	myAVLTree p = tree;
	while (p&&p->No != No)
	{
		if (p->No < No)
			p = p->right;//向右子树搜寻
		else
			p = p->left;//向左子树搜寻
	}
	return p;
}