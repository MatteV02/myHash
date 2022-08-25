#pragma once

#include <QWidget>
#include "ui_FileHash.h"

#include "Algortithms.h"

class FileHash : public QWidget
{
	Q_OBJECT

public:
	FileHash(QWidget *parent = nullptr);
	~FileHash();

	void SetAlgorithm(Algorithms type);
	
public slots:
	void OpenFileDlg();
	void Hash();

private:
	Ui::FileHashClass ui;

	Algorithms alg;
};