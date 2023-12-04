#include "Qt_APP.h"
#include "Question.h"
#include "Player.h"

#include <QtWidgets/QApplication>





int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Question q;
    q.loadQuestions();
    
    Qt_APP w;
    w.show();
    return a.exec();
 
}
