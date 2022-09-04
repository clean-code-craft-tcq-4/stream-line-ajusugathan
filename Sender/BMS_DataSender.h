
#define REQ_TEMPEARTURE_RANGE    100
#define REQ_SOC_RANGE            100
#define MAX_VALUE                100


typedef enum{
	DATA_GENERATION_FAILED=0,
	DATA_SENDING_FAILED,
	DATA_SENDING_OK,
	DATA_GENERATION_OK
}OpeartionStatus_en;

typedef struct{
	float Tempearature[MAX_VALUE];
	float Soc[MAX_VALUE];
}DataStructure;


OpeartionStatus_en Generate_SensorData(int DataSize,DataStructure *SensorData);
void PrintData(int DataSize,DataStructure *SensorData);
OpeartionStatus_en Send_SensorData(int DataSize,DataStructure *SensorData);
