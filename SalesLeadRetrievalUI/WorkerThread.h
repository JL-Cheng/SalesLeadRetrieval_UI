//���߳��࣬��֤���治�Ῠ����ʵ�ֲ����Ѻ���

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
	myIndex *myindex;//����
	QString str;//�������������
	int number;//��ҳ������
	int status;//��״̬��0-������1-������

};
