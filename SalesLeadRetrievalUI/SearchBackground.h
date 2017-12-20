//��������

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
	void init();//�����ʼ������
	void resizeEvent(QResizeEvent*event);//ʹ����ͼƬ�����������
	void keyPressEvent(QKeyEvent *event);//��������Ϣ
private:
	Ui::SearchBackground ui;

	QLabel *resultLabel;
	QLabel *numberLabel;//�����������
	QLineEdit *searchEdit;
	QPushButton *searchButton;
	QScrollArea *scrollArea;
	QString searchStr;//��������
	QString oldStr;//��¼֮ǰ�������ݣ�����������
	QString resultStr;//���
};
