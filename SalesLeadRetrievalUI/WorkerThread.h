//多线程类，保证界面不会卡死，实现操作友好性

#pragma once

#include <QThread>
#include"CP_MyIndex.h"

class WorkerThread : public QThread
{
	Q_OBJECT

public:
	WorkerThread(int num, myIndex *index, QObject *parent = 0);
	WorkerThread(QString q_str, int num, myIndex *index, QObject *parent = 0);
	~WorkerThread();

signals:
	void AnalyseNumber(int number);

protected:
	virtual void run() Q_DECL_OVERRIDE;

private:
	myIndex *myindex;//索引
	QString str;//输入的搜索词语
	int number;//网页总数量
	int status;//（状态，0-分析，1-搜索）

};
