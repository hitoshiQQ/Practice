#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegExp>
#include <QRegularExpression>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText)
            {
        QRegularExpression exp("^\\+\\d{11}$");
        if(exp.match(currentText).hasMatch()) {
            setOkLabel();

        } else {
            setNotOkLabel();
        }
    });
}

MainWindow::~MainWindow() {

    delete ui;
}


void MainWindow::setOkLabel() {

    ui->label->setText("OK!");
    ui->label->setStyleSheet("QLabel {color: green} ");
}

void MainWindow::setNotOkLabel() {

    ui->label->setText("NOT OK!");
    ui->label->setStyleSheet("QLabel {color: red} ");
}
