#include <iostream>
#include "phone_process.h"

int main() {
	Mobile* mobile = new Mobile;
	mobile->processMobile();
	
	delete mobile;
	mobile = nullptr;
}