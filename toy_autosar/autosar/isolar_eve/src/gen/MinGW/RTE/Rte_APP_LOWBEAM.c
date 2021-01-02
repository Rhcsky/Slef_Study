/** @file     Rte_APP_LOWBEAM.c
  * 
  * @brief    RTE Sample SWC implementation skeleton file
  * 
  * @note     Generated by ETAS GmbH  RTA-RTE v5.8.4  (R4.0 backend version: v7.8.7 (Build 46772))
  */

#include "Rte_APP_LOWBEAM.h"
#define LIGHT_RANGE 20
#define MIN_DISTANCE 150
typedef enum _LightConstVar {off, lowBeam, highBeam} LightConstVar;
/* --------------------------------------------------------------------------- */
/* RTE Event: /Components/APP_LOWBEAM/IB_APP_LOWBEAM/DRE_DISTANCE */

int count;
int lightWindow[5];
int distanceWindow[5];
int getVoltage(int light){
	int voltage = 0;
	int stepRange = 0;
	for(stepRange = 0; stepRange < 5; stepRange++){
		if (stepRange * LIGHT_RANGE <= light && (stepRange+1) * LIGHT_RANGE > light){
			voltage = stepRange + 1;
		}
	}
	return voltage;
}
void sort(){
	int i,j,min,temp;
	for(i=0;i<4;i++){
		min=lightWindow[i];
		for(j=i+1;j<5;j++){
			if(min>lightWindow[j]){
				temp=min;
				min=lightWindow[j];
				lightWindow[j]=temp;
			}
		}
	}
}

void distance_sort(){
	int i,j,min,temp;
	for(i=0;i<4;i++){
		min=distanceWindow[i];
		for(j=i+1;j<5;j++){
			if(min>distanceWindow[j]){
				temp=min;
				min=distanceWindow[j];
				distanceWindow[j]=temp;
			}
		}
	}
}
FUNC(void, APP_LOWBEAM_CODE) RE_LOWBEAM(void)
{
	int distance = 0;
	int lightMode = 0;
	int light = 0;
	int speed = 0;
	int voltage = 0;

	lightMode = Rte_DRead_R_LIGHTMODE_FROM_SENSOR_LIGHTMODE_VDP_SENSOR_TO_APP();
	speed = Rte_DRead_R_SPEED_FROM_SENSOR_SPEED_VDP_SENSOR_TO_APP();

//	status_printf("distance Value(from sensor) : %d", distance);
//	status_printf("lightMode Value(from sensor) : %d", lightMode);
//	status_printf("light Value(from sensor) : %d", light);
//	status_printf("speed Value(from sensor) : %d", speed);
	int index;
	index=0;
	int check=0;
	while(!check){
		light = Rte_DRead_R_LIGHT_FROM_SENSOR_LIGHT_VDP_SENSOR_TO_APP();
		distance = Rte_DRead_R_DISTANCE_FROM_SENSOR_DISTANCE_VDP_SENSOR_TO_APP();
		lightWindow[index]=light;
		distanceWindow[index]=distance;
		if(index==3) check=1;
		index++;
	}
	lightWindow[4] = Rte_DRead_R_LIGHT_FROM_SENSOR_LIGHT_VDP_SENSOR_TO_APP();
	distanceWindow[4] = Rte_DRead_R_DISTANCE_FROM_SENSOR_DISTANCE_VDP_SENSOR_TO_APP();
	sort();
	distance_sort();
	light=lightWindow[1];
	distance=distanceWindow[1];
	switch(lightMode){
	case off:
		voltage = 0;
		break;
	case lowBeam:
		voltage = getVoltage(light);
		break;
	case highBeam:
		if (distance < MIN_DISTANCE){
			voltage = -getVoltage(light);
		} else {
			voltage = 0;
		}
		break;
	}

	Rte_Write_P_LOWBEAMMODE_TO_ACT_LOWBEAM_VDP_APP_TO_ACT(voltage);
}
