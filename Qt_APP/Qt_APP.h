#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qt_APP.h"


class Qt_APP : public QMainWindow{
    Q_OBJECT
    private slots:

    private:
        Ui::Qt_APPClass ui;

    public:
        Qt_APP(QWidget *parent = nullptr);
        ~Qt_APP();


};
