#include"CP_MyDictionary.h"
#define MaxWordLength 20

myDictionary::myDictionary()
{
	string s;

	//录入词库的词和专业用语
	ifstream infile1("lexicon.dic");//打开词库
	if (!infile1.is_open())exit(-1);//打开文件失败，返回
	cout << "正在录入词库..." << endl;
	while (getline(infile1, s))
	{
		HashDictionary.insert(pair(s, 1));
	}
	infile1.close();

	ifstream infile2("terminology.txt");//打开专业用语
	if (!infile2.is_open())exit(-1);//打开文件失败，返回
	while (getline(infile2, s))
	{
		HashDictionary.insert(pair(s, 1));
	}
	infile2.close();
}

int myDictionary::FindWord(myString str)
{
	if (HashDictionary.find(str.m_str) != HashDictionary.end())
		return 1;
	else
		return 0;
}

void myDictionary::SegmentSentence(myString strToSegment, myStringList &List)
{
	myString strHandled;//将要分词的字符串进行预处理，只保留汉字
	myString finalStr;//最后的结果
	for (int i = 0; i < strToSegment.length; i++)//预处理
	{
		myString tempStr = "";
		myString commaStr = "，";//中文逗号
		myString fullStopStr = "。";//中文句号
		myString semicolonStr = "；";//中文分号
		myString exclamatoryStr = "！";//中文感叹号
		myString hyphenStr = "-";//中文连接号
		myString colonStr = "：";//中文冒号
		myString virguleStr = "/";//中文斜线号
		myString slightPauseStr = "、";//中文斜线号

		if (strToSegment[i] >= 0)continue;
		else
		{
			tempStr = tempStr + strToSegment[i];
			tempStr = tempStr + strToSegment[++i];
			if (tempStr.IndexOf(commaStr) == -1 &&
				tempStr.IndexOf(fullStopStr) == -1 &&
				tempStr.IndexOf(semicolonStr) == -1 &&
				tempStr.IndexOf(exclamatoryStr) == -1&&
				tempStr.IndexOf(hyphenStr) == -1&&
				tempStr.IndexOf(colonStr) == -1&&
				tempStr.IndexOf(virguleStr) == -1&&
				tempStr.IndexOf(slightPauseStr) == -1)
			{
				strHandled = strHandled + tempStr[0];
				strHandled = strHandled + tempStr[1];
			}
		}
	}

	while (strHandled.length != 0)
	{
		int tempLen = strHandled.length;
		if (tempLen > MaxWordLength)//大于最大词长
		{
			tempLen = MaxWordLength;
		}

		myString tempStr;
		tempStr.SubString(strHandled, strHandled.length - tempLen, tempLen);
		int tempNum = FindWord(tempStr);
		while (tempLen > 2 && tempNum == 0)
		{
			tempLen -= 2;
			tempStr.SubString(strHandled, strHandled.length - tempLen, tempLen);
			tempNum = FindWord(tempStr);
		}
		if (tempStr.length > 2 && finalStr.IndexOf(tempStr)==-1)//存入不重复的词
		{
			List.addNode(tempStr);
		}
		strHandled.SubString(strHandled, 0, strHandled.length - tempLen);
	}


}