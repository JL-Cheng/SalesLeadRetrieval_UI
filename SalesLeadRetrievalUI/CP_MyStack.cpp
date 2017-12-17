#include"CP_MyStack.h"

myStack::myStack(int max_size):
	m_StackSize(max_size)
{
	Init();
}

myStack::~myStack() 
{
	delete[]m_Stack.base;
}

void myStack::Init()
{
	m_Stack.base = new stackData[m_StackSize];
	m_Stack.stacksize = m_StackSize;
	if (!m_Stack.base) return;
	m_Stack.top = m_Stack.base;
	return;
}

void myStack::Push(myString S, int &start_i)
{
	if (m_Stack.top - m_Stack.base >= m_Stack.stacksize)return;
	myString tempString;
	myString tempLabel;
	stackData tempData;
	int j = start_i;
	while (true)
	{
		tempString = tempString + S[j];
		if (S[j] == '>') break;
		j++;
	}

	start_i = ++j;
	tempData.label = tempString;
	tempData.No = 0;

	tempLabel = "<div";//若是div标签
	if (tempString.IndexOf(tempLabel)!=-1)
	{
		tempData.No = 1;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "<a";//若是a标签
	if (tempString.IndexOf(tempLabel)!=-1)
	{
		tempData.No = 2;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "<ul";//若是ul标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		tempData.No = 3;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "<style";//若是style标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		tempData.No = 4;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "<tr";//若是tr标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		tempData.No = 5;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "<p";//若是p标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		tempData.No = 6;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "<em";//若是em标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		tempData.No = 7;
		*m_Stack.top++ = tempData;
		return;
	}

	tempLabel = "</div";//若是div结束标签
	if (tempString.IndexOf(tempLabel)!=-1)
	{
		Pop(1);
		return;
	}

	tempLabel = "</a";//若是a结束标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		Pop(2);
		return;
	}

	tempLabel = "</ul";//若是ul结束标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		Pop(3);
		return;
	}

	tempLabel = "</style";//若是style结束标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		Pop(4);
		return;
	}

	tempLabel = "</tr";//若是tr结束标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		Pop(5);
		return;
	}

	tempLabel = "</p";//若是p结束标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		Pop(6);
		return;
	}

	tempLabel = "</em";//若是p结束标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		Pop(7);
		return;
	}

	tempLabel = "</";//若是p结束标签
	if (tempString.IndexOf(tempLabel) != -1)
	{
		Pop(0);
		return;
	}

	tempLabel = "/>";//若不是自结束且不是前边提到的标签
	if (tempString.IndexOf(tempLabel) == -1)
	{
		*m_Stack.top++ = tempData;
		return;
	}
}

void myStack::Pop(int num)
{
	if (Empty())
		return;
	m_Stack.top--;
	if (m_Stack.top->No != num)
	{
		m_Stack.top++;
		return;
	}
	else
	{
		m_Stack.top->label = "";
		m_Stack.top->No = 0;
		return;
	}

}

