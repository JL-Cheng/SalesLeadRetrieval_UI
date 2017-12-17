#include"CP_MyDocumentList.h"

myDocumentList::myDocumentList()
{
	head = new myDocumentNode;
	head->ID = -1;
	head->number = 0;
	head->content = "";
	head->title = "";
	head->website = "";
	head->next = NULL;
	end = head;
	length = 0;
}

myDocumentList::~myDocumentList()
{
	myDocumentNode *tempNode1 = this->head;
	myDocumentNode *tempNode2 = this->head;
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

void myDocumentList::addNode(myDocumentNode *doc)//按number由高到低的顺序排列插入
{
	if (length == 0)
	{
		end->next = doc;
		end = doc;
		end->next = NULL;
	}
	else
	{
		myDocumentNode *p = head, *q = head->next;
		while (q)
		{
			if (q->number >= doc->number)
			{
				q = q->next;
				p = p->next;
			}
			else
				break;
		}
		if (!q)
		{
			end->next = doc;
			end = doc;
			end->next = NULL;
		}
		else
		{
			p->next = doc;
			doc->next = q;
		}
	}
	length++;
}

void myDocumentList::removeNode(int ID)
{
	myDocumentNode *tempNode1 = head;
	while (tempNode1->next != NULL&&tempNode1->next->ID != ID)
		tempNode1 = tempNode1->next;
	if (tempNode1->next == NULL)return;
	if (tempNode1->next == end)
	{
		myDocumentNode *tempNode2 = tempNode1->next;
		end = tempNode1;
		delete tempNode2;
		tempNode1->next = NULL;
		length--;
	}
	else
	{
		myDocumentNode *tempNode2 = tempNode1->next;
		tempNode1->next = tempNode1->next->next;
		delete tempNode2;
		length--;
	}
}

myDocumentNode* myDocumentList::searchNode(int ID)
{
	myDocumentNode *node = head;
	while (node != NULL&&node->ID != ID)
		node = node->next;
	if (node == NULL) 
		return 0;
	else
		return node;
}

void myDocumentList::editNode(int ID, myString title, myString content, myString website, int number)
{
	myDocumentNode *node = searchNode(ID);
	if (node == NULL)
		return;//该结点不存在
	else//进行修改
	{
		if (title.length != 0)
			node->title = title;
		if (content.length != 0)
			node->content = content;
		if (website.length != 0)
			node->website = website;
		if (number != 0)
			node->number = number;
	}
	return;
}