//���ж�����ַ�����

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


	//��pos��ʼ�����������Ӵ�T������m_str�е�λ�ã�0<=pos<=StrLength(S)���������ڣ��򷵻�-1
	void GetNext(myString T, int* next);
	int IndexOf(myString T, int pos = 0);

	//�ַ����ָ��m_str�ָ�Ϊ��ͬ�ַ���
	void SplitString(vector<myString>& v, myString c);

	//�ַ�������,���ַ���������m_str��
	void SubString(myString str, int pos, int len);

	//�ַ�������,���ַ������ӵ�m_str��
	void ConcatString(myString str);

	//����"="�����
	myString& operator =(const string&str);
	myString& operator =(const myString& myStr);

	//����"+"�����
	myString& operator +(const char& ch);

	//����"[]"�±������
	char& operator [](int n) { return m_str[n]; }

public: 
	string m_str;
	int length;
};

#endif // !CP_OPERATESTRING_H
