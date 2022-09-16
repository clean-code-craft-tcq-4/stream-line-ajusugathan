#pragma once
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
using namespace std;

class sensorstreams{
	public:
			std::vector<float> temperaturestream{};
			std::vector<float> socstream{};
			std::vector<std::string>outputstreamdata{};
			bool readingfromstdin();
			bool printmaxandminvalue();
			bool printaverage();
			void stringtofloat(const std::vector<std::string>&outputstreamdata,std::vector<float>&outputfloatdata);
			std::vector<float> getnumberoutputstream(std::vector<std::string>&outputstreamdatas);
			void printvalue(float value, std::string str);
};