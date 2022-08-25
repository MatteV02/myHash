#include "myHash.h"

myHash::myHash(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

myHash::~myHash()
{}

void myHash::AlgorithmChanged(int type)
{
    ui.TextTab->SetAlgorithm((Algorithms)type);
    ui.FileTab->SetAlgorithm((Algorithms)type);
}