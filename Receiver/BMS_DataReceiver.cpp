#include "BMS_DataReceiver.hpp"

bool readingfromstdin()
{
	 for (std::string line; std::getline(std::cin, line);) {
         std::cout << line << std::endl;
        }
	return true;
	
}