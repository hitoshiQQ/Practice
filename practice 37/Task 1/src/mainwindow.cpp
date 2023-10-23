#include "include/mainwindow.h"
#include "src/ui_mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QChar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    ui->label->clear();

    initialization();

    connect(ui->btn_key_0,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_1,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_2,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_3,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_4,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_5,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_6,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_7,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_8,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));
    connect(ui->btn_key_9,SIGNAL(clicked()),this,SLOT(digitBtnClicked()));

    connect(ui->btn_ac_ce,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_c,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_dot,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_plus,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_minus,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_mul,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_div,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_equal,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
    connect(ui->btn_ac_ce,SIGNAL(clicked()),this,SLOT(actionBtnClicked()));
}

MainWindow::~MainWindow(){

    delete ui;
}


void MainWindow::initialization(){

    is_decimal = false;
    action_state = false;
    digit_str = "0";
    result = 0;
    last_action = 0;
}

void MainWindow::digitBtnClicked(){

    if(last_action == '=') {
        initialization();

        ui->label->setText("");
    }

    action_state = false;

    QPushButton *btn_sender = qobject_cast<QPushButton*>(sender());
    if(digit_str == "0") {
        digit_str = btn_sender->text();
    } else {

        digit_str = digit_str.append(btn_sender->text());
    }

    ui->label->clear();
    ui->label->setText(digit_str);
}

void MainWindow::actionBtnClicked(){

    QPushButton *btn_sender = qobject_cast<QPushButton*>(sender());

    if(btn_sender->objectName() == "btn_ac_ce") {
        initialization();

        ui->label->setText(digit_str);
        ui->label->setText("");

        enableBtn();
    } else if(btn_sender->objectName() == "btn_ac_c") {
        if(last_action == '='){
            return;
        }

        digit_str = "0";
        is_decimal = false;

        ui->label->setText(digit_str);
    } else if(btn_sender->objectName() == "btn_ac_dot") {
        if(is_decimal) {
            return;
        }

        is_decimal = true;
        digit_str = digit_str.append(btn_sender->text());

    } else if(btn_sender->objectName() == "btn_ac_del") {
        if(digit_str == "0" || last_action == '=') {
            return;
        }

        int len = digit_str.length() - 1;
        QChar last_digit = digit_str[len];

        if(last_digit == '.') {
            digit_str = digit_str.left(len - 1);
            is_decimal = false;
        } else {
            digit_str = digit_str.left(len);

            if(len - 1 >= 0 and digit_str[len - 1] == '.') {
                digit_str = digit_str.left(len - 1);
                is_decimal = false;
            }
        }

        if(digit_str == "") {
            digit_str.append("0");
        }

        ui->label->clear();
        ui->label->setText(digit_str);

    } else {
        if(!action_state || btn_sender->objectName() == "btn_ac_equal"){
            calculate();
            ui->label->setText(QString::number(result));
        }

        action_state = true;

        if(btn_sender->objectName() == "btn_ac_plus")
            last_action = '+';
        else if(btn_sender->objectName() == "btn_ac_minus")
            last_action = '-';
        else if(btn_sender->objectName() == "btn_ac_mul")
            last_action = '*';
        else if(btn_sender->objectName() == "btn_ac_div")
            last_action = '/';
        else if(btn_sender->objectName() == "btn_ac_equal") {
            last_action = '=';
            action_state = false;
            digit_str = QString::number(result);
        }

        if(last_action != '='){
             ui->label->setText(QString(last_action));

        }else{
             ui->label->setText(QString(digit_str));
        }
    }
}

void MainWindow::calculate(){

    switch(last_action){

       case '+':
           result += digit_str.toFloat();
           break;

       case '-':
           result -= digit_str.toFloat();
           break;

       case '*':
           result *= digit_str.toFloat();
           break;

       case '/':
           if(digit_str.toFloat() != 0){
            result /= digit_str.toFloat();

           }else{
            QMessageBox::critical(this,"Error","Divide by zero!");
            ui->label->setText("NaN");
            disableBtn();

            return;
           }
           break;

       default:
           result = digit_str.toFloat();

    }

    ui->label->setText(QString::number(result));

    digit_str = "0";
    is_decimal = false;
}


void MainWindow::disableBtn(){

    ui->btn_key_0->setEnabled(false);
    ui->btn_key_1->setEnabled(false);
    ui->btn_key_2->setEnabled(false);
    ui->btn_key_3->setEnabled(false);
    ui->btn_key_4->setEnabled(false);
    ui->btn_key_5->setEnabled(false);
    ui->btn_key_6->setEnabled(false);
    ui->btn_key_7->setEnabled(false);
    ui->btn_key_8->setEnabled(false);
    ui->btn_key_9->setEnabled(false);

    ui->btn_ac_c->setEnabled(false);
    ui->btn_ac_dot->setEnabled(false);
    ui->btn_ac_plus->setEnabled(false);
    ui->btn_ac_minus->setEnabled(false);
    ui->btn_ac_mul->setEnabled(false);
    ui->btn_ac_div->setEnabled(false);
    ui->btn_ac_equal->setEnabled(false);
    ui->btn_ac_del->setEnabled(false);
}

void MainWindow::enableBtn(){

    ui->btn_key_0->setEnabled(true);
    ui->btn_key_1->setEnabled(true);
    ui->btn_key_2->setEnabled(true);
    ui->btn_key_3->setEnabled(true);
    ui->btn_key_4->setEnabled(true);
    ui->btn_key_5->setEnabled(true);
    ui->btn_key_6->setEnabled(true);
    ui->btn_key_7->setEnabled(true);
    ui->btn_key_8->setEnabled(true);
    ui->btn_key_9->setEnabled(true);

    ui->btn_ac_c->setEnabled(true);
    ui->btn_ac_dot->setEnabled(true);
    ui->btn_ac_plus->setEnabled(true);
    ui->btn_ac_minus->setEnabled(true);
    ui->btn_ac_mul->setEnabled(true);
    ui->btn_ac_div->setEnabled(true);
    ui->btn_ac_equal->setEnabled(true);
    ui->btn_ac_del->setEnabled(true);
}
