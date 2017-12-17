#pragma once
#ifndef CP_MYDICTIONARY_H
#define CP_MYDICTIONARY_H
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1

#include<iostream>
#include<fstream>
#include<hash_map>
#include"CP_MyString.h"
#include"CP_MyStringList.h"

using namespace std;
using namespace stdext;

class myDictionary
{
public:
	myDictionary();//����ʵ��ļ�����һ����ϣ�ʵ�
	~myDictionary() {}
	int FindWord(myString str);//�ڹ�ϣ�ʵ��в��Ҵ�
	void SegmentSentence(myString strToSegment,myStringList &List);//���ַ������зִ�

private:
	hash_map<string, int> HashDictionary;//��ϣ�ֵ�
	typedef pair<string, int> pair;
};

#endif // !CP_MYDICTIONARY_H
