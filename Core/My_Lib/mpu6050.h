/*
 * mpu6050.h
 *
 *  Created on: Feb 9, 2025
 *      Author: Huy
 */

#ifndef MYLIB_MPU6050_H_
#define MYLIB_MPU6050_H_

/* include libs */
#include <stdint.h>
#include <stdint.h>
#include <math.h>
#include "stm32f4xx_hal.h"

#define AD0_PIN 0

#if AD0_PIN == 0
	#define MPU_ADDR (0x68 << 1)
#else
	#define MPU_ADDR (0x69 << 1)
#endif

#define MPU_GYRO_AXIS 6
#define MPU_ACCEL_AXIS 6

#define MPU_SMPLRT_DIV (0x19)
#define MPU_CONFIG (0x1A)
#define MPU_GYRO_CONFIG (0x1B)
#define MPU_ACCEL_CONFIG (0x1C)
#define MPU_PWR_MGMT_1 (0x6B)
#define MPU_SIGNAL_PATH_RESET (0x68)
#define MPU_USER_CTRL (0x6A)

#define ACCEL_XOUT_H (0x3B)
#define GYRO_XOUT_H (0x43)
#define TEMP_OUT_H (0x41)

/* flag for signal path reset */
#define MPU_SIGNAL_PATH_RESET_TEMP (0x00)
#define MPU_SIGNAL_PATH_RESET_ACCEL (0x01)
#define MPU_SIGNAL_PATH_RESET_GYRO (0x04)
#define MPU_SIGNAL_PATH_RESET_ALL (0x07)

/* flag for user control */
#define MPU_USER_CTRL_FIFO_EN (0x40)
#define MPU_USER_CTRL_FIFO_RESET (0x04)

/* flag for Power Management 1*/
#define MPU_PWR_MGMT_1_DEVICE_RESET (0x80)
#define MPU_PWR_MGMT_1_SLEEP (0x40)
#define MPU_PWR_MGMT_1_CYCLE (0x20)
#define MPU_PWR_MGMT_1_TEMP_DIS (0x08)

/* mode for configuration register
flag external Frame Synchronization (FSYNC) pin sampling */
typedef enum{
	MPU_INPUT_DIS = 0x00,
	MPU_TEMP_OUT_L,
	MPU_GYRO_XOUT_L,
	MPU_GYRO_YOUT_L,
	MPU_GYRO_ZOUT_L,
	MPU_ACCEL_XOUT_L,
	MPU_ACCEL_YOUT_L,
	MPU_ACCEL_ZOUT_L,
}mpu_ext_sync;

/*flag for  the Digital Low Pass Filter (DLPF)*/
typedef enum{
	MPU_BAND_260HZ = 0x00,
	MPU_BAND_184HZ,
	MPU_BAND_94HZ,
	MPU_BAND_44HZ,
	MPU_BAND_21HZ,
	MPU_BAND_10HZ,
	MPU_BAND_5HZ,
}mpu_bandwitdth;

/*flag for full scale range of gyroscope*/
typedef enum{
	MPU_GYRO_250_DEG_RANGE = 0x00,
	MPU_GYRO_500_DEG_RANGE,
	MPU_GYRO_1000_DEG_RANGE,
	MPU_GYRO_2000_DEG_RANGE
}mpu_gyro_range;
#define MPU_GYRO_250_DEG (131.0)
#define MPU_GYRO_500_DEG (62.5)
#define MPU_GYRO_1000_DEG (32.8)
#define MPU_GYRO_2000_DEG (16.4)

/*flag for full scale range of accelerometer*/
typedef enum{
	MPU_ACCEL_2_G_RANGE = 0x00,
	MPU_ACCEL_4_G_RANGE,
	MPU_ACCEL_8_G_RANGE,
	MPU_ACCEL_16_G_RANGE
}mpu_accel_range;
#define MPU_ACCEL_2_G (16384.0)
#define MPU_ACCEL_4_G (8192.0)
#define MPU_ACCEL_8_G (4096.0)
#define MPU_ACCEL_16_G (2048.0)
#define MPU_IS_CONNECT(hi2c, addr) HAL_I2C_IsDeviceReady(hi2c,addr, 5, 200)
#define RAD2DEG (57.32)

void mpu_write(uint16_t MemAdress, uint8_t data);
void mpu_reset(void);
void mpu_init(I2C_HandleTypeDef *i2c);
void imu_read_raw_accel(void);
void imu_calib_accel(uint8_t num);
float mpu_get_pitch(void);
void mpu_read_gyro(void);
void mpu_read_temp(void);
void mpu_read_accel(void);
float mpu_get_roll(void);
float mpu_get_yaw(void);

#endif /* MYLIB_MPU6050_H_ */
