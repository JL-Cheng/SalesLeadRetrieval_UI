//自行定义的平衡二叉树（AVL）

#pragma once
#ifndef CP_MYAVL_H
#define CP_MYAVL_H

#include<iostream>
using namespace std;
#include"CP_MyDocumentList.h"

typedef struct myAVLNode//平衡二叉树结点
{
	int No;//词语编号
	myString word;//词语
	myDocumentList *doc_list;//文档链表
	int h;//结点平衡因子
	myAVLNode *right;//结点右孩子
	myAVLNode *left;//结点左孩子
	myAVLNode *pa;//结点双亲结点
}*myAVLTree;

class myAVL
{
public:
	myAVL();
	~myAVL();

	//添加结点,成功返回1
	int insertNode(myAVLNode *avlNode);

	//查找结点
	myAVLNode* searchNode(int No);

	//移除某结点
	int removeNode(int No);

private:
	//调整二叉树使其平衡,成功返回1
	int adjustAVLTree(myAVLNode *p);

	/*与平衡二叉树相关的操作*/
	//插入子节点后，调整祖先结点的平衡因子
	void adjustParentH_add(myAVLNode *q1);
	//插入子结点后，当二叉树进行左右旋转之后，调整祖先结点的平衡因子
	void adjustParentH_rotate(myAVLNode *q1);
	//删除结点后，调整祖先结点的平衡因子
	void adjustParentH_delete(myAVLNode *q1,int flag);

	//右单旋转
	myAVLTree rightRotate(myAVLNode *a);
	//左单旋转
	myAVLTree leftRotate(myAVLNode *a);

	//插入一个新节点到根节点的左子树（L）的左子树（L），不平衡后进行旋转
	void LLRotate(myAVLNode *a);
	//插入一个新节点到根节点的右子树（R）的右子树（R），不平衡后进行旋转
	void RRRotate(myAVLNode *a);
	//插入一个新节点到根节点的左子树（L）的右子树（R），不平衡后进行旋转
	void LRRotate(myAVLNode *a);
	//插入一个新节点到根节点的右子树（R）的左子树（L），不平衡后进行旋转
	void RLRotate(myAVLNode *a);

	//寻找与p结点紧邻且比p结点No大的结点
	myAVLNode *nextNode(myAVLNode *p);

	//删除一棵二叉树
	void deleteAVLTree(myAVLTree T);

public:
	myAVLTree tree;

};

#endif // !CP_MYAVL_H
