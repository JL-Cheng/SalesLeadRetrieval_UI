//������ҳ��Ϣ����ȡ

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
	operateWebRI(int num);//numΪ��ҳ����
	~operateWebRI()	
	{
		delete analysis_list;
		delete segment_list;
		delete webRI;
	}

	//��ָ����ҳ���ݽ��з�����ȡ���ؼ�����
	void webRIAnalysis(int num);

	//�����ҳ��ȡ����
	void printWebRI();

	//�������ķִ�
	void webRISegment(int num);

private:
	myDictionary dictionary;
	int number;//��ַ����
	
public:
	myStringList *analysis_list;//�洢num����ҳ��ȡ�ؼ��ʺ�Ľ�����ֱ�Ϊnum������
	myStringList *segment_list;//�洢�ִ�֮��Ľ��
	extractWebRI *webRI;
	vector<myString> webRI_vector;//num����ҳ��Ϣ���ַ�������

};


#endif // !CP_OPERATEWEBRI_H
