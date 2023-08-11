#pragma once
#include <exception>

class FishFoundException : public std::exception {
public:
	const char* what() const noexcept override {
		return "\nFish Caught!";
	}
};

class BootFoundException : public std::exception {
public:
	const char* what() const noexcept override {
		return "\nBoot Caught...";
	}
};