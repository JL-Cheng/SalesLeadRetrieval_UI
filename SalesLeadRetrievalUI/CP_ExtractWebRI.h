//�๦�ܣ�1����CSV�ļ�����ȡ�����ҳ��Ϣ	2����ȡ��ҳ����

#pragma once
#ifndef CP_EXTRACTWEBRI_H
#define CP_EXTRACTWEBRI_H

#include <iostream>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <vector>
#include<stdio.h>
#include<QObject>
#include<QEventLoop>
#include <QtNetwork/QNetworkAccessManager>  
#include <QtNetwork/QNetworkRequest>  
#include <QtNetwork/QNetworkReply> 
#include<QTextCodec>
using namespace std;

#include"CP_MyString.h"

class extractWebRI:public QObject
{
	Q_OBJECT

public:
	extractWebRI(int num);
	~extractWebRI();

	void ReadWebsite(vector<myString> &str_vec);//��ȡ��ҳԴ��

signals:
	void ReadNumber(int number);

public:
	vector<myString> Website;//�洢��ҳ��ַ

private:
	void GetWebsite();//��ȡCSV�ļ���num����ַ
	//����qstring��string��ת��
	string qstr2str(const QString qstr)
	{
		QByteArray cdata = qstr.toLocal8Bit();
		return string(cdata);
	}
	char* FileName;//���ļ����ļ���
	QNetworkAccessManager *m_NetManger;
	int number;

};

#endif // !CP_EXTRACTWEBRI_H
