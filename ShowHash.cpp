#include "ShowHash.h"

using namespace std;

ShowHash::ShowHash(string& hash, QWidget* parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	ui.OutputLine->setText(QString(hash.c_str()));
	int line_length = 7 * hash.size();
	ui.OutputLine->setFixedSize(QSize(line_length, 21));
	setFixedSize(QSize(line_length + 20, 160));
}

ShowHash::~ShowHash()
{}
