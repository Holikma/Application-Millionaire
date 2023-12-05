#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_APP.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "Player.h"
#include "Question.h"


class Qt_APP : public QMainWindow{
    Q_OBJECT
    private slots:
        QString Name_Input();
        int Level_Input();
        void freeze();
        void Set_Game();

    private:
        Ui::Qt_APPClass ui;
        
    public:
        Qt_APP(QWidget *parent = nullptr);
        ~Qt_APP();
};
