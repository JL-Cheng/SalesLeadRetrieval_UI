#include"CP_OperateWebRI.h"

operateWebRI::operateWebRI(int num)
{
	analysis_list = new myStringList[num];
	segment_list = new myStringList[num];
	number = num;
	webRI = new extractWebRI(number);

}

void operateWebRI::webRIAnalysis(int num)
{
	myStack *stack = new myStack(10000);
	analysis_list[num].addNode(webRI->Website[num]);//先加入网址
	int i = 0;
	bool AddContent = NULL;//因为不只有一份内容，所以只添加主贴内容
	bool AddAuthor = NULL;//只添加作者
	bool AddDate = NULL;//添加日期
	bool AddLabel = NULL;//添加标签
	bool AddTitle = NULL;
	while (i < webRI_vector[num].length - 1)
	{
		if (webRI_vector[num][i] == '<')//是一个标签
		{
			stack->Push(webRI_vector[num], i);//将标签压入栈
			stackData tempData;
			myString tempLabel;
			tempData = stack->Top();//获取栈顶标签

			tempLabel = "<div class=\"z\">";//有发帖大类、发帖小类和标题
			if (tempData.label.IndexOf(tempLabel)!=-1 && !AddTitle)
			{
				int temp_num = 0;//获取的信息数
				while (true)
				{
					if (webRI_vector[num][i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						tempData = stack->Top();
						if (tempData.No == 2)//<a开头标签
							temp_num++;
						if (temp_num >= 3 && tempData.No == 2)
						{
							myString str;//存储信息
							int j = i;
							while (webRI_vector[num][j] != '<')
							{
								str = str + webRI_vector[num][j];
								j++;
							}
							i = j;
							i--;
							analysis_list[num].addNode(str); 
						}
						if (temp_num == 5)
						{
							AddTitle = true;
							stack->Push(webRI_vector[num], i);
							break;
						}//得到三条有用信息后退出
					}

					i++;
				}
			}

			tempLabel = "<td class=\"t_f\"";//有发帖内容
			if (tempData.label.IndexOf(tempLabel) != -1&&!AddContent)
			{
				AddContent = true;
				int temp_num = 0;
				myString str;//存储信息
				myString unicodeStr = "";//记录unicode的编码
				while (true)
				{
					if (webRI_vector[num][i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						if (temp_num == 0)
						{
							temp_num = 1;
							continue;
						}
						else if (unicodeStr.length != 0)//最后有数字或字母
						{
							for (int temp_l = 0; temp_l < unicodeStr.length; temp_l++)
							{
								str = str + unicodeStr[temp_l];
							}
						}
						analysis_list[num].addNode(str);
						break;
					}
					else if (webRI_vector[num][i] == '\n' || webRI_vector[num][i] == '\r' || webRI_vector[num][i] == ' ')
					{
						i++;
						continue;
					}
					else if(webRI_vector[num][i] == '&')//开始unicode编码
					{
						i++;
						while (true)
						{
							if (webRI_vector[num][i] != ';')
							{
								unicodeStr = unicodeStr + webRI_vector[num][i];
								i++;
							}
							else if (webRI_vector[num][i] == ';')//unicode码结束
							{
								unsigned short number = 0;
								char czChinese[3];
								wchar_t wcChinese[2];
								myString spaceStr = "nbsp";
								if (unicodeStr[0] == '#')
								{
									for (int k = 1; k < unicodeStr.length; k++)
									{
										number = number * 10 + unicodeStr[k] - '0';
									}
									wcChinese[0] = number;
									wcChinese[1] = 0;
									WideCharToMultiByte(0, 0, wcChinese, -1, czChinese, sizeof(czChinese), NULL, NULL);
									str = str + czChinese[0];
									str = str + czChinese[1];
								}
								else if(unicodeStr.IndexOf(spaceStr)!=-1)
								{
									str = str + ' ';
								}
								unicodeStr = "";//还原
								i++;
								break;
							}
						}
						continue;
					}
					else//是其他字符
					{
						if (webRI_vector[num][i] == ',')//是英文逗号,防止输出时分割的错误
						{
							myString s = "，";
							str = str + s[0];
							str = str + s[1];
							i++;
							continue;
						}
						str = str + webRI_vector[num][i];
						i++;
						continue;
					}
				}
			}

			tempLabel = "<div class=\"authi\">";//有发帖作者
			if (tempData.label.IndexOf(tempLabel) != -1 && !AddAuthor)
			{
				AddAuthor = true;
				while (true)
				{
					if (webRI_vector[num][i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						continue;
					}
					else
					{
						myString str;//存储信息
						int j = i;
						while (webRI_vector[num][j] != '<')
						{
							str = str + webRI_vector[num][j];
							j++;
						}
						i = j;
						analysis_list[num].addNode(str);
						stack->Push(webRI_vector[num], i);
						break;
					}
				}
			}

			tempLabel = "<em id"; //有发帖日期
			if (tempData.label.IndexOf(tempLabel) != -1 && !AddDate)
			{
				while (true)
				{
					if (webRI_vector[num][i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						break;
					}
					else if(!AddDate&&webRI_vector[num][i]>='0'&& webRI_vector[num][i]<='9')
					{
						myString str;//存储信息
						int j = i;
						while (webRI_vector[num][j] != ' ')
						{
							str = str + webRI_vector[num][j];
							j++;
						}
						i = j;
						analysis_list[num].addNode(str);
						AddDate = true;
					}
					else
					{
						i++;
						continue;
					}
				}
			}

			tempLabel = "<div class=\"ts z h1\">"; //有发帖类型
			if (tempData.label.IndexOf(tempLabel) != -1 && !AddLabel)
			{
				while (true)
				{
					if (webRI_vector[num][i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						continue;
					}
					else if(webRI_vector[num][i] == '[')
					{
						myString str;//存储信息
						int j = i;
						while (webRI_vector[num][j] != '<')
						{
							str = str + webRI_vector[num][j];
							j++;
						}
						i = j;
						analysis_list[num].addNode(str);
						AddLabel = true;
						break;
					}
					else
					{
						i++;
						continue;
					}

				}
			}

		}
		else
		{
			i++;
			continue;
		}
	}
	delete stack;
}

void operateWebRI::webRISegment(int num)
{
	myString title;
	myString content;
	myString segmentFinal;
	myStringNode *temp_node = analysis_list[num].head->next;
	if (temp_node == NULL)return;
	int a = 1;

	while (true)
	{
		temp_node = temp_node->next;
		a++;
		if (a == 4)
		{
			title = temp_node->data;
		}
		if (a == 8)
		{
			content = temp_node->data;
		}
		if (temp_node == NULL)break;
	}

	segmentFinal = title;
	for (int i = 0; i < content.length; i++)
	{
		segmentFinal = segmentFinal + content[i];
	}

	dictionary.SegmentSentence(segmentFinal, segment_list[num]);

}

void operateWebRI::printWebRI()
{
	ofstream ofile;
	ofile.open("output/result.csv", ios::out | ios::trunc);
	ofile << "序号,网址,发帖大类,发帖小类,发帖标题,发帖类型,发帖人,发帖时间,发帖内容,分词结果" << endl;
	for (int i = 0; i < number; i++)
	{
		ofile << i + 1 << ",";//输出序号
		myStringNode *temp_node = analysis_list[i].head->next;
		while (temp_node != NULL)
		{
			ofile << temp_node->data.m_str << ",";
			temp_node = temp_node->next;
		}

		//输出分词结果
		temp_node = segment_list[i].head->next;
		while (temp_node != NULL)
		{
			ofile << temp_node->data.m_str << " ";
			temp_node = temp_node->next;
		}

		ofile << endl;
	}
	ofile.close();
	cout << "已输出结果。" << endl;
}

