/*
 * hc_sr04.c
 *
 *  Created on: Mar 22, 2021
 *      Author: piotr
 */

#include "main.h"

#define HC_SR04_US_TO_CM_CONVERTER	58

void hc_sr04_init(struct us_sensor_str *us_sensor, TIM_HandleTypeDef *htim)
{
	us_sensor->htim = htim;

	HAL_TIM_IC_Start_IT(us_sensor->htim, TIM_CHANNEL_1 | TIM_CHANNEL_2);
}

void hc_sr04_set_trigger(struct us_sensor_str *us_sensor)
{
	HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, SET);
	hc_sr_04_wait_us(us_sensor, 10);
	HAL_GPIO_WritePin(TRIG_GPIO_Port, TRIG_Pin, RESET);
}

uint32_t hc_sr04_convert_us_to_cm(uint32_t distance_us)
{
	return (distance_us / HC_SR04_US_TO_CM_CONVERTER);
}

void hc_sr_04_wait_us(struct us_sensor_str *us_sensor, uint32_t usec)
{
	uint32_t tim_cnt = 0;

	tim_cnt = __HAL_TIM_GET_COUNTER(us_sensor->htim);

	while((__HAL_TIM_GET_COUNTER(us_sensor->htim) - tim_cnt) < usec)
	  ;
}
