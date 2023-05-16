#include <iostream>
#include "Boss.h"

int main() {
	
	auto* company = createCompany();

	while (!company->allTeamBusy()) {
		company->setOrder();
	}
	deleteCompany(company);
}