#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat test("Yvette", 4);

	std::cout << test.getGrade() << test.getName() << std::endl;
	return 0;
}