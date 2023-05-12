#include <iostream>
#include "playerClass.h"

int main() {
	AudioPlayer* audio_player = new AudioPlayer;
	audio_player->addTracks(Track::tracking("Frank Sinatra - Fly Me To The Moon", time(nullptr), 156));
	audio_player->addTracks(Track::tracking("Dorian Marko - Cornfield Chase", time(nullptr), 129));
	audio_player->addTracks(Track::tracking("Rick Astley - Never Gonna Give You Up", time(nullptr), 212));
	audio_player->addTracks(Track::tracking("Linkin Park - In The End", time(nullptr), 216));
	audio_player->addTracks(Track::tracking("a-ha - Take On Me",time(nullptr),243));
	audio_player->processAudioPlayer();
	std::cout << "\n\t\tHave a Good Day\n";

	delete audio_player;
	audio_player = nullptr;
}