#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    // Constructor && Destructor
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // Variables
    Ui::MainWindow *ui;
    QString file_path;

    // Methods
    QImage blurImage(QImage src, int blur_rad);
    void processSingleImage(QString file_path);

public slots:
    void createFileDialog();
    void setBlurEffectOnImage();
};
#endif // MAINWINDOW_H
