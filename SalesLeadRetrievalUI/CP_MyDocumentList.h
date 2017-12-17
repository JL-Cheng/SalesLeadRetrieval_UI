//自行定义的文档链表类

#pragma once
#ifndef CP_MYDOCUMENTLIST_H
#define CP_MYDOCUMENTLIST_H

#include<iostream>
using namespace std;
#include"CP_MyString.h"

struct myDocumentNode
{
	int ID;//文档编号
	int number;//文档中包含某一词语的个数
	myString title;//标题
	myString content;//内容
	myString website;//网址
	struct myDocumentNode *next;
};

class myDocumentList
{
public:
	myDocumentList();
	~myDocumentList();

	//添加结点
	void addNode(myDocumentNode *doc);

	//删除结点
	void removeNode(int ID);

	//查找某结点位置
	myDocumentNode* searchNode(int ID);

	//找到编号为ID的结点，修改文档结点内容，在函数变量中，只修改非空字符串
	void editNode(int ID, myString title, myString content, myString website,int number=0);

public:
	myDocumentNode *head;
	myDocumentNode *end;
	int length;//链表长度
};

#endif // !CP_MYDOCUMENTLIST_H
