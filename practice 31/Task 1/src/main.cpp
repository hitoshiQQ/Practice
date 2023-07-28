#include <iostream>
#include "shared_ptr_toy.h"

void print(Shared_ptr_toy& sp_toy) {
	if (&sp_toy) {
		std::cout << "shared ptr = " << &sp_toy << " " << (sp_toy.get() ? sp_toy.get()->get_name() : "") << std::endl;
	}
	else {
		std::cout << "Not initialized \n";
	}
}

int main() {

	Shared_ptr_toy a = Shared_ptr_toy(Toy("Ball"));
	a.print();

	{
		Shared_ptr_toy b = Shared_ptr_toy(a);
		b.print();
		Shared_ptr_toy c = Shared_ptr_toy(b);
		c.print();
	}
	{
		Shared_ptr_toy d = a;
		d.print();
		d.reset();
		d.print();
	}
	{
		Shared_ptr_toy e = Shared_ptr_toy();
		e.print();
		Shared_ptr_toy f = Shared_ptr_toy(Toy("Ball"));
		f.print();

		e.reset();
		e.print();
		f.reset();
		f.print();

	}
};