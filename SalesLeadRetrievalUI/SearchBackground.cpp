#include "SearchBackground.h"
#define max(a,b) a>b?a:b

SearchBackground::SearchBackground(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//��ʼ��
	init();
	//������Ӱ�ť���������
	connect(searchButton, SIGNAL(clicked()), this, SLOT(search()));
	//������
	connect(resultLabel, &QLabel::linkActivated, this, &SearchBackground::openUrl);
}

SearchBackground::~SearchBackground()
{
	delete resultLabel;
	delete numberLabel;
	delete searchEdit;
	delete searchButton;
	delete scrollArea;
}

void SearchBackground::init()
{
	resultLabel = new QLabel(this);
	numberLabel = new QLabel(this);
	searchEdit = new QLineEdit(this);
	searchButton = new QPushButton("Search",this);
	scrollArea = new QScrollArea(this);
	searchStr = "";
	resultStr = "";
	oldStr = "";

	resultLabel->setFrameShape(QFrame::Panel);
	resultLabel->setFrameShadow(QFrame::Sunken);
	resultLabel->setStyleSheet("background-color:rgb(233,233,233)");
	resultLabel->resize(1000, 1000);
	resultLabel->setAlignment(Qt::AlignTop);
	resultLabel->setWordWrap(true);

	QFont font;//�����ı�����
	font.setFamily("����");
	resultLabel->setFont(font);

	searchEdit->setPlaceholderText("����������");

	searchButton->setStyleSheet("background-color:rgb(233,233,233)");

	scrollArea->setWidget(resultLabel);

}

void SearchBackground::showResult(QStringList *resultList, QStringList wordList)
{
	numberLabel->setText(QString("Ϊ���ҵ���ؽ��Լ%1��").arg(resultList->size()));
	resultLabel->resize(1000, max(1000, 150 * resultList->size() + 100));
	resultStr = "";
	QString temp_content = "", temp_title = "";
	for (int i = 0; i < resultList[0].size(); i++)
	{
		temp_content += "<font color='#000000' size='4'>" + resultList[2][i] + "</font>";
		temp_title += "<font color='#0000dd' size='5'><u>" + resultList[1][i] + "</u></font>";
		for (int i = 0; i < wordList.size(); i++)
		{
			temp_content.replace(wordList[i], QString("<font color='#dd0000'>" + wordList[i] + "</font>"));
			temp_title.replace(wordList[i], QString("<font color='#dd0000'>" + wordList[i] + "</font>"));
		}
		resultStr += "<style> a {text-decoration: none} </style><a href=" + resultList[0][i] + ">" + temp_title + "<\a><br/>" + temp_content + "<br/><br/>";
		temp_content = "";
		temp_title = "";
	}
	if (resultList->size() == 0)
	{
		resultStr = QString("<font color='#000000' size='5'>�ܱ�Ǹ��û���ҵ������ҳ�������������ӻ���ȷ��ʽ�������롣</font>");
	}
	resultLabel->setOpenExternalLinks(true);
	resultLabel->setText(resultStr);
	resultLabel->show();
}

void SearchBackground::resizeEvent(QResizeEvent *event)
{
	Q_UNUSED(event);//�������������
	this->setAutoFillBackground(true);//�Զ���䱳��

	//��ӱ���
	QImage image;
	QPalette palette;
	image.load(":/SalesLeadRetrievalUI/SearchBackground");

	palette.setBrush(this->backgroundRole(),
		QBrush(image.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation)));//���ñ�����ˢ

	this->setPalette(palette);

	//ʹ�ı�������Ӧ
	searchButton->setGeometry(geometry().x() + 700, geometry().y() + 150, 100, 50);
	searchEdit->setGeometry(geometry().x() + 100, geometry().y() + 150, 600, 50);
	numberLabel->setGeometry(geometry().x() + 100, geometry().y() + 200, 700, 50);
	scrollArea->setGeometry(geometry().x() + 100, geometry().y() + 250, 700, 500);
}
