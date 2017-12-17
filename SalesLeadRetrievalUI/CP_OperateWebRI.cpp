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
	analysis_list[num].addNode(webRI->Website[num]);//�ȼ�����ַ
	int i = 0;
	bool AddContent = NULL;//��Ϊ��ֻ��һ�����ݣ�����ֻ�����������
	bool AddAuthor = NULL;//ֻ�������
	bool AddDate = NULL;//�������
	bool AddLabel = NULL;//��ӱ�ǩ
	bool AddTitle = NULL;
	while (i < webRI_vector[num].length - 1)
	{
		if (webRI_vector[num][i] == '<')//��һ����ǩ
		{
			stack->Push(webRI_vector[num], i);//����ǩѹ��ջ
			stackData tempData;
			myString tempLabel;
			tempData = stack->Top();//��ȡջ����ǩ

			tempLabel = "<div class=\"z\">";//�з������ࡢ����С��ͱ���
			if (tempData.label.IndexOf(tempLabel)!=-1 && !AddTitle)
			{
				int temp_num = 0;//��ȡ����Ϣ��
				while (true)
				{
					if (webRI_vector[num][i] == '<')
					{
						stack->Push(webRI_vector[num], i);
						tempData = stack->Top();
						if (tempData.No == 2)//<a��ͷ��ǩ
							temp_num++;
						if (temp_num >= 3 && tempData.No == 2)
						{
							myString str;//�洢��Ϣ
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
						}//�õ�����������Ϣ���˳�
					}

					i++;
				}
			}

			tempLabel = "<td class=\"t_f\"";//�з�������
			if (tempData.label.IndexOf(tempLabel) != -1&&!AddContent)
			{
				AddContent = true;
				int temp_num = 0;
				myString str;//�洢��Ϣ
				myString unicodeStr = "";//��¼unicode�ı���
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
						else if (unicodeStr.length != 0)//��������ֻ���ĸ
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
					else if(webRI_vector[num][i] == '&')//��ʼunicode����
					{
						i++;
						while (true)
						{
							if (webRI_vector[num][i] != ';')
							{
								unicodeStr = unicodeStr + webRI_vector[num][i];
								i++;
							}
							else if (webRI_vector[num][i] == ';')//unicode�����
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
								unicodeStr = "";//��ԭ
								i++;
								break;
							}
						}
						continue;
					}
					else//�������ַ�
					{
						if (webRI_vector[num][i] == ',')//��Ӣ�Ķ���,��ֹ���ʱ�ָ�Ĵ���
						{
							myString s = "��";
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

			tempLabel = "<div class=\"authi\">";//�з�������
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
						myString str;//�洢��Ϣ
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

			tempLabel = "<em id"; //�з�������
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
						myString str;//�洢��Ϣ
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

			tempLabel = "<div class=\"ts z h1\">"; //�з�������
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
						myString str;//�洢��Ϣ
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
	ofile << "���,��ַ,��������,����С��,��������,��������,������,����ʱ��,��������,�ִʽ��" << endl;
	for (int i = 0; i < number; i++)
	{
		ofile << i + 1 << ",";//������
		myStringNode *temp_node = analysis_list[i].head->next;
		while (temp_node != NULL)
		{
			ofile << temp_node->data.m_str << ",";
			temp_node = temp_node->next;
		}

		//����ִʽ��
		temp_node = segment_list[i].head->next;
		while (temp_node != NULL)
		{
			ofile << temp_node->data.m_str << " ";
			temp_node = temp_node->next;
		}

		ofile << endl;
	}
	ofile.close();
	cout << "����������" << endl;
}

