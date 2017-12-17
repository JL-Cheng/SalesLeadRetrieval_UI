//���ж����ƽ���������AVL��

#pragma once
#ifndef CP_MYAVL_H
#define CP_MYAVL_H

#include<iostream>
using namespace std;
#include"CP_MyDocumentList.h"

typedef struct myAVLNode//ƽ����������
{
	int No;//������
	myString word;//����
	myDocumentList *doc_list;//�ĵ�����
	int h;//���ƽ������
	myAVLNode *right;//����Һ���
	myAVLNode *left;//�������
	myAVLNode *pa;//���˫�׽��
}*myAVLTree;

class myAVL
{
public:
	myAVL();
	~myAVL();

	//��ӽ��,�ɹ�����1
	int insertNode(myAVLNode *avlNode);

	//���ҽ��
	myAVLNode* searchNode(int No);

	//�Ƴ�ĳ���
	int removeNode(int No);

private:
	//����������ʹ��ƽ��,�ɹ�����1
	int adjustAVLTree(myAVLNode *p);

	/*��ƽ���������صĲ���*/
	//�����ӽڵ�󣬵������Ƚ���ƽ������
	void adjustParentH_add(myAVLNode *q1);
	//�����ӽ��󣬵�����������������ת֮�󣬵������Ƚ���ƽ������
	void adjustParentH_rotate(myAVLNode *q1);
	//ɾ�����󣬵������Ƚ���ƽ������
	void adjustParentH_delete(myAVLNode *q1,int flag);

	//�ҵ���ת
	myAVLTree rightRotate(myAVLNode *a);
	//����ת
	myAVLTree leftRotate(myAVLNode *a);

	//����һ���½ڵ㵽���ڵ����������L������������L������ƽ��������ת
	void LLRotate(myAVLNode *a);
	//����һ���½ڵ㵽���ڵ����������R������������R������ƽ��������ת
	void RRRotate(myAVLNode *a);
	//����һ���½ڵ㵽���ڵ����������L������������R������ƽ��������ת
	void LRRotate(myAVLNode *a);
	//����һ���½ڵ㵽���ڵ����������R������������L������ƽ��������ת
	void RLRotate(myAVLNode *a);

	//Ѱ����p�������ұ�p���No��Ľ��
	myAVLNode *nextNode(myAVLNode *p);

	//ɾ��һ�ö�����
	void deleteAVLTree(myAVLTree T);

public:
	myAVLTree tree;

};

#endif // !CP_MYAVL_H
