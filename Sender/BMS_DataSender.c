
#include <stdio.h>
#include <stdlib.h>
#include "BMS_DataSender.h"


OpeartionStatus_en Generate_SensorData(int DataSize,DataStructure *SensorData)
{
	OpeartionStatus_en GenerationStatus=DATA_GENERATION_FAILED;

	printf("\n Generating Temperature and State Of Charge\n");
	if((DataSize)&&(SensorData!=NULL))
	{
		GenerationStatus=DATA_GENERATION_OK;
		for(int count=0;count<DataSize;count++)
		{
			SensorData->Tempearature[count]=rand()%REQ_TEMPEARTURE_RANGE;
			SensorData->Soc[count]=rand()%REQ_SOC_RANGE;
		}
	}

	return(GenerationStatus);
}

void PrintData(int DataSize,DataStructure *SensorData)
{
    for(int count=0;count<DataSize;count++)
	{
		printf("%2f,%2f\n",SensorData->Tempearature[count],SensorData->Soc[count]);
	}
}

OpeartionStatus_en Send_SensorData(int DataSize,DataStructure *SensorData)
{
	OpeartionStatus_en GenerationStatus=DATA_SENDING_FAILED;
    if(SensorData!=NULL)
	{
		GenerationStatus=Generate_SensorData(DataSize,SensorData);
		if(GenerationStatus)
		{
			PrintData(DataSize,SensorData);
			GenerationStatus=DATA_SENDING_OK;
		}
	}
	return(GenerationStatus);
}

