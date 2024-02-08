#include "button.h"
#include <iostream>

Button::Button(QWidget *parent) : QPushButton(parent) {

    player = new QMediaPlayer;
    audio_output = new QAudioOutput;
    player->setAudioOutput(audio_output);
    setUp();
    player->setSource(sound_url);
    audio_output->setVolume(100);

}

Button::~Button() {
    delete player;
}


void Button::setUp() {

    this->setIcon(button_default);
}

void Button::setDown() {

    this->setIcon(button_press);
}

void Button::playSound() {

    if(!player->isPlaying()) {

        std::cout << "Yes" << std::endl;
        player->play();
    }
}
