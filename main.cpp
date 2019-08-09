#include "nanotekspice.hpp"

int main(const int ac, const char * const av[]) {
	try {
		(void)ac;
		// Problem ici
		nts::Nanotekspice nanotek;

		nanotek.parseFile(av[1]);
		nanotek.run();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}