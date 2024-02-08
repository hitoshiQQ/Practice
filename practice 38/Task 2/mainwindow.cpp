#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, ui->WebView, [plainTextEdit = ui->plainTextEdit, webView = ui->WebView]()
    {
        webView->setHtml(plainTextEdit->toPlainText());
    });
}

MainWindow::~MainWindow() {

    delete ui;
}

