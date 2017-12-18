//*索引类，通过使用二叉平衡树、文档链表和已有数据库构建索引词典

#pragma once
#ifndef CP_MYINDEX_H
#define CP_MYINDEX_H

#include"CP_MyAVL.h"
#include"CP_OperateWebRI.h"

#include<QObject>
#include <QThread>

class myIndex:public QThread
{
	Q_OBJECT

public:
	myIndex(int num);
	~myIndex();

	//创建索引
	void createIndex();
	//解析网页内容并分词
	void operateWeb(int number);

	operateWebRI *OWR;//获取网页内容与分词结果

	public slots:
	//对输入的关键词组进行查询
	void Search(QString q_str);

signals:
	void readyToSearch();
	void findResult(QStringList *result,QStringList word);

private:

	//查询该词位置
	void searchWord(myString word, int *record);
	//进行qstring向string的转换
	string qstr2str(const QString qstr)
	{
		QByteArray cdata = qstr.toLocal8Bit();
		return string(cdata);
	}

	myAVL *IndexTree;//索引字典树
	int number;//用number个网页的数据内容建立索引
};

#endif // !CP_MYINDEX_H

