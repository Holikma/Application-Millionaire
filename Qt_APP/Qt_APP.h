#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_APP.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>

class Qt_APP : public QMainWindow{
    Q_OBJECT
    private slots:
        void Name_Input();
 
    private:
        Ui::Qt_APPClass ui;
        
    public:
        Qt_APP(QWidget *parent = nullptr);
        ~Qt_APP();


};
