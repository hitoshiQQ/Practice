#pragma once
#include <vector>
#include "trackClass.h"


class AudioPlayer {

	enum Command {
		PLAY,
		PAUSE,
		NEXT,
		STOP,
		EXIT,
		NONE
	};

	std::vector<Track> playlist;
	enum Command command = NONE;
	enum Command condition = NONE;
	int current_track = 0;

	void getCommand() {
		std::string enter;
		std::cout << "Enter command [play,pause,next,stop,exit]: ";
		std::cin >> enter;
		if (enter == "play") {
			command = PLAY;
		}else if (enter == "pause") {
			command = PAUSE;
		}else if (enter == "next") {
			command = NEXT;
		}else if (enter == "stop") {
			command = STOP;
		}else if (enter == "exit") {
			command = EXIT;
		}
	}

	std::string enterName() {
		std::string enter;
		std::cout << "\nEnter name of the track: ";
		std::cin >> enter;
		return enter;
	}

	void play() {
		if(condition != PLAY) {
		playlist.at(current_track).play();
		condition = PLAY;
	    }
	}

	void pause() {
		if (condition != PAUSE && condition != STOP) {
			std::cout << "~Pause~\n";
			condition = PAUSE;
		}
	}

	void next() {
		condition = NEXT;
		std::srand(time(nullptr));
		current_track = abs(rand()) % playlist.size();
		play();
	}

	void stop() {
		if (condition == PLAY || condition == PAUSE) {
			std::cout << "-STOP-\n";
		}
		if (condition != STOP) {
			condition = STOP;
		}
	}

public:
	void addTracks(Track* track) {
		playlist.push_back(*track);
	}
	
	void processAudioPlayer() {
		while (true) {
			getCommand();
			switch (command) {
			   case PLAY: {
				   play();
				   break;
			   }
			   case PAUSE: {
				   pause();
				   break;
			   }
			   case NEXT: {
				   next();
				   break;
			   }
			   case STOP: {
				   stop();
				   break;
			   }
			   case EXIT: {
				   std::cout << "\nSee you soon\n";
				   return;
			   }
			   case NONE: {
				   break;
			   }
			}
			command = NONE;
		}
	}
};