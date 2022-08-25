#pragma once

#include <QWidget>
#include "ui_TextHash.h"

#include "Algortithms.h"

class TextHash : public QWidget
{
	Q_OBJECT

public:
	TextHash(QWidget *parent = nullptr);
	~TextHash();

	void SetAlgorithm(Algorithms type);

public slots:
	void Hash();

private:
	Ui::TextHashClass ui;

	Algorithms alg;
};
