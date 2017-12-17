#include "SalesLeadRetrievalUI.h"
#include <QtWidgets/QApplication>
#include"CP_MyIndex.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SalesLeadRetrievalUI w;
	w.show();

	return a.exec();
}
