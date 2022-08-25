#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_myHash.h"

#include "Algortithms.h"

#include "TextHash.h"
#include "FileHash.h"

class myHash : public QMainWindow
{
    Q_OBJECT

public: 
    myHash(QWidget *parent = nullptr);
    ~myHash();

public slots:
    void AlgorithmChanged(int type);

private:
    Ui::myHashClass ui;
};
