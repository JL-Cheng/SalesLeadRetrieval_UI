//���ж�����ĵ�������

#pragma once
#ifndef CP_MYDOCUMENTLIST_H
#define CP_MYDOCUMENTLIST_H

#include<iostream>
using namespace std;
#include"CP_MyString.h"

struct myDocumentNode
{
	int ID;//�ĵ����
	int number;//�ĵ��а���ĳһ����ĸ���
	myString title;//����
	myString content;//����
	myString website;//��ַ
	struct myDocumentNode *next;
};

class myDocumentList
{
public:
	myDocumentList();
	~myDocumentList();

	//��ӽ��
	void addNode(myDocumentNode *doc);

	//ɾ�����
	void removeNode(int ID);

	//����ĳ���λ��
	myDocumentNode* searchNode(int ID);

	//�ҵ����ΪID�Ľ�㣬�޸��ĵ�������ݣ��ں��������У�ֻ�޸ķǿ��ַ���
	void editNode(int ID, myString title, myString content, myString website,int number=0);

public:
	myDocumentNode *head;
	myDocumentNode *end;
	int length;//������
};

#endif // !CP_MYDOCUMENTLIST_H
