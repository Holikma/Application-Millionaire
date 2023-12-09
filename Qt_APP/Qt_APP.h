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
#include <cstdlib>
#include <ctime>


class Qt_APP : public QMainWindow{
    Q_OBJECT
    int current_index = -1;

    private slots:
        void freeze();
        int Level_Input();
        QString Name_Input();
        void Set_Game();        
        void loop_questions();
        void submit_answer();

    private:
        Player player1;
        Question q;
        Ui::Qt_APPClass ui;

       
    public:
        void randomize_order(int* order);
        void check_answers(Question q);
        Qt_APP(QWidget *parent = nullptr);
        ~Qt_APP();
};
