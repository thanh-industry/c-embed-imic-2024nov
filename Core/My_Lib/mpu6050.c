/*
 * mpu6050.c
 *
 *  Created on: Feb 9, 2025
 *      Author: Huy
 */

#include "mpu6050.h"


static uint8_t buff[14] = {0};
I2C_HandleTypeDef *imu_hi2c;
float ax,ay,az;
float gx, gy, gz;
float acc_offet_x, acc_offet_y, acc_offet_z;
float yAngle = 0;
double accY = 0;
uint16_t acc_x = 0;
int16_t gryo_x_raw, gryo_y_raw, gryo_z_raw;
int16_t accel_x_raw, accel_y_raw, accel_z_raw;
float temp;


void mpu_write(uint16_t MemAdress, uint8_t data){
	HAL_I2C_Mem_Write(imu_hi2c, MPU_ADDR, MemAdress, 1, &data, 1, 100);
}

void mpu_reset(){
	mpu_write(MPU_PWR_MGMT_1, MPU_PWR_MGMT_1_DEVICE_RESET);
	HAL_Delay(100);
	mpu_write(MPU_SIGNAL_PATH_RESET, MPU_SIGNAL_PATH_RESET_ALL);
	HAL_Delay(100);
	mpu_write(MPU_PWR_MGMT_1, 0x00);
}


void mpu_init(I2C_HandleTypeDef *i2c){
	// check connect imu
	imu_hi2c = i2c;
	if(MPU_IS_CONNECT(imu_hi2c, MPU_ADDR) != HAL_OK){
		uint8_t cnt = 50;
		while(cnt--){
			HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_13);
			HAL_Delay(20);
		}
	}

	// reset mpu
	mpu_reset();

	//mpu_write(MPU_CONFIG, MPU_BAND_44HZ);
	// Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV)
	// 50Hz = 1KHz / (1 + SMPLRT_DIV)
	mpu_write(MPU_SMPLRT_DIV, 0x07); // SMPLRT_DIV = 19

	// Set Gyroscopic configuration in GYRO_CONFIG Register
	mpu_write(MPU_GYRO_CONFIG, 0x00);

  // Set accelerometer configuration in ACCEL_CONFIG Register
	// XA_ST=0,YA_ST=0,ZA_ST=0, FS_SEL=0 -> 2g
	mpu_write(MPU_ACCEL_CONFIG, 0x00);
	HAL_Delay(100);
}


void imu_calib_accel(uint8_t num){
	float sum_acc_x = 0, sum_acc_y = 0, sum_acc_z = 0;
	for(uint8_t i = 0; i < num; i++){
		imu_read_raw_accel();
		sum_acc_x += ax;
		sum_acc_y += ay;
		sum_acc_z += az;
		HAL_Delay(1);
	}
	acc_offet_x = (float)sum_acc_x / num;
	acc_offet_y = (float)sum_acc_y / num;
	acc_offet_z = (float)sum_acc_z / num;
}


void imu_read_raw_accel(){
	uint8_t data_accel[6] = {0};
	HAL_I2C_Mem_Read(imu_hi2c, MPU_ADDR, ACCEL_XOUT_H, 1, data_accel, MPU_ACCEL_AXIS, 100);

	// combine data high and low to form 16 bit accelerometer data for x, y, z axis
	accel_x_raw = (int16_t)(data_accel[0] << 8) | data_accel[1];
	accel_y_raw = (int16_t)(data_accel[2] << 8) | data_accel[3];
	accel_z_raw = (int16_t)(data_accel[4] << 8) | data_accel[5];

	// convert data into proper �g� format
	ax = (accel_x_raw / MPU_ACCEL_2_G);
	ay = (accel_y_raw / MPU_ACCEL_2_G);
	az = (accel_z_raw / MPU_ACCEL_2_G);
}


void mpu_read_gyro(){
	uint8_t data_gyro[6] = {0};
	HAL_I2C_Mem_Read(imu_hi2c, MPU_ADDR, GYRO_XOUT_H, 1, data_gyro, MPU_GYRO_AXIS, 100);
	gryo_x_raw = (int16_t)(data_gyro[0] << 8) | data_gyro[1];
	gryo_y_raw = (int16_t)(data_gyro[2] << 8) | data_gyro[3];
	gryo_z_raw = (int16_t)(data_gyro[4] << 8) | data_gyro[5];

	gx = gryo_x_raw / MPU_GYRO_250_DEG;
	gy = gryo_y_raw / MPU_GYRO_250_DEG;
	gz = gryo_z_raw / MPU_GYRO_250_DEG;
}


void mpu_read_temp(){
	uint8_t data_temp[2] = {0};
	HAL_I2C_Mem_Read(imu_hi2c, MPU_ADDR, TEMP_OUT_H, 1, data_temp, 2, 100);

	uint16_t data = (data_temp[0] << 8) | data_temp[1];
	temp = data / 340.0 + 36.53;
}


void mpu_read_accel(){
	uint8_t data_accel[6] = {0};
	HAL_I2C_Mem_Read(imu_hi2c, MPU_ADDR, ACCEL_XOUT_H, 1, data_accel, MPU_ACCEL_AXIS, 100);

	// combine data high and low to form 16 bit accelerometer data for x, y, z axis
	accel_x_raw = (int16_t)(data_accel[0] << 8) | data_accel[1];
	accel_y_raw = (int16_t)(data_accel[2] << 8) | data_accel[3];
	accel_z_raw = (int16_t)(data_accel[4] << 8) | data_accel[5];

	// convert data into proper g format
	ax = (accel_x_raw / MPU_ACCEL_2_G) - 0.04;
	ay = (accel_y_raw / MPU_ACCEL_2_G) + 0.01;
	az = (accel_z_raw / MPU_ACCEL_2_G) - 0.08;
}


float mpu_get_pitch(){
//	static uint32_t last_tick = 0;
//	mpu_read_gyro();
//	mpu_read_accel();
//	float duration = (HAL_GetTick() - last_tick) / 1000.0;
//	last_tick = HAL_GetTick();

//	accY = atan(-1 * (accel_x_raw / 16384.0) / sqrt(pow((accel_y_raw / 16384.0), 2) + pow((accel_z_raw / 16384.0), 2))) * RAD2DEG;
//	yAngle = 0.98 * (yAngle + gy * duration) + 0.02 * accY;
//	return yAngle;
	mpu_read_accel();
	float tmp = ax / ( ay * ay + az * az);
	return -atan(tmp);
}

float mpu_get_roll(){
	mpu_read_gyro();
	float tmp = ay / ( ay * ay + az * az);
	return atan(tmp);
}

float mpu_get_yaw(){
	static float yaw_old = 0;
	static uint32_t pre = 0;
	float yaw_angle = 0;
	float dt = (HAL_GetTick() - pre) / 1000.0;
	mpu_read_gyro();
	yaw_angle = yaw_old + gz * dt;
	pre = HAL_GetTick();
	yaw_old = yaw_angle;
	return yaw_angle;
}
