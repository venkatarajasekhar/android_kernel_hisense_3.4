/*
 * arch/arm/mach-tegra/board-enterprise.h
 *
 * Copyright (c) 2012, NVIDIA Corporation.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef _MACH_TEGRA_BOARD_ENTERPRISE_H
#define _MACH_TEGRA_BOARD_ENTERPRISE_H

#include <mach/gpio.h>
#include <mach/irqs.h>
#include <linux/mfd/tps80031.h>

/* Processor Board  ID */
#define BOARD_E1205		0x0C05
#define BOARD_E1197		0x0B61
#define BOARD_E1239		0x0C27
#define SKU_BATTERY_SUPPORT	0x1

/* Board Fab version */
#define BOARD_FAB_A00		0x0
#define BOARD_FAB_A01		0x1
#define BOARD_FAB_A02		0x2
#define BOARD_FAB_A03		0x3
#define BOARD_FAB_A04		0x4

/* vdd_cpu voltage follower */
#define BOARD_SKU_VF_BIT	0x0400

int enterprise_charge_init(void);
int enterprise_sdhci_init(void);
int enterprise_pinmux_init(void);
int enterprise_panel_init(void);
int enterprise_sensors_init(void);
int touch_init(void);
int enterprise_kbc_init(void);
int enterprise_emc_init(void);
int enterprise_regulator_init(void);
int enterprise_modem_init(void);
int enterprise_suspend_init(void);
int enterprise_edp_init(void);
void enterprise_bpc_mgmt_init(void);

/* Invensense MPU Definitions */
#define MPU_GYRO_NAME		"mpu3050"
#define MPU_GYRO_NAME_TAI	"mpu9150"
#define MPU_GYRO_IRQ_GPIO	TEGRA_GPIO_PH4
#define MPU_GYRO_IRQ_GPIO_TAI	TEGRA_GPIO_PI6
#define MPU_GYRO_ADDR		0x68
#define MPU_GYRO_BUS_NUM	0
#define MPU_GYRO_BUS_NUM_TAI	0
#define MPU_GYRO_ORIENTATION	{ -1, 0, 0, 0, -1, 0, 0, 0, 1 }
#define MPU_ACCEL_NAME		"kxtf9"
#define MPU_ACCEL_IRQ_GPIO	0 /* DISABLE ACCELIRQ:  TEGRA_GPIO_PJ2 */
#define MPU_ACCEL_ADDR		0x0F
#define MPU_ACCEL_BUS_NUM	0
#define MPU_ACCEL_ORIENTATION	{ 0, 1, 0, -1, 0, 0, 0, 0, 1 }
#define MPU_COMPASS_NAME	"ak8975"
#define MPU_COMPASS_IRQ_GPIO	0
#define MPU_COMPASS_ADDR	0x0C
#define MPU_COMPASS_BUS_NUM	0
#define MPU_COMPASS_ORIENTATION	{ 0, 1, 0, -1, 0, 0, 0, 0, 1 }

/* PCA954x I2C bus expander bus addresses */
#define PCA954x_I2C_BUS_BASE	6
#define PCA954x_I2C_BUS0	(PCA954x_I2C_BUS_BASE + 0)
#define PCA954x_I2C_BUS1	(PCA954x_I2C_BUS_BASE + 1)
#define PCA954x_I2C_BUS2	(PCA954x_I2C_BUS_BASE + 2)
#define PCA954x_I2C_BUS3	(PCA954x_I2C_BUS_BASE + 3)

/*****************External GPIO tables ******************/
/* External peripheral gpio base. */
#define ENT_TPS80031_GPIO_BASE	   TEGRA_NR_GPIOS
#define ENT_TPS80031_GPIO_REGEN1 (ENT_TPS80031_GPIO_BASE + TPS80031_GPIO_REGEN1)
#define ENT_TPS80031_GPIO_REGEN2 (ENT_TPS80031_GPIO_BASE + TPS80031_GPIO_REGEN2)
#define ENT_TPS80031_GPIO_SYSEN	 (ENT_TPS80031_GPIO_BASE + TPS80031_GPIO_SYSEN)
#define ENT_TPS80031_GPIO_END	(ENT_TPS80031_GPIO_BASE + TPS80031_GPIO_NR)

/*****************External Interrupt tables ******************/
/* External peripheral irq base */
#define ENT_TPS80031_IRQ_BASE	TEGRA_NR_IRQS
#define ENT_TPS80031_IRQ_END  (ENT_TPS80031_IRQ_BASE + TPS80031_INT_NR)

/* AIC3256 IRQs */
/* Assuming TPS is the PMIC on Ent */
#define AIC3256_CODEC_IRQ_BASE ENT_TPS80031_IRQ_END
#define AIC3256_CODEC_IRQ_END  (AIC3256_CODEC_IRQ_BASE + 6)

/*****************Camera GPIOs ******************/
#define CAM_CSI_MUX_SEL_GPIO	TEGRA_GPIO_PM3
#define CAM_CSI_MUX_SEL_REAR	1
#define CAM_CSI_MUX_SEL_FRONT	0

#define CAM1_RST_L_GPIO		TEGRA_GPIO_PM5 /*REAR RIGHT*/
#define CAM2_RST_L_GPIO		TEGRA_GPIO_PF4 /*REAR LEFT*/
#define CAM3_RST_L_GPIO		TEGRA_GPIO_PM2 /*FRONT*/
#define CAM3_RST_L_TRUE		0
#define CAM3_RST_L_FALSE	1
#define CAM3_PWDN_GPIO		TEGRA_GPIO_PN4 /*FRONT*/
#define CAM3_PWDN_TRUE		1
#define CAM3_PWDN_FALSE		0
#define CAM_FLASH_EN_GPIO	TEGRA_GPIO_PBB3
#define CAM_FLASH_MAX_TORCH_AMP	7
#define CAM_FLASH_MAX_FLASH_AMP	7
#define CAM_I2C_MUX_RST_EXP	TEGRA_GPIO_PF3 /*I2C Mux Reset*/

/* Audio-related GPIOs */
#define TEGRA_GPIO_HP_DET	TEGRA_GPIO_PW3
#define TEGRA_GPIO_CODEC_RST	TEGRA_GPIO_PX0

/* UART port which is used by bluetooth*/
#define BLUETOOTH_UART_DEV_NAME "/dev/ttyHS2"
/* Baseband GPIO addresses */

#define GPIO_BB_RESET		TEGRA_GPIO_PE1
#define GPIO_BB_PWRON		TEGRA_GPIO_PE0
#define GPIO_BB_APACK		TEGRA_GPIO_PE3
#define GPIO_BB_APACK2		TEGRA_GPIO_PE2
#define GPIO_BB_CPACK		TEGRA_GPIO_PU5
#define GPIO_BB_CPACK2		TEGRA_GPIO_PV0
#define GPIO_BB_RSVD1		TEGRA_GPIO_PV1
#define GPIO_BB_RSVD2		TEGRA_GPIO_PU4

#define BB_GPIO_MDM_PWRON_AP2BB		TEGRA_GPIO_PE0 /* LCD_D0 */
#define BB_GPIO_RESET_AP2BB		TEGRA_GPIO_PE1 /* LCD_D1 */
#define BB_GPIO_LCD_PWR1		TEGRA_GPIO_PC1
#define BB_GPIO_LCD_PWR2		TEGRA_GPIO_PC6
#define BB_GPIO_HS1_AP2BB		TEGRA_GPIO_PE3 /* LCD_D3 */
#define BB_GPIO_HS1_BB2AP		TEGRA_GPIO_PU5

#define XMM_GPIO_BB_ON			BB_GPIO_MDM_PWRON_AP2BB
#define XMM_GPIO_BB_RST			BB_GPIO_RESET_AP2BB
#define XMM_GPIO_IPC_HSIC_ACTIVE	BB_GPIO_LCD_PWR1
#define XMM_GPIO_IPC_HSIC_SUS_REQ	BB_GPIO_LCD_PWR2
#define XMM_GPIO_IPC_BB_WAKE		BB_GPIO_HS1_AP2BB
#define XMM_GPIO_IPC_AP_WAKE		BB_GPIO_HS1_BB2AP

/* Battery Peak Current Management */
#define TEGRA_BPC_TRIGGER		TEGRA_GPIO_PR3
#define TEGRA_BPC_TIMEOUT		100 /* ms */
#define TEGRA_BPC_CPU_PWR_LIMIT	0 /* in mW, (0 disables) */

#define TEGRA_CUR_MON_THRESHOLD		-2000
#define TEGRA_CUR_MON_RESISTOR		20
#define TEGRA_CUR_MON_MIN_CORES		2

/* Baseband IDs */

enum tegra_bb_type {
	TEGRA_BB_PH450 = 1,
	TEGRA_BB_XMM6260,
	TEGRA_BB_M7400,
};

/* Indicate the pwm of backlight, DC pwm or external pwm3. */
/* External pwm is used for TAI (E1239) but do not set this compiler switch */
#define IS_EXTERNAL_PWM		1

//M470 GPIO Start
#define TEGRA_GPIO_M470_HP_DET			 TEGRA_GPIO_PO5
#define TEGRA_GPIO_M470_KEY_DET		   	 TEGRA_GPIO_PO4
#define TEGRA_GPIO_CDC_IRQ_N    TEGRA_GPIO_PW3
#define TEGRA_GPIO_CAM_AVDD_PWR_EN         TEGRA_GPIO_PV1
#define TEGRA_GPIO_CAM_PWR_EN   TEGRA_GPIO_PX1
#define TEGRA_GPIO_EN_CODEC_PA  TEGRA_GPIO_PX0
#define TEGRA_GPIO_GYRO_IRQ_N   TEGRA_GPIO_PX2
#define TEGRA_GPIO_EN_VDD_SDMMC1    TEGRA_GPIO_PP1
#define TEGRA_GPIO_EN_VDDIO_VID_OC_N    TEGRA_GPIO_PP2
#define TEGRA_GPIO_GPS_PWN                      TEGRA_GPIO_PP0
#define TEGRA_GPIO_NFC_PWN                      TEGRA_GPIO_PP3
#define TEGRA_GPIO_AP_ONKEY_N                   TEGRA_GPIO_PV0
//#define TEGRA_GPIO_CAM_AF_PWDN_N            TEGRA_GPIO_PBB3
#define TEGRA_GPIO_CAM_AF_EN            TEGRA_GPIO_PBB3



#define TEGRA_GPIO_REAR_CAM_PWDN            TEGRA_GPIO_PBB5
#define TEGRA_GPIO_FRONT_CAM_RST            TEGRA_GPIO_PBB6
#define TEGRA_GPIO_FRONT_CAM_PWDN       TEGRA_GPIO_PBB7
//#define TEGRA_GPIO_CAM_RST_N                    TEGRA_GPIO_PCC1
#define TEGRA_GPIO_REAR_CAM_RST_N                    TEGRA_GPIO_PCC1


#define TEGRA_GPIO_BL_PWM			TEGRA_GPIO_PH0
#define TEGRA_GPIO_LCD_BL_EN                    TEGRA_GPIO_PH2
#define TEGRA_GPIO_EN_VDD_BL                      TEGRA_GPIO_PH3
#define TEGRA_GPIO_EN_VDD_FUSE                  TEGRA_GPIO_PH4
#define TEGRA_GPIO_EN_LCD_1V8                       TEGRA_GPIO_PH5
#define TEGRA_GPIO_TP_LP0                                TEGRA_GPIO_PH6
#define TEGRA_GPIO_PMU_CHRG_DET             TEGRA_GPIO_PI6
#define TEGRA_GPIO_SDMMC_CD_N               TEGRA_GPIO_PI5
#define TEGRA_GPIO_HDMI_HPD                     TEGRA_GPIO_PN7
#define TEGRA_GPIO_COMPASS_RST_N                TEGRA_GPIO_PN4
#define TEGRA_GPIO_COMPASS_DRDY                 TEGRA_GPIO_PW0
#define TEGRA_GPIO_LVDS_SHTDN_N                 TEGRA_GPIO_PN6
#define TEGRA_GPIO_BT_REG_ON                        TEGRA_GPIO_PD2
#define TEGRA_GPIO_EN_VDD_PNL                       TEGRA_GPIO_PW1
#define TEGRA_GPIO_RST_CDC                              TEGRA_GPIO_PB2
#define TEGRA_GPIO_PMU_MSECURE                  TEGRA_GPIO_PC1
#define TEGRA_GPIO_EN_LCD_3V3                       TEGRA_GPIO_PC6
#define TEGRA_GPIO_ALS_IRQ_N                            TEGRA_GPIO_PZ2                   
#define TEGRA_GPIO_TS_RESET_N                           TEGRA_GPIO_PN5
#define TEGRA_GPIO_TS_IRQ_N                                 TEGRA_GPIO_PZ3
#define TEGRA_GPIO_WLAN_RST_N                       TEGRA_GPIO_PD3
#define TEGRA_GPIO_BT_RST_N                             TEGRA_GPIO_PD4
#define TEGRA_GPIO_VOL_UP                               TEGRA_GPIO_PQ1
#define TEGRA_GPIO_VOL_DOWN                         TEGRA_GPIO_PQ2
#define TEGRA_GPIO_GPS_RST_N                            TEGRA_GPIO_PQ7
#define TEGRA_GPIO_TEMP_ALERT_N                     TEGRA_GPIO_PS6
#define TEGRA_GPIO_NFC_WAKE                             TEGRA_GPIO_PS7
//#define TEGRA_GPIO_CAM_FLASH                            TEGRA_GPIO_PR2
#define TEGRA_GPIO_CAM_FLASH_EN                            TEGRA_GPIO_PR2



//#define TEGRA_GPIO_CAM_TORCH                        TEGRA_GPIO_PR3
#define TEGRA_GPIO_CAM_TORCH_EN                        TEGRA_GPIO_PR3

#define TEGRA_GPIO_WLAN_HOST_WAKE               TEGRA_GPIO_PS0
#define TEGRA_GPIO_BATREMOVAL                           TEGRA_GPIO_PS1
#define TEGRA_GPIO_NRESWARM                             TEGRA_GPIO_PU0
#define TEGRA_GPIO_HOST_BT_WAKE                         TEGRA_GPIO_PU1
#define TEGRA_GPIO_NFC_IRQ                                      TEGRA_GPIO_PU5
#define TEGRA_GPIO_BT_HOST_WAKE                         TEGRA_GPIO_PU6
#define TEGRA_GPIO_FACTORY_LED                  TEGRA_GPIO_PU3
//M470 GPIO End

#endif /*_MACH_TEGRA_BOARD_ENTERPRISE_H */
