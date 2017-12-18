//*�����࣬ͨ��ʹ�ö���ƽ�������ĵ�������������ݿ⹹�������ʵ�

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

	//��������
	void createIndex();
	//������ҳ���ݲ��ִ�
	void operateWeb(int number);

	operateWebRI *OWR;//��ȡ��ҳ������ִʽ��

	public slots:
	//������Ĺؼ�������в�ѯ
	void Search(QString q_str);

signals:
	void readyToSearch();
	void findResult(QStringList *result,QStringList word);

private:

	//��ѯ�ô�λ��
	void searchWord(myString word, int *record);
	//����qstring��string��ת��
	string qstr2str(const QString qstr)
	{
		QByteArray cdata = qstr.toLocal8Bit();
		return string(cdata);
	}

	myAVL *IndexTree;//�����ֵ���
	int number;//��number����ҳ���������ݽ�������
};

#endif // !CP_MYINDEX_H

