#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_APP.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "Player.h"
#include "Question.h"

class Player;
class Question;

class Qt_APP : public QMainWindow{
    Q_OBJECT
     int current_index = -1;

    private slots:
        void freeze();
        int Level_Input();
        QString Name_Input();
        void Set_Game();        
        void loop_questions();

    private:
        Ui::Qt_APPClass ui;

       
    public:
        Qt_APP(QWidget *parent = nullptr);
        ~Qt_APP();
};
