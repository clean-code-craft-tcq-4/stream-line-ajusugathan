#define CATCH_CONFIG_MAIN

#include "test/catch.hpp"
#include <iostream>
#include "Receiver/BMS_DataReceiver.hpp"
#include <cstdlib> 
#include <ctime> 



TEST_CASE("TEST_CASE 1 :: Reading Data From Stdin") {
  
    sensorstreams objectofsensor;
	assert(objectofsensor.readingfromstdin() == true);
	assert(objectofsensor.printmaxandminvalue() == true);
	assert(objectofsensor.printaverage() == true);
}
//TEST_CASE("TEST_CASE 2 :: Fail to Generate Parameters of Battery") {
//  
//    Battery batteryobj;
//    std::srand(static_cast<unsigned int>(std::time(nullptr))); 
//	assert(batteryobj.printoutputtocommunicate() == false);
//}