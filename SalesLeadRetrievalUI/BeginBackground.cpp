#include "BeginBackground.h"

BeginBackground::BeginBackground(int num,QWidget *parent)
	: QWidget(parent),
	total(num)
{
	ui.setupUi(this);

	showLabel = new QLabel(this);
	showProgressBar = new QProgressBar(this);

	QFont font;//�����ı�����
	font.setPointSize(25);
	font.setFamily("����");
	showLabel->setFont(font);
	showLabel->setStyleSheet("color:black");//�����ı���ɫ

	showProgressBar->setOrientation(Qt::Horizontal);  // ˮƽ����
	showProgressBar->setMinimum(0);  // ��Сֵ
	showProgressBar->setMaximum(total);  // ���ֵ
	showProgressBar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // ���뷽ʽ

	number = 0;
}

BeginBackground::~BeginBackground()
{
	delete showLabel;
	delete showProgressBar;
}

void BeginBackground::getReadNumber(int num)
{
	number = num;
	showLabel->setText(tr("������ȡ��ҳ"));
	showProgressBar->setValue(number);  // ��ǰ����
	showProgressBar->setFormat(QString("��ǰ����Ϊ��%1%").arg(number * 100 / total));//��ǰ����
	showLabel->repaint();
	showProgressBar->repaint();
}

void BeginBackground::getAnalyseNumber(int num)
{
	number = num;
	showLabel->setText(tr("���ڷ�����ҳ"));
	showProgressBar->setValue(number);  // ��ǰ����
	showProgressBar->setFormat(QString("��ǰ����Ϊ��%1%").arg(number * 100 / total));//��ǰ����
	showLabel->repaint();
	showProgressBar->repaint();
}

void BeginBackground::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);//�������������
	this->setAutoFillBackground(true);//�Զ���䱳��

	//��ӱ���
	QImage image;
	QPalette palette;
	image.load(":/SalesLeadRetrievalUI/BeginBackground");
	
	palette.setBrush(this->backgroundRole(),
		QBrush(image.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));//���ñ�����ˢ

	this->setPalette(palette);

	//ʹ�ı�������Ӧ
	showLabel->setGeometry(geometry().x() + geometry().width()/2-120, geometry().y() + geometry().height()-220, 350, 50);
	showProgressBar->setGeometry(geometry().x() + geometry().width() / 2 -300, geometry().y() + geometry().height() - 150, 600, 50);
}
