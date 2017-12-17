#include"CP_MyDictionary.h"
#define MaxWordLength 20

myDictionary::myDictionary()
{
	string s;

	//¼��ʿ�Ĵʺ�רҵ����
	ifstream infile1("lexicon.dic");//�򿪴ʿ�
	if (!infile1.is_open())exit(-1);//���ļ�ʧ�ܣ�����
	cout << "����¼��ʿ�..." << endl;
	while (getline(infile1, s))
	{
		HashDictionary.insert(pair(s, 1));
	}
	infile1.close();

	ifstream infile2("terminology.txt");//��רҵ����
	if (!infile2.is_open())exit(-1);//���ļ�ʧ�ܣ�����
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
	myString strHandled;//��Ҫ�ִʵ��ַ�������Ԥ����ֻ��������
	myString finalStr;//���Ľ��
	for (int i = 0; i < strToSegment.length; i++)//Ԥ����
	{
		myString tempStr = "";
		myString commaStr = "��";//���Ķ���
		myString fullStopStr = "��";//���ľ��
		myString semicolonStr = "��";//���ķֺ�
		myString exclamatoryStr = "��";//���ĸ�̾��
		myString hyphenStr = "-";//�������Ӻ�
		myString colonStr = "��";//����ð��
		myString virguleStr = "/";//����б�ߺ�
		myString slightPauseStr = "��";//����б�ߺ�

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
		if (tempLen > MaxWordLength)//�������ʳ�
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
		if (tempStr.length > 2 && finalStr.IndexOf(tempStr)==-1)//���벻�ظ��Ĵ�
		{
			List.addNode(tempStr);
		}
		strHandled.SubString(strHandled, 0, strHandled.length - tempLen);
	}


}