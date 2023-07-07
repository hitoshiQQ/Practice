#include "Talent.h"
#include "Counting.h"
#include "Dancing.h"
#include "Swimming.h"
#include "Dog.h"

int main() {
	Dog d("Steve");

	Talent* dance = new Dancing;
	Talent* swim = new Swimming;
	Talent* count = new Counting;
	d.addTalent(dance);
	d.addTalent(swim);
	d.addTalent(count);

	d.show_talents();

	return 0;
}