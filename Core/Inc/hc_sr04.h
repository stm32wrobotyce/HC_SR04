/*
 * hc_sr04.h
 *
 *  Created on: Mar 22, 2021
 *      Author: piotr
 */

#ifndef INC_HC_SR04_H_
#define INC_HC_SR04_H_

struct us_sensor_str
{
	TIM_HandleTypeDef *htim;

	volatile uint32_t distance_cm;
};

void hc_sr04_init(struct us_sensor_str *us_sensor, TIM_HandleTypeDef *htim);
void hc_sr04_set_trigger(struct us_sensor_str *us_sensor);
uint32_t hc_sr04_convert_us_to_cm(uint32_t distance_us);

void hc_sr_04_wait_us(struct us_sensor_str *us_sensor, uint32_t usec);

#endif /* INC_HC_SR04_H_ */
