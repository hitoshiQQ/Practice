#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>

class Button : public QPushButton {
    Q_OBJECT
public:
    // Constructor && Destructor
    Button(QWidget *parent);
    ~Button();

    // Methods
    void setUp();
    void setDown();
    void playSound();

private:
    // Variables
    QMediaPlayer* player;
    QAudioOutput* audio_output;
    QUrl sound_url = QUrl("qrc:/resources/button_press_sound.mp3");
    QPixmap button_default = QPixmap(":/resources/button_default.png");
    QPixmap button_press = QPixmap(":/resources/button_press.png");
};

#endif // BUTTON_H
