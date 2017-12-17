#include"CP_MyIndex.h"

myIndex::myIndex(int num):
	number(num)
{
	IndexTree = new myAVL;
	OWR = new operateWebRI(number);

	createIndex();
}

myIndex::~myIndex()
{
	delete IndexTree;
	delete OWR;
}

void myIndex::operateWeb(int number)
{
	for (int i = 0; i < number; i++)
	{
		OWR->webRIAnalysis(i);
		OWR->webRISegment(i);
		emit AnalyseNumber(i + 1);
	}
}

void myIndex::createIndex()
{
	for (int i = 0; i < number; i++)//循环构建索引
	{
		if (OWR->segment_list[i].length == 0)//不存在分词
			continue;
		myStringNode *word = OWR->segment_list[i].head->next;
		myString word_str="";//存储遍历过的词语，避免重复存储
		//遍历每个网页的所有分词
		while (word)
		{
			if (word_str.IndexOf(word->data) != -1)//该网页的该词已加入检索树
			{
				word = word->next;
				continue;
			}
			else
			{
				word_str.ConcatString(word->data);
				int No = 0;//该词语所对应编号
				int number = 1;//该词语在该文档中出现次数
				myAVLNode *avlNode;//插入或更新的二叉树结点
				myDocumentNode *docNode;//插入的文档结点
				for (int i = 0; i < word->data.length; i++)//No的生成规则
				{
					No = No * 10 - word->data[i];
				}
				myStringNode *temp = word->next;
				while (temp)
				{
					if (word->data.IndexOf(temp->data) != -1)
					{
						number++;
					}
					temp = temp->next;
				}

				//构建文档结点
				docNode = new myDocumentNode;
				docNode->ID = i;
				docNode->number = number;
				docNode->next = NULL;
				int a = 1;
				myStringNode *temp_node = OWR->analysis_list[i].head->next;
				docNode->website = temp_node->data;
				while (true)
				{
					temp_node = temp_node->next;
					a++;
					if (a == 4)
					{
						docNode->title = temp_node->data;
					}
					if (a == 8)
					{
						docNode->content = temp_node->data;
					}
					if (temp_node == NULL)break;
				}

				avlNode = IndexTree->searchNode(No);
				if (!avlNode)//之前未插入此词语
				{
					avlNode = new myAVLNode;
					avlNode->doc_list = new myDocumentList;
					avlNode->doc_list->addNode(docNode);
					avlNode->left = avlNode->right = avlNode->pa = NULL;
					avlNode->h = 0;
					avlNode->No = No;
					avlNode->word = word->data;
					IndexTree->insertNode(avlNode);
				}
				else//插入文档结点
				{
					avlNode->doc_list->addNode(docNode);
				}

				word = word->next;
			}
		}
	}

	emit readyToSearch();
}

void myIndex::Search(QString q_str)
{
	vector<myString> str_vector;
	QStringList word;
	myString separator_str(" ");//分割字符串
	myString word_str = qstr2str(q_str);
	int *record = new int[number + 1];
	for (int i = 0; i < number + 1; i++)
		record[i] = 0;
	word_str.SplitString(str_vector, separator_str);
	for (int i = 0; i < str_vector.size(); i++)
	{
		searchWord(str_vector[i], record);
		word.append(QString::fromLocal8Bit(str_vector[i].m_str.c_str()));
	}

	QStringList *result = new QStringList[3];
	for (int i = 0; i < number + 1; i++)
	{
		if (record[i] != 0)
		{
			myStringNode *temp_node = OWR->analysis_list[i].head->next;
			result[0].append(QString::fromStdString(temp_node->data.m_str));//存入网址
			int a = 1;
			while (true)
			{
				temp_node = temp_node->next;
				a++;
				if (a == 4)
				{
					result[1].append(QString::fromLocal8Bit(temp_node->data.m_str.c_str()));//存入标题
				}
				if (a == 8)
				{
					result[2].append(QString::fromLocal8Bit(temp_node->data.m_str.c_str()));//存入内容
				}
				if (temp_node == NULL)break;
			}
			delete temp_node;
		}
	}
	emit findResult(result, word);
	delete[]record;
}

void myIndex::searchWord(myString word,int *record)
{
	int No = 0;//该词语的代号
	for (int i = 0; i < word.length; i++)//No的生成规则
	{
		No = No * 10 - word[i];
	}

	myAVLNode *nodeToFInd = IndexTree->searchNode(No);
	if (!nodeToFInd)
		return;
	else
	{
		myDocumentNode *docNode = nodeToFInd->doc_list->head->next;
		while (docNode)
		{
			record[docNode->ID] += docNode->number;
			docNode = docNode->next;
		}
	}
}