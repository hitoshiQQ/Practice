#pragma once
#include <vector>
#include "mobile_contact.h"

class Mobile {
	enum Command {
		ADD,
		CALL,
		SMS,
		EXIT,
		NONE
	};

	enum Command command = NONE;
	std::vector<Contact> contact;

	Contact* findNumber() {
		std::string str = Contact::enterNumString();
		bool checkMobileNum = Contact::checkNum(str);
		for (int j = 0; j < contact.size(); ++j) {
			if (checkMobileNum && contact[j].getNumber() == str) {
				return &contact[j];
			}else if (!checkMobileNum && contact[j].getName() == str) {
				return &contact[j];
			}
		}
		Contact* contact = new Contact;
		contact->setName("Unkown");
		contact->setNumber("");
		return contact;
	}

	void add() {
		Contact* contact_new = new Contact;
		contact_new->enterName();
		contact_new->enterNumber();
		contact.push_back(*contact_new);
		delete contact_new;
		contact_new = nullptr;
	}

	void call() {
		std::cout << "\nEner Name/Number: ";
		Contact* contact = findNumber();
		std::cout << "Calling ~~" << contact->getNumber() << std::endl;
	}

	void sms(){
		std::string sms_text;
		std::cout << "Enter Name/Number: ";
		Contact* contact = findNumber();
		std::cout << "Enter sms: ";
		std::cin.ignore();
		std::getline(std::cin, sms_text);
		std::cout << "Sms ~~" << contact->getNumber() << "\nSms text: " << sms_text <<std::endl;
	}

	void getCommand() {
		std::string enter;
		std::cout << "Enter command [add,call,sms,exit]: ";
		std::cin >> enter;
		if (enter == "add") {
			command = ADD;
		}else if (enter == "call") {
			command = CALL;
		}else if (enter == "sms") {
			command = SMS;
		}else if (enter == "exit") {
			command = EXIT;
		}
	}

public: 
	void processMobile() {
		while (command == NONE) {
			getCommand();
			switch (command) {
			   case ADD: {
				   add();
				   break;
			   }
			   case CALL: {
				   call();
				   break;
			   }
			   case SMS: {
				   sms();
				   break;
			   }
			   case NONE: {
				   break;
			   }
			   case EXIT: {
				   return;
			   }
			}
			command = NONE;
		}
	}
};