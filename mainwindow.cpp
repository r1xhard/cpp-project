#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <iostream>
#include "ringbuffer.h"

using namespace std;
ringbuffer *rb = new ringbuffer();



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow(){
    delete ui;
    delete rb;
}

void MainWindow::setInputText(QString text){
    ui->textEdit->setText(text);
}

void MainWindow::setOutputText(QString text) {

    bool nl = false;
    stringstream output;

    for(int i=0; i<text.count(); i++){
        rb->ringbuffer_add(text[i].toLatin1());
    if(text[i] == '\n'){
        nl = true;
    }
}

    if(nl){
        while(1){
            char nc = rb-> ringbuffer_get();
            output << nc;
            if(nc == '\n'){


        ui->textEdit_2->setText(QString::fromStdString(output.str()));
        break;
            }
        }
    }
}
    /*
     * Aufgabe: Nehmen Sie bitte den Input (text) engegen und
     * speichern Sie alle einzelnen Zeichen in einem Ringpuffer ab.
     * anschließend gehen Sien den Rinpuffer von Beginn an durch und
     * suchen sie nach einem Zeilenumbruch. Wenn Sie den Zeilenumbruch
     * gefunden haben, entnehmen sie alle zeichen inklusive dem umbruch
     * und geben ssie diese im unteren textfeld aus.
     */



