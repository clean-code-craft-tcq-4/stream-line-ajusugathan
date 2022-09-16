#include "BMS_DataReceiver.hpp"
float sensorstreams::stringtofloat(std::string str)
{
        return std::stof(str);
}
void sensorstreams::splitstreamdata(std::string deli = ",")
{
	for(std::string val : outputstreamdata){
	     int start = 0;
         int end = val.find(deli);
         while (end != -1) {
             temperaturestream.push_back(stringtofloat(val.substr(start, end - start)));
             start = end + deli.size();
             end = val.find(deli, start);
         }
         socstream.push_back(stringtofloat(val.substr(start, end - start)));
	}
	std::sort(temperaturestream.begin(),temperaturestream.end());
	std::sort(socstream.begin(),socstream.end());
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
	   splitstreamdata(",");
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
	  printvalue(temperaturestream[0],"Minimum Temperature values is :: ");
	  printvalue(temperaturestream[temperaturestream.size()-1],"Maximum Temperature values is :: ");
	  
	  printvalue(socstream[0],"Minimum Soc values is :: ");
	  printvalue(socstream[socstream.size()-1],"Maximum Soc values is :: ");
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
	  for(auto val : temperaturestream)
        { averageval += val;  }
	  printvalue(averageval/temperaturestream.size(),"Average Temperature values is :: ");
	  
	  averageval = 0;	
	  for(auto val : socstream)
        { averageval += val;  }
	  printvalue(averageval/socstream.size(),"Average Soc values is :: ");
	}
	catch(...)
	{
		return false;
	}
	return true;
}