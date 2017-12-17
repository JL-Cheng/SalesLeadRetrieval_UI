#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_BeginBackground.h"
#include<QResizeEvent>
#include<QLabel>
#include<QProgressBar>

class BeginBackground : public QWidget
{
	Q_OBJECT

public:
	BeginBackground(int num, QWidget *parent = Q_NULLPTR);
	~BeginBackground();

	void resizeEvent(QResizeEvent *event);//��䱳��

	public slots:
	void getReadNumber(int num);//��ȡ��ȡ����ҳ����
	void getAnalyseNumber(int num);//��ȡ��������ҳ����

private:
	Ui::BeginBackground ui;

	QLabel *showLabel;//��ʾ��ʾ��
	QProgressBar *showProgressBar;//��ʾ��ҳ��ȡ����
	int number;//���ڲ�������ҳ��
	int total;//�ܲ�����ҳ��
};
