#pragma once
#pragma once
#include <iostream>
#include <string>

class Toy {
private:
	std::string name;

public:
	Toy(std::string _name) : name(_name) { name = _name; }
	Toy(const Toy& oth) {
		name = oth.name;
	}
	Toy& operator=(const Toy& oth) {
		name = oth.name;
	}
	~Toy() {
		std::cout << "\n Toy " << name << " is deleted!";
	}

	std::string get_name() {
		return name;
	}
};


class Shared_ptr_toy {
private:
	Toy* obj;
	int* p_count;

	void deleteObj() {
		if (obj != nullptr) {
			delete obj;
			obj = nullptr;
		}
		if (p_count != nullptr) {
			delete p_count;
			p_count = nullptr;
		}
	}
	void print_position() {
		std::cout << "\n Shared pointer " << this << " || Object = " << obj
			<< (obj ? " name= " + obj->get_name() : "") << " " << (p_count ? *p_count : 0) << "";
	}

public:

	static Shared_ptr_toy* make(std::string _name) {
		return new Shared_ptr_toy(Toy(_name));
	}

	Shared_ptr_toy(Toy _toy) {
		p_count = nullptr;
		obj = nullptr;

		if (&_toy) {
			obj = new Toy(_toy);
			p_count = new int(1);
		}
		else {
			return;
		}
	}
	Shared_ptr_toy() : Shared_ptr_toy(Toy("SomeToy")) {}
	Shared_ptr_toy(const Shared_ptr_toy& oth) {
		if (&oth != nullptr) {
			if (oth.obj && oth.p_count) {
				obj = oth.obj;
				p_count = oth.p_count;
				++*p_count;
			}
			else {
				std::cout << this << "\n RESET shared pointer!";
			}
		}
		else {
			std::cout << this << "\n Not init shared pointer!";
		}
	}
	Shared_ptr_toy& operator=(const Shared_ptr_toy& oth) {
		if (this == &oth) {
			return *this;
		}
		else if (&oth) {
			if (oth.obj && oth.p_count) {
				if (obj != nullptr) {
					delete obj;
				}
				obj = oth.obj;
				p_count = oth.p_count;
			}
			++ * p_count;
			return *this;
		}
		else if (&oth == nullptr) {
			std::cout << "\n Right side not initialized!";
		}
	}
	~Shared_ptr_toy() {
		reset();
	}

	Toy* get() {
		return obj;
	}
	void print() {
		std::cout << "\n Shared pointer " << this << " || " << (get() ? get()->get_name() : "");
	}
	void reset() {
		if (p_count) {
			if (*p_count <= 0) {
				deleteObj();
				--*p_count;
			}
			else {
				p_count = nullptr;
				obj = nullptr;
			}
		}
	}
};