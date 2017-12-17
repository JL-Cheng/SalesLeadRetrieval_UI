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

	void resizeEvent(QResizeEvent *event);//填充背景

	public slots:
	void getReadNumber(int num);//获取读取的网页个数
	void getAnalyseNumber(int num);//获取分析的网页个数

private:
	Ui::BeginBackground ui;

	QLabel *showLabel;//显示提示语
	QProgressBar *showProgressBar;//显示网页提取进程
	int number;//正在操作的网页数
	int total;//总操作网页数
};
