#include "BMS_DataReceiver.hpp"

std::vector<std::string>outputstreamdata{};
bool readingfromstdin()
{
	int c =0;
	 for (std::string line; std::getline(std::cin, line);) {
         if(c < 9)
		 {			 
           std::cout << line << std::endl;
		 }
		 c++;
    }
	return true;
}