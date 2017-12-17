#include"CP_MyStringList.h"

myStringList::myStringList()
{
	head = new myStringNode;
	head->data = "";
	head->next = NULL;
	end = head;
	length = 0;
}

myStringList::~myStringList()
{
	myStringNode *tempNode1 = this->head;
	myStringNode*tempNode2 = this->head;
	while (tempNode1->next)
	{
		tempNode2 = tempNode1->next;
		delete tempNode1;
		tempNode1 = tempNode2;
	}
	delete tempNode1;
	tempNode1 = NULL;
	tempNode2 = NULL;
	head = NULL;
}

void myStringList::addNode(myString str)
{
	myStringNode *node = new myStringNode;
	node->data = str;
	node->next = 0;
	length++;
	end->next = node;
	end = node;
	node->next = NULL;
}

void myStringList::removeNode(myString str)
{
	myStringNode *tempNode1 = head;
	while (tempNode1->next!=NULL&&tempNode1->next->data.m_str != str.m_str)
		tempNode1 = tempNode1->next;
	if (tempNode1->next == NULL)return;
	if (tempNode1->next == end)
	{
		myStringNode *tempNode2 = tempNode1->next;
		end = tempNode1;
		delete tempNode2;
		tempNode1->next = NULL;
		length--;
	}
	else
	{
		myStringNode *tempNode2 = tempNode1->next;
		tempNode1->next = tempNode1->next->next;
		delete tempNode2;
		length--;
	}
}

myStringNode* myStringList::searchNode(myString data)
{
	myStringNode *node = head;
	while (node != NULL&&node->data.m_str != data.m_str)node = node->next;
	if (node == NULL) return 0;
	else return node;
}