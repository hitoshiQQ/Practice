#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();


private:
    // Variables
    Ui::MainWindow *ui;
    QString digit_str;
    float result;
    char last_action;

    // Accessors
    bool is_decimal;
    bool action_state;

    // Methods
    void initialization();
    void calculate();
    void disableBtn();
    void enableBtn();

private slots:
    void digitBtnClicked();
    void actionBtnClicked();

};
#endif // MAINWINDOW_H
