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
	myDictionary();//读入词典文件构造一个哈希词典
	~myDictionary() {}
	int FindWord(myString str);//在哈希词典中查找词
	void SegmentSentence(myString strToSegment,myStringList &List);//将字符串进行分词

private:
	hash_map<string, int> HashDictionary;//哈希字典
	typedef pair<string, int> pair;
};

#endif // !CP_MYDICTIONARY_H
