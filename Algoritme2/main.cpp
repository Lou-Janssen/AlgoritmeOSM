#include "JobShop.h"

/**
 * deze functie returned een string met de naam + extensie van het meegegeven bestand op de commandline
 */
std::string getArg(char* argv[], int argc){
	std::string string = "";
	if(argc > 1){
		string = argv[1];
	}else{
		while(string == "") {
			std::cout << "Please enter a file: " << std::endl;
			std::cin >> string;
		}
	}
	return string;
}

int main(int argc, char **argv) {
	std::string inputFile = getArg(argv, argc);
	JobShop jobshop(inputFile);
	jobshop.run();
	return 0;
}





