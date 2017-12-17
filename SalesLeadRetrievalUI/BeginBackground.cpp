#include "BeginBackground.h"

BeginBackground::BeginBackground(int num,QWidget *parent)
	: QWidget(parent),
	total(num)
{
	ui.setupUi(this);

	showLabel = new QLabel(this);
	showProgressBar = new QProgressBar(this);

	QFont font;//设置文本字体
	font.setPointSize(25);
	font.setFamily("隶书");
	showLabel->setFont(font);
	showLabel->setStyleSheet("color:black");//设置文本颜色

	showProgressBar->setOrientation(Qt::Horizontal);  // 水平方向
	showProgressBar->setMinimum(0);  // 最小值
	showProgressBar->setMaximum(total);  // 最大值
	showProgressBar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式

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
	showLabel->setText(tr("正在提取网页"));
	showProgressBar->setValue(number);  // 当前进度
	showProgressBar->setFormat(QString("当前进度为：%1%").arg(number * 100 / total));//当前进度
	showLabel->repaint();
	showProgressBar->repaint();
}

void BeginBackground::getAnalyseNumber(int num)
{
	number = num;
	showLabel->setText(tr("正在分析网页"));
	showProgressBar->setValue(number);  // 当前进度
	showProgressBar->setFormat(QString("当前进度为：%1%").arg(number * 100 / total));//当前进度
	showLabel->repaint();
	showProgressBar->repaint();
}

void BeginBackground::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);//避免编译器报警
	this->setAutoFillBackground(true);//自动填充背景

	//添加背景
	QImage image;
	QPalette palette;
	image.load(":/SalesLeadRetrievalUI/BeginBackground");
	
	palette.setBrush(this->backgroundRole(),
		QBrush(image.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));//设置背景画刷

	this->setPalette(palette);

	//使文本框自适应
	showLabel->setGeometry(geometry().x() + geometry().width()/2-120, geometry().y() + geometry().height()-220, 350, 50);
	showProgressBar->setGeometry(geometry().x() + geometry().width() / 2 -300, geometry().y() + geometry().height() - 150, 600, 50);
}
