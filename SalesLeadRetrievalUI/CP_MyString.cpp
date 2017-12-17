#include"CP_MyString.h"

myString::myString():
	length(0),
	m_str("")
{
}

myString::myString(string str):
	m_str(str)
{
	length = str.length();
}

void myString::GetNext(myString T, int* next)
{
	int j = 0, k = -1;
	int length = T.length;
	next[0] = -1;

	while (j < length)
	{
		if (k == -1 || T[j] == T[k])
		{
			++j;
			++k;
			next[j] = k;
		}
		else k = next[k];
	}
}

//×Ö·û´®²éÕÒ
int myString::IndexOf(myString T,int pos)
{
	int i = pos;
	int j = 0;
	int length2 = T.length;
	int *next = new int[length2 + 1];
	int final_num;
	GetNext(T, next);

	while (i < length&&j < length2)
	{
		if (j == -1 || m_str[i] == T[j])
		{
			++i;
			++j;
		}
		else j = next[j];
	}
	if (j >= length2)
		final_num = i - length2;
	else
		final_num = -1;
	delete[] next;
	return final_num;
}

//×Ö·û´®¿½±´
void myString::SubString(myString str, int pos, int len)
{
	char *temp_s = new char[len + 1];
	stringstream ss;
	for (int i = 0, j = pos; i < len; i++, j++)
	{
		temp_s[i] = str[j];
	}
	temp_s[len] = '\0';
	ss << temp_s;
	ss >> m_str;
	length = len;
	delete[]temp_s;
}

//×Ö·û´®·Ö¸î
void myString::SplitString(vector<myString>& v, myString c)
{
	string::size_type pos1, pos2;
	pos2 = this->IndexOf(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		myString temp_str;
		temp_str.SubString(*this, pos1, pos2 - pos1);
		v.push_back(temp_str);

		pos1 = pos2 + c.length;
		pos2 = this->IndexOf(c, pos1);
	}
	if (pos1 != length)
	{
		myString temp_str;
		temp_str.SubString(*this, pos1, length - pos1);
		v.push_back(temp_str);
	}
}

//×Ö·û´®Á¬½Ó
void myString::ConcatString(myString str)
{
	m_str += str.m_str;
	length += str.length;
}

myString& myString::operator=(const string &str)
{
	m_str = str;
	length = str.length();
	return *this;
}

myString& myString::operator=(const myString &myStr)
{
	m_str = myStr.m_str;
	length = myStr.length;
	return *this;
}

myString& myString::operator+(const char &ch)
{
	m_str += ch;
	length++;
	return *this;
}
