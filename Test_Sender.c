#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "BMS_DataSender.h"

void TEST_CASE_01()
{
	printf("\n Test case to check if the input data buffer is invalid\n");
    assert(Send_SensorData(50,NULL)==DATA_SENDING_FAILED);
}
void TEST_CASE_02()
{
	printf("\n Test case to check if the input data length is invalid\n");
    DataStructure test_02;
    assert(Send_SensorData(0,&test_02)==DATA_GENERATION_FAILED);
}
void TEST_CASE_03()
{
	printf("\n Test case to check if both the input data length and data buffers are invalid\n");
    assert(Send_SensorData(0,NULL)==DATA_SENDING_FAILED);
}
void TEST_CASE_04()
{
	printf("\n Test case to check if both the input data length and data buffers are valid\n");
    DataStructure test_04;
    assert(Send_SensorData(20,&test_04)==DATA_SENDING_OK);
}
int main()
{
   TEST_CASE_01();
   TEST_CASE_02();
   TEST_CASE_03();
   TEST_CASE_04();
}