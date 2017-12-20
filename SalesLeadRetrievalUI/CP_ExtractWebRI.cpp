#include"CP_ExtractWebRI.h"

extractWebRI::extractWebRI(int num):
	FileName("input/url.csv"),
	number(num)
{
	GetWebsite();	

	m_NetManger = new QNetworkAccessManager;
}

extractWebRI::~extractWebRI()
{
	delete FileName;
	delete m_NetManger;
}

//获取网址
void extractWebRI::GetWebsite()//将网址存入字符串向量中
{
	ifstream file(FileName);
	myString temp_str;
	string temp_line;
	vector<myString> temp_str_vector;
	myString separator_str(",");//分割字符串
	myString myLine_str;//读入的每一行字符串
	myString webSite_str;//每个网址的字符串

	getline(file, temp_line);//去除第一行
	while (getline(file, temp_line))
	{
		temp_str_vector.clear();
		webSite_str = "";
		temp_str = temp_line;
		temp_str.SplitString(temp_str_vector, separator_str);
		for (int i = 1; i < temp_str_vector[1].length - 1; i++)
		{
			webSite_str = webSite_str + temp_str_vector[1][i];
		}
		Website.push_back(webSite_str);
	}

}

//读取网站内容
void extractWebRI::ReadWebsite(vector<myString> &str_vec)
{
	QNetworkReply *m_Reply;
	for (int i = 0; i < number; i++)
	{
		QUrl url(Website[i].m_str.data());

		m_Reply = m_NetManger->get(QNetworkRequest(url));
		m_Reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
		m_Reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
		if (m_Reply->error() == QNetworkReply::NoError)
		{
			QEventLoop eventLoop;
			connect(m_NetManger, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
			eventLoop.exec();       //block until finish
			QByteArray bytes = m_Reply->readAll();
			QString q_str = QString::fromLocal8Bit(bytes);
			string str = qstr2str(q_str);

			//将网页源码输入到向量中
			myString mStr(str);
			str_vec.push_back(mStr);

		}
		else
		{
			qDebug() << m_Reply->errorString();//输出错误信号
		}
		emit ReadNumber(i + 1);
	}

	m_Reply->deleteLater();
}