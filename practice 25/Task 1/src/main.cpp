#include <iostream>
#include "operation_process.h"

int main() {
	std::cout << "\t\tSurgery simulator\n\n";

	std::cout << "\nStart rule's of operations";
	std::cout << "\n|First command must be |SCALPEL|";
	std::cout << "\n|Last command must be SUTURE";
	std::cout << "\n|The coordinates must match";

	std::vector<MyCommand> op;
	enterOperation(op);
	if (checkOperation(op)) {
		std::cout << "Operation planned is correctly\n";
		processOperation(op);
	}else {
		std::cout << "Operation planned incorrectly!\n";
		processOperation(op);
	}
	std::cout << "\n\n\t\t\tProgram finished!!";
}