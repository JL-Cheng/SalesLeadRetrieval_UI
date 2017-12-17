//自行定义的字符串链表类

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
	
	//添加节点
	void addNode(myString str);
	
	//删除节点
	void removeNode(myString str);

	//查找某元素位置
	myStringNode* searchNode(myString data);

public:
	myStringNode *head;
	myStringNode *end;	
	int length;//链表长度
};

#endif // !CP_MYSTRINGLIST_H
