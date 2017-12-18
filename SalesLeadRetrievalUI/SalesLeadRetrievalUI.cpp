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
	connect(index, &myIndex::readyToSearch, this, &SalesLeadRetrievalUI::toSearchBackground);
	connect(searchBackground, &SearchBackground::toSearch, this, &SalesLeadRetrievalUI::startSearchThread);
	connect(index, &myIndex::findResult, searchBackground, &SearchBackground::showResult);

	this->show();

	index->OWR->webRI->ReadWebsite(index->OWR->webRI_vector);
	startAnalyseThread();
}

void SalesLeadRetrievalUI::init()
{
	//��ʼ���������
	total = 20;
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

void SalesLeadRetrievalUI::startAnalyseThread()
{
	WorkerThread *workerThread = new WorkerThread(total,index,this);
	connect(workerThread, &WorkerThread::AnalyseNumber, beginBackground, &BeginBackground::getAnalyseNumber);
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void SalesLeadRetrievalUI::startSearchThread(QString q_str)
{
	WorkerThread *workerThread = new WorkerThread(q_str,total, index, this);
	connect(workerThread, &WorkerThread::AnalyseNumber, beginBackground, &BeginBackground::getAnalyseNumber);
	// �߳̽������Զ�����
	connect(workerThread, SIGNAL(finished()), workerThread, SLOT(deleteLater()));
	workerThread->start();
}

void SalesLeadRetrievalUI::keyPressEvent(QKeyEvent *event)
{

}