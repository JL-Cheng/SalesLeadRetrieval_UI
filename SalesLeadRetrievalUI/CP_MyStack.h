//实现自定义栈操作

#pragma once
#ifndef CP_MYSTACK_H
#define CP_MYSTACK_H
#include<iostream>
#include<stack>
#include"CP_MyString.h"
using namespace std;

typedef struct
{
	myString label;//标签字符串
	int No;//标签编号
}stackData;//栈数据类型

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

	//初始化栈
	void Init();

	//从字符串的start_i开始读取标签并压栈，No为标签类型
	void Push(myString S, int &start_i);

	//将标签退栈
	void Pop(int num);

	//获取栈顶元素,内联函数
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

	//判断栈是否为空，内联函数
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



