/*
 * hc_sr04.h
 *
 *  Created on: Mar 22, 2021
 *      Author: piotr
 */

#ifndef INC_HC_SR04_H_
#define INC_HC_SR04_H_

typedef uint32_t TIM_Channel;

struct us_sensor_str
{
	TIM_HandleTypeDef *htim_echo;
	TIM_HandleTypeDef *htim_trig;
	TIM_Channel trig_channel;

	volatile uint32_t distance_cm;
};

void hc_sr04_init(struct us_sensor_str *us_sensor, TIM_HandleTypeDef *htim_echo, TIM_HandleTypeDef *htim_trig, TIM_Channel channel);
uint32_t hc_sr04_convert_us_to_cm(uint32_t distance_us);

#endif /* INC_HC_SR04_H_ */
