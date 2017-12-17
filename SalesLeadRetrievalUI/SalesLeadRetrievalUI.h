//����ʾ���棬���Ʋ�ͬ�����ת��

#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_SalesLeadRetrievalUI.h"

//�������ͷ�ļ�
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

	myIndex *index;//����

private slots:
	void updateBackground(int number);//ˢ�½���

	void toBeginBackground();//���뿪ʼ����
	void toSearchBackground();//������������

protected:
	void keyPressEvent(QKeyEvent *event);//��������Ϣ

signals:
	void changeBackgroundNo(int number);//���½�����

private:
	Ui::SalesLeadRetrievalUIClass ui;
	void init();//��ʼ����������

	QStackedWidget *BackgroundController;//���ƽ����ת��
	int BackgroundNo;//��ѡ����ı�ţ���ʼ����-0,��������-1��
	int total;//�ܲ�����ҳ��

	BeginBackground *beginBackground;//������ʼ����
	SearchBackground *searchBackground;//������������
};
