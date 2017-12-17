//主显示界面，控制不同界面的转换

#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_SalesLeadRetrievalUI.h"

//加入界面头文件
#include"BeginBackground.h"
#include"SearchBackground.h"
#include"CP_MyIndex.h"

#include<QStackedWidget>
#include<QKeyEvent>

class extractWebRI;
class myIndex;

class SalesLeadRetrievalUI : public QMainWindow
{
	Q_OBJECT

public:
	SalesLeadRetrievalUI(QWidget *parent = Q_NULLPTR);

	myIndex *index;//索引

private slots:
	void updateBackground(int number);//刷新界面

	void toBeginBackground();//进入开始界面
	void toSearchBackground();//进入搜索界面

protected:
	void keyPressEvent(QKeyEvent *event);//处理按键信息

signals:
	void changeBackgroundNo(int number);//更新界面编号

private:
	Ui::SalesLeadRetrievalUIClass ui;
	void init();//初始化各项数据

	QStackedWidget *BackgroundController;//控制界面的转换
	int BackgroundNo;//所选界面的编号（开始界面-0,搜索界面-1）
	int total;//总操作网页数

	BeginBackground *beginBackground;//创建开始界面
	SearchBackground *searchBackground;//创建搜索界面
};
