#ifndef TVREMOTE_H
#define TVREMOTE_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class tvRemote; }
QT_END_NAMESPACE

class tvRemote : public QMainWindow
{
    Q_OBJECT

public:
    tvRemote(QWidget *parent = nullptr);
    ~tvRemote();

private slots:

    void onDigitBtnClicked();
    void onVolumeUpBtnClicked();
    void onVolumeDownBtnClicked();
    void onChannelUpBtnClicked();
    void onChannelDownBtnClicked();

private:
    Ui::tvRemote *ui;
    int volume = 0;
    int channel = 0;
    QString volume_str;
    QString channel_str;
    QString buffer_str;
};
#endif // TVREMOTE_H
