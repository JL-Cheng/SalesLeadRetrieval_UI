//进行网页信息的提取

#pragma once
#ifndef CP_OPERATEWEBRI_H
#define CP_OPERATEWEBRI_H

#include<iostream>
#include<Windows.h>
#include<stringapiset.h>
#include"CP_ExtractWebRI.h"
#include"CP_MyStack.h"
#include"CP_MyString.h"
#include"CP_MyStringList.h"
#include"CP_MyDictionary.h"
using namespace std;

class operateWebRI
{

public:
	operateWebRI(int num);//num为网页数量
	~operateWebRI()	
	{
		delete analysis_list;
		delete segment_list;
		delete webRI;
	}

	//对指定网页内容进行分析提取出关键内容
	void webRIAnalysis(int num);

	//输出网页提取内容
	void printWebRI();

	//进行中文分词
	void webRISegment(int num);

private:
	myDictionary dictionary;
	int number;//网址数量
	
public:
	myStringList *analysis_list;//存储num个网页提取关键词后的结果，分别为num个链表
	myStringList *segment_list;//存储分词之后的结果
	extractWebRI *webRI;
	vector<myString> webRI_vector;//num个网页信息的字符串向量

};


#endif // !CP_OPERATEWEBRI_H
