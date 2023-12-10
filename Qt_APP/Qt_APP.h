#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_APP.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QDebug>
#include "Player.h"
#include "Question.h"
#include <QMessageBox>


class Qt_APP : public QMainWindow{
    Q_OBJECT
    private slots:
        QString Name_Input();
        void Set_Game();        
        void loop_questions();

    private:
        Player player;
        Question q;
        Ui::Qt_APPClass ui;

       
    public:
        int Level_Input();
        void lock_in_input();
        void check_answers(int index);
        Qt_APP(QWidget *parent = nullptr);
        ~Qt_APP();
};
