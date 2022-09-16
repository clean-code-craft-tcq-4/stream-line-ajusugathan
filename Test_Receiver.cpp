#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include <iostream>
#include "Receiver/BMS_DataReceiver.hpp"
#include <cstdlib> 
#include <ctime> 



TEST_CASE("TEST_CASE 1 :: Reading Data From Stdin") {
  
    std::vector<std::string>outputstreamdata{};
	assert(readingfromstdin(outputstreamdata) == true);
	assert(printmaxandminvalue(outputstreamdata) == true);
	assert(printaverage(outputstreamdata) == true);
}
//TEST_CASE("TEST_CASE 2 :: Fail to Generate Parameters of Battery") {
//  
//    Battery batteryobj;
//    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
//	assert(batteryobj.printoutputtocommunicate() == false);
//}