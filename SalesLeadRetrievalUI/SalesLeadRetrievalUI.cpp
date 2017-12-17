#include "SalesLeadRetrievalUI.h"


SalesLeadRetrievalUI::SalesLeadRetrievalUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	init();//��ʼ������

	//���ô�������
	this->resize(1200, 900);
	this->setWindowOpacity(1);
	this->setAttribute(Qt::WA_TranslucentBackground);
	this->setWindowTitle("Sales Lead Retrieval");

	connect(this, SIGNAL(changeBackgroundNo(int)), this, SLOT(updateBackground(int)));//��������
	connect(index->OWR->webRI, &extractWebRI::ReadNumber,
		beginBackground, &BeginBackground::getReadNumber);
	connect(index, &myIndex::AnalyseNumber,
		beginBackground, &BeginBackground::getAnalyseNumber);
	connect(index, &myIndex::readyToSearch, this, &SalesLeadRetrievalUI::toSearchBackground);
	connect(searchBackground, &SearchBackground::toSearch, index, &myIndex::Search);
	connect(index, &myIndex::findResult, searchBackground, &SearchBackground::showResult);

	this->show();

	index->OWR->webRI->ReadWebsite(index->OWR->webRI_vector);
	index->operateWeb(total);
	index->createIndex();
}

void SalesLeadRetrievalUI::init()
{
	//��ʼ���������
	total = 2000;
	BackgroundController = new QStackedWidget(this);
	beginBackground = new BeginBackground(total,this);
	searchBackground = new SearchBackground(this);
	index = new myIndex(total);

	this->setCentralWidget(BackgroundController);//��ҳ������Ϊ���Ĵ���

	//��������뵽�����������
	BackgroundController->addWidget(beginBackground);
	BackgroundController->addWidget(searchBackground);

	BackgroundNo = 0;

	//������Ľ�������Ϊ��ʼ����
	BackgroundController->setCurrentIndex(BackgroundNo);

}

void SalesLeadRetrievalUI::updateBackground(int number)
{
	BackgroundController->setCurrentIndex(number);
}

void SalesLeadRetrievalUI::toBeginBackground()
{
	BackgroundNo = 0;
	emit changeBackgroundNo(BackgroundNo);
}

void SalesLeadRetrievalUI::toSearchBackground()
{
	BackgroundNo = 1;
	emit changeBackgroundNo(BackgroundNo);
}

void SalesLeadRetrievalUI::keyPressEvent(QKeyEvent *event)
{

}