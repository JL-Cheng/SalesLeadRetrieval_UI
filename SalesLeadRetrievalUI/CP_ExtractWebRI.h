//类功能：1、打开CSV文件并读取相关网页信息	2、提取网页内容

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

	void ReadWebsite(vector<myString> &str_vec);//提取网页源码

signals:
	void ReadNumber(int number);

public:
	vector<myString> Website;//存储网页地址

private:
	void GetWebsite();//读取CSV文件中num个网址
	//进行qstring向string的转换
	string qstr2str(const QString qstr)
	{
		QByteArray cdata = qstr.toLocal8Bit();
		return string(cdata);
	}
	char* FileName;//打开文件的文件名
	QNetworkAccessManager *m_NetManger;
	int number;

};

#endif // !CP_EXTRACTWEBRI_H
