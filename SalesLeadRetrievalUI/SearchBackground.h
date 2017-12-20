//搜索界面

#pragma once
#pragma execution_character_set("utf-8")

#include <QWidget>
#include "ui_SearchBackground.h"

#include<QLabel>
#include<QLineEdit>
#include<QGridLayout>
#include<QPushButton>
#include<QScrollArea>
#include<QDesktopServices>
#include<QUrl>
#include<QFont>
#include<QFocusEvent>
#include<CP_MyString.h>

class SearchBackground : public QWidget
{
	Q_OBJECT

public:
	SearchBackground(QWidget *parent = Q_NULLPTR);
	~SearchBackground();

signals:
	void toSearch(QString q_str);

private slots:
	void search();

public slots:
	void showResult(QStringList *resultList, QStringList wordList);
	void openUrl(QString url)
	{
		QDesktopServices::openUrl(QUrl(url));
	}

protected:
	void init();//界面初始化函数
	void resizeEvent(QResizeEvent*event);//使背景图片填充整个界面
	void keyPressEvent(QKeyEvent *event);//处理按键信息
private:
	Ui::SearchBackground ui;

	QLabel *resultLabel;
	QLabel *numberLabel;//搜索结果数量
	QLineEdit *searchEdit;
	QPushButton *searchButton;
	QScrollArea *scrollArea;
	QString searchStr;//搜索内容
	QString oldStr;//记录之前搜索数据，避免多次搜索
	QString resultStr;//结果
};
