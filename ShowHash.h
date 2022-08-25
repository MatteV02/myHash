#pragma once

#include <QDialog>
#include <string>
#include "ui_ShowHash.h"

class ShowHash : public QDialog
{
	Q_OBJECT

public:
	ShowHash(std::string& hash, QWidget* parent = nullptr);
	~ShowHash();

private:
	Ui::ShowHashClass ui;
};
