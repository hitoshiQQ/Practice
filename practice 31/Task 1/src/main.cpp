#include "Dog.h"
#include "Toy.h"
#include <iostream>

int main() {
	std::shared_ptr<Toy> ball = std::make_shared<Toy>("ball");
	std::shared_ptr<Toy> bone = std::make_shared<Toy>("bone");

	Dog a("Arik", ball, 12);
	Dog b("Bobik", bone, 13);

	a.dropToy();
	a.dropToy();
	a.getToy(bone);

	b.getToy(ball);
	b.getToy(ball);

	a.getToy(bone);


	return 0;
}