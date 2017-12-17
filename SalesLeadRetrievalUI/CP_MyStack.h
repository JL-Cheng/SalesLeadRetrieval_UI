//ʵ���Զ���ջ����

#pragma once
#ifndef CP_MYSTACK_H
#define CP_MYSTACK_H
#include<iostream>
#include<stack>
#include"CP_MyString.h"
using namespace std;

typedef struct
{
	myString label;//��ǩ�ַ���
	int No;//��ǩ���
}stackData;//ջ��������

typedef struct
{
	stackData *base;
	stackData *top;
	int stacksize;

}Stack;

class myStack
{
public:
	myStack(int max_size);
	~myStack();

	//��ʼ��ջ
	void Init();

	//���ַ�����start_i��ʼ��ȡ��ǩ��ѹջ��NoΪ��ǩ����
	void Push(myString S, int &start_i);

	//����ǩ��ջ
	void Pop(int num);

	//��ȡջ��Ԫ��,��������
	stackData Top()
	{
		if (Empty()) exit(OVERFLOW);
		else
		{
			m_Stack.top--;
			stackData temp = *m_Stack.top;
			m_Stack.top++;
			return temp;
		}
	}

	//�ж�ջ�Ƿ�Ϊ�գ���������
	bool Empty()
	{
		if (m_Stack.top == m_Stack.base) return true;
		else return false;
	}

private:
	Stack m_Stack;
	int m_StackSize;
};

#endif // !CP_MYSTACK_H



