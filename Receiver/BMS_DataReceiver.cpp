#include "BMS_DataReceiver.hpp"

bool readingfromstdin()
{
	int c =0;
	 for (std::string line; std::getline(std::cin, line);) {
		 if(c>4)
		 {
           std::cout << line << std::endl;
		 }
		 c++;
        }
	return true;
}