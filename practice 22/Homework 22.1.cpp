#include <iostream>
#include <map>
#include <string>

void helpWall() {
    std::cout << "\n=================================\n";
    std::cout << "add\t- add subscriber\n";
    std::cout << "phone\t- phone number search\n";
    std::cout << "name\t- name subscriber search\n";
    std::cout << "list\t- for print all phone's\n";
    std::cout << "exit\t- Exit\n";
    std::cout << "=================================\n";
}

std::string getCommand() {
    std::cout << "\nEnter command: ";
    std::string command;
    getline(std::cin, command);
    for (char& j : command) {
        j = (char)tolower(j);
    }
    return command;
}

bool checkNumber(std::string& const num) {
    const std::string regex = "+0123456789()-";
    for (char j : num) {
        if (regex.find(j) == std::string::npos) {
            return false;
        }
    }
    return true;
}

void insertToPhoneBook(std::map<std::string, std::string>& PhoneBook,
    const std::string& const name, const std::string const phone) {
    if (name.empty() || phone.empty()) {
        return;
    }
    auto iter = PhoneBook.find(name);
    if (iter == PhoneBook.end()) {
        PhoneBook.insert(std::pair<std::string, std::string>(name, phone));
    }
}

void addSubscriber(std::map<std::string, std::string>& phoneBook) {
    std::string name, phone;

    std::cout << "\nEnter name subscriber: ";
    getline(std::cin, name);
    if (name.empty()) {
        return;
    }
    std::cout << "Enter phone number: ";
    getline(std::cin, phone);
    if (phone.empty()) {
        return;
    }
    if (checkNumber(phone)) {
        insertToPhoneBook(phoneBook, name, phone);
    }
}

void findToNumber(std::map<std::string, std::string>& phoneBook) {
    std::string phone,res;
    std::cout << "\nEnter number for find: ";
    getline(std::cin, phone);
    if (phone.empty()) {
        return;
    }

    std::map<std::string, std::string>::iterator iter;
    iter = phoneBook.find(phone);
    if (iter != phoneBook.end()) {
        res = "Name: " + iter->first;
    }else {
        res = "Phone number not found!\n";
    }
    std::cout << res;
}

void findToName(std::map<std::string, std::string>& phoneBook) {
    std::string name, res;
    std::cout << "\nEnter name for find: ";
    getline(std::cin, name);
    if (name.empty()) {
        return;
    }

    std::map<std::string, std::string>::iterator iter;
    iter = phoneBook.find(name);
    if (iter != phoneBook.end()) {
        res = "Phone: " + iter->second;
    }else {
        res = "Phone number not found!\n";
    }
    std::cout << res;
}

void printAllPhones(std::map<std::string, std::string>& phoneBook) {
    for (std::map<std::string, std::string>::iterator iter = phoneBook.begin();
        iter != phoneBook.end(); ++iter) {
        std::cout << "\nPhone: " << iter->second << "\tName: " << iter->first << std::endl;
    }
}

void processPhoneBook(std::map<std::string, std::string>& phoneBook) {
    helpWall();
    std::string enter;
    do {
        enter = getCommand();
        if (enter == "add") {
            addSubscriber(phoneBook);
        }
        else if (enter == "phone") {
            findToNumber(phoneBook);
        }
        else if (enter == "name") {
            findToName(phoneBook);
        }
        else if (enter == "list") {
            printAllPhones(phoneBook);
        }

    } while (enter != "exit");
    
}

int main() {
	std::cout << "\t\tPhone Book\n\n";

    std::map<std::string, std::string> phoneBook;
    processPhoneBook(phoneBook);

	return 0;
}
