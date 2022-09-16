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
			float stringtofloat(float outputfloatdata);
			void printvalue(float value, std::string str);
			void splitstreamdata(std::string deli);
};