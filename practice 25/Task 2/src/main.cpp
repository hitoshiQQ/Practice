#include <iostream>
#include "cpu.h"
#include "gpu.h"
#include "hdd.h"
#include "memory.h"
#include "keyboard.h"

int main()
{
	std::string cmd_str;
	bool run = true;
	std::vector<int> vec;
	do {
		std::cout << "Enter command |sum - save - load - enter - display - exit |: ";
		std::cin >> cmd_str;
		if (cmd_str == "sum") {
			cpuComputer(memoryRead());
		}else if (cmd_str == "save") {
			hddSave(memoryRead());
		}else if (cmd_str == "load") {
			memoryWrite(hddLoad());
		}else if (cmd_str == "enter") {
			memoryWrite(enterKeyBoard());
		}else if (cmd_str == "display") {
			gpuDisplay(memoryRead());
		}else if (cmd_str == "exit") {
			run = false;
		}
	} while (run);

	return 0;
}
