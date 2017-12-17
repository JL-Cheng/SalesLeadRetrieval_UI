//���ж�����ַ���������

#pragma once
#ifndef CP_MYSTRINGLIST_H
#define CP_MYSTRINGLIST_H

#include<iostream>
using namespace std;
#include"CP_MyString.h"

struct myStringNode
{
	myString data;
	struct myStringNode *next;
};

class myStringList
{
public:
	myStringList();
	~myStringList();
	
	//��ӽڵ�
	void addNode(myString str);
	
	//ɾ���ڵ�
	void removeNode(myString str);

	//����ĳԪ��λ��
	myStringNode* searchNode(myString data);

public:
	myStringNode *head;
	myStringNode *end;	
	int length;//������
};

#endif // !CP_MYSTRINGLIST_H
