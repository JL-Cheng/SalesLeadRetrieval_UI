#include"WorkerThread.h"

WorkerThread::WorkerThread(int num, myIndex *index, QObject *parent)
	:QThread(parent)
{
	myindex = index;
	number = num;
	status = 0;
	str = "";
}

WorkerThread::WorkerThread(QString q_str, int num, myIndex *index, QObject *parent)
	:QThread(parent)
{
	myindex = index;
	number = num;
	status = 1;
	str = q_str;
}

WorkerThread::~WorkerThread()
{
	// «Î«Û÷’÷π
	requestInterruption();
	quit();
	wait();
}

void WorkerThread::run()
{
	while (!isInterruptionRequested())
	{
		if (status == 0)
		{
			for (int i = 0; i < number; i++)
			{
				msleep(50);
				myindex->OWR->webRIAnalysis(i);
				myindex->OWR->webRISegment(i);
				emit AnalyseNumber(i + 1);
			}
			myindex->createIndex();
			vector<myString>(myindex->OWR->webRI_vector).swap(myindex->OWR->webRI_vector);
			return;
		}

		else if (status == 1)
		{
			myindex->Search(str);
			return;
		}

	}
}