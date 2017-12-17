//自行定义的字符串类

#pragma once
#ifndef CP_MYSTRING_H
#define CP_MYSTRING_H

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

class myString
{
public:
	myString();
	myString(string str);
	~myString() {}


	//从pos开始搜索，返回子串T在主串m_str中的位置，0<=pos<=StrLength(S)；若不存在，则返回-1
	void GetNext(myString T, int* next);
	int IndexOf(myString T, int pos = 0);

	//字符串分割，将m_str分割为不同字符串
	void SplitString(vector<myString>& v, myString c);

	//字符串拷贝,将字符串拷贝到m_str中
	void SubString(myString str, int pos, int len);

	//字符串连接,将字符串连接到m_str中
	void ConcatString(myString str);

	//重载"="运算符
	myString& operator =(const string&str);
	myString& operator =(const myString& myStr);

	//重载"+"运算符
	myString& operator +(const char& ch);

	//重载"[]"下标运算符
	char& operator [](int n) { return m_str[n]; }

public: 
	string m_str;
	int length;
};

#endif // !CP_OPERATESTRING_H
