#include "BMS_DataReceiver.hpp"
void sensorstreams::stringtofloat(const std::vector<std::string>&outputstreamdata,std::vector<float>&outputfloatdata)
{
	for(std::string val : outputstreamdata)
        {  outputfloatdata.push_back(std::stof(val));  }
}
std::vector<float> sensorstreams::getnumberoutputstream(std::vector<std::string>&outputstreamdata)
{
	std::vector<float>outputfloatdata{}; 	
	stringtofloat(outputstreamdata,outputfloatdata);
	std::sort(outputfloatdata.begin(),outputfloatdata.end());
	return outputfloatdata;
}
void sensorstreams::printvalue(float value, std::string str="")
{
	std::cout << str << value << std::endl;
}
bool sensorstreams::readingfromstdin()
{
	try{
	   int c =0;
	    for (std::string line; std::getline(std::cin, line);) {
            if(c > 10)
	     	 {			 
	   	      outputstreamdata.push_back(line);
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
bool sensorstreams::printmaxandminvalue()
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
bool sensorstreams::printaverage()
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