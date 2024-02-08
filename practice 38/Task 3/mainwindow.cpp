#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

#include <QGraphicsScene>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include <QDir>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::blurImage(QImage src, int blur_rad) {
    if(src.isNull()) return {};

    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(src));

    auto *blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(blur_rad);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);

    QImage result(src.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);

    QPainter painter(&result);
    scene.render(&painter, QRectF(), QRectF(0, 0, src.width(), src.height()));
    delete blur;
    return result;
}

void MainWindow::processSingleImage(QString file_path) {

    QImage bluredImage = blurImage(QImage(file_path), ui->blurSlider->value());
    ui->imageLabel->setPixmap(QPixmap::fromImage(bluredImage.scaled(
        ui->imageLabel->width(),
        ui->imageLabel->height(),
        Qt::KeepAspectRatio)
    ));
}

void MainWindow::createFileDialog() {

    file_path = QFileDialog::getOpenFileName(nullptr, "Open Image", QDir::current().absolutePath() + "/source" ,"jpg files (*.jpg)");
    if(!file_path.isNull()) {

        processSingleImage(file_path);
    }
}

void MainWindow::setBlurEffectOnImage() {

    processSingleImage(file_path);
}
