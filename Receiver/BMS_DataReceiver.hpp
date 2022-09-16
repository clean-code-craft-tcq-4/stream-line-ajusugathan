#pragma once
#include <assert.h>
#include <iostream>
#include <string>
#include <algorithm> 
#include <vector>
using namespace std;

bool readingfromstdin(std::vector<std::string>&outputstreamdata);
bool printmaxandminvalue(std::vector<std::string>&outputstreamdata);
bool printaverage(std::vector<std::string>&outputstreamdata);
void stringtofloat(const std::vector<std::string>&outputstreamdata,std::vector<float>&outputfloatdata);
std::vector<float> getnumberoutputstream(std::vector<std::string>&outputstreamdatas);