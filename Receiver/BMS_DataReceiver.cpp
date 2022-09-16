#include "BMS_DataReceiver.hpp"
void stringtofloat(const std::vector<std::string>&outputstreamdata,std::vector<float>&outputfloatdata)
{
	for(std::string val : outputstreamdata)
        {  outputfloatdata.push_back(std::stof(val));  }
}
std::vector<float> getnumberoutputstream(std::vector<std::string>&outputstreamdata)
{
	std::vector<float>outputfloatdata{}; 	
	stringtofloat(outputstreamdata,outputfloatdata);
	sort(outputfloatdata.begin(),outputfloatdata.end());
}
void printvalue(float value, std::string str="")
{
	std::cout << str << value << std::endl;
}
bool readingfromstdin(std::vector<std::string>&outputstreamdata)
{
	try{
	   int c =0;
	    for (std::string line; std::getline(std::cin, line);) {
            if(c > 10)
	     	 {			 
	   	      outputstreamdata.push_back(line)
	   	     }
	   	 c++;
       }
	}
	catch(...)
	{
		return false;
	}
	return true;
}
bool printmaxandminvalue(std::vector<std::string>&outputstreamdata)
{
	try{
	  std::vector<float>outputfloatdata = getnumberoutputstream(outputstreamdata); 
	  printvalue(outputfloatdata[0],"Minimum values is :: ");
	  printvalue(outputfloatdata[outputfloatdata.size()-1],"Maximum  values is :: ");
	}
	catch(...)
	{
		return false;
	}
	return true;
}
bool printaverage(std::vector<std::string>&outputstreamdata)
{
	try{
	  float averageval = 0;	
	  std::vector<float>outputfloatdata = getnumberoutputstream(outputstreamdata);
	  for(auto val : outputfloatdata)
        { averageval += val;  }
	  printvalue(averageval/outputfloatdata.size(),"Average values is :: ");
	}
	catch(...)
	{
		return false;
	}
	return true;
}