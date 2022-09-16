#include <stdio.h>
#include <stdlib.h>
#include "BMS_DataSender.h"

/*
 **********************************************************************************************************************
 * Service name         : Generate_SensorData
 * Syntax               : OpeartionStatus_en Generate_SensorData(int DataSize,DataStructure *SensorData)
 * param[in]            : DataSize    (total data size)
 * param[in]            : SensorData (pointer to the data holding structure)
 * return               : DATA_GENERATION_FAILED, DATA_GENERATION_OK
 * Description          : Function to generate random Temperature and SOC values 
 
 Note :-Please set the maximum possible data size in BMS_DataSender.h,default value is 100
 **********************************************************************************************************************
 */

OpeartionStatus_en Generate_SensorData(int DataSize,DataStructure *SensorData)
{
	OpeartionStatus_en GenerationStatus=DATA_GENERATION_FAILED;

	if((DataSize)&&(SensorData!=NULL))
	{
		printf("\n**Generating Temperature and State Of Charge**\n\n");
		GenerationStatus=DATA_GENERATION_OK;
		for(int count=0;count<DataSize;count++)
		{ 
	        /*REQ_TEMPEARTURE_RANGE value can be adjusted by user in BMS_DataSender.h,default value is 100*/
			SensorData->Tempearature[count]=rand()%REQ_TEMPEARTURE_RANGE;
			/*REQ_SOC_RANGE value can be adjusted by user in BMS_DataSender.h,default value is 100*/
			SensorData->Soc[count]=rand()%REQ_SOC_RANGE;
		}
	}

	return(GenerationStatus);
}

/*
 **********************************************************************************************************************
 * Service name         : PrintData
 * Syntax               : void PrintData(int DataSize,DataStructure *SensorData)
 * param[in]            : DataSize    (total data size)
 * param[in]            : SensorData (pointer to the data holding structure)
 * return               : Nill
 * Description          : Function to send/print the value in console
  
 Note :-Please set the maximum possible data size in BMS_DataSender.h,default value is 100
 **********************************************************************************************************************
 */
 
void PrintData(int DataSize,DataStructure *SensorData)
{
    for(int count=0;count<DataSize;count++)
	{
		printf("%2f,%2f\n",SensorData->Tempearature[count],SensorData->Soc[count]);
	}
}

/*
 **********************************************************************************************************************
 * Service name         : Send_SensorData
 * Syntax               : OpeartionStatus_en Send_SensorData(int DataSize,DataStructure *SensorData)
 * param[in]            : DataSize    (total data size)
 * param[in]            : SensorData (pointer to the data holding structure)
 * return               : DATA_SENDING_FAILED, DATA_SENDING_OK
 * Description          : Function to generate and send Temperature , SOC values to the console 
  
 Note :-Please set the maximum possible data size in BMS_DataSender.h,default value is 100
 **********************************************************************************************************************
 */
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

