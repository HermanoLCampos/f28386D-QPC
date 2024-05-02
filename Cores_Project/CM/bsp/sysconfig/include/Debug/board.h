/*
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef BOARD_H
#define BOARD_H

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif

//
// Included Files
//

#include "driverlib.h"
#include "device.h"

//*****************************************************************************
//
// PinMux Configurations
//
//*****************************************************************************

//
// CANA -> CAN1 Pinmux
//
//
// CANA_RX - GPIO Settings
//
#define GPIO_PIN_CANA_RX 62
#define CAN1_CANRX_GPIO 62
#define CAN1_CANRX_PIN_CONFIG GPIO_62_CANA_RX
//
// CANA_TX - GPIO Settings
//
#define GPIO_PIN_CANA_TX 63
#define CAN1_CANTX_GPIO 63
#define CAN1_CANTX_PIN_CONFIG GPIO_63_CANA_TX

//
// CANB -> CAN2 Pinmux
//
//
// CANB_RX - GPIO Settings
//
#define GPIO_PIN_CANB_RX 39
#define CAN2_CANRX_GPIO 39
#define CAN2_CANRX_PIN_CONFIG GPIO_39_CANB_RX
//
// CANB_TX - GPIO Settings
//
#define GPIO_PIN_CANB_TX 38
#define CAN2_CANTX_GPIO 38
#define CAN2_CANTX_PIN_CONFIG GPIO_38_CANB_TX

//
// EPWM4 -> GD_HB_1 Pinmux
//
//
// EPWM4A - GPIO Settings
//
#define GPIO_PIN_EPWM4A 6
#define GD_HB_1_EPWMA_GPIO 6
#define GD_HB_1_EPWMA_PIN_CONFIG GPIO_6_EPWM4A
//
// EPWM4B - GPIO Settings
//
#define GPIO_PIN_EPWM4B 7
#define GD_HB_1_EPWMB_GPIO 7
#define GD_HB_1_EPWMB_PIN_CONFIG GPIO_7_EPWM4B

//
// EPWM3 -> GD_HB_2 Pinmux
//
//
// EPWM3A - GPIO Settings
//
#define GPIO_PIN_EPWM3A 4
#define GD_HB_2_EPWMA_GPIO 4
#define GD_HB_2_EPWMA_PIN_CONFIG GPIO_4_EPWM3A
//
// EPWM3B - GPIO Settings
//
#define GPIO_PIN_EPWM3B 5
#define GD_HB_2_EPWMB_GPIO 5
#define GD_HB_2_EPWMB_PIN_CONFIG GPIO_5_EPWM3B

//
// EPWM12 -> FO_HB_1 Pinmux
//

//
// EPWM8 -> FO_HB_2 Pinmux
//
//
// GPIO9 - GPIO Settings
//
#define LED1_GPIO_PIN_CONFIG GPIO_9_GPIO9
//
// GPIO8 - GPIO Settings
//
#define LED2_GPIO_PIN_CONFIG GPIO_8_GPIO8
//
// GPIO99 - GPIO Settings
//
#define LED3_GPIO_PIN_CONFIG GPIO_99_GPIO99
//
// GPIO21 - GPIO Settings
//
#define LED4_GPIO_PIN_CONFIG GPIO_21_GPIO21
//
// GPIO35 - GPIO Settings
//
#define RTD_CSA_GPIO_PIN_CONFIG GPIO_35_GPIO35
//
// GPIO48 - GPIO Settings
//
#define RTD_CSB_GPIO_PIN_CONFIG GPIO_48_GPIO48
//
// GPIO30 - GPIO Settings
//
#define RTD_MUX_A0_GPIO_PIN_CONFIG GPIO_30_GPIO30
//
// GPIO28 - GPIO Settings
//
#define RTD_MUX_A1_GPIO_PIN_CONFIG GPIO_28_GPIO28
//
// GPIO29 - GPIO Settings
//
#define RTD_MUX_B0_GPIO_PIN_CONFIG GPIO_29_GPIO29
//
// GPIO31 - GPIO Settings
//
#define RTD_MUX_B1_GPIO_PIN_CONFIG GPIO_31_GPIO31
//
// GPIO40 - GPIO Settings
//
#define RTD_DRDYA_GPIO_PIN_CONFIG GPIO_40_GPIO40
//
// GPIO41 - GPIO Settings
//
#define RTD_DRDYB_GPIO_PIN_CONFIG GPIO_41_GPIO41
//
// GPIO89 - GPIO Settings
//
#define GD_EN1_GPIO_PIN_CONFIG GPIO_89_GPIO89
//
// GPIO88 - GPIO Settings
//
#define GD_EN2_GPIO_PIN_CONFIG GPIO_88_GPIO88
//
// GPIO17 - GPIO Settings
//
#define ERROR_OUT1_GPIO_PIN_CONFIG GPIO_17_GPIO17
//
// GPIO27 - GPIO Settings
//
#define ERROR_OUT2_GPIO_PIN_CONFIG GPIO_27_GPIO27
//
// GPIO43 - GPIO Settings
//
#define HALT1_GPIO_PIN_CONFIG GPIO_43_GPIO43
//
// GPIO67 - GPIO Settings
//
#define HALT2_GPIO_PIN_CONFIG GPIO_67_GPIO67
//
// GPIO47 - GPIO Settings
//
#define HALT1_N_GPIO_PIN_CONFIG GPIO_47_GPIO47
//
// GPIO42 - GPIO Settings
//
#define HALT2_N_GPIO_PIN_CONFIG GPIO_42_GPIO42
//
// GPIO46 - GPIO Settings
//
#define STOP1_GPIO_PIN_CONFIG GPIO_46_GPIO46
//
// GPIO133 - GPIO Settings
//
#define STOP2_GPIO_PIN_CONFIG GPIO_133_GPIO133
//
// GPIO53 - GPIO Settings
//
#define HSD1_GPIO_PIN_CONFIG GPIO_53_GPIO53
//
// GPIO52 - GPIO Settings
//
#define HSD2_GPIO_PIN_CONFIG GPIO_52_GPIO52
//
// GPIO51 - GPIO Settings
//
#define HSD3_GPIO_PIN_CONFIG GPIO_51_GPIO51
//
// GPIO49 - GPIO Settings
//
#define HSD4_GPIO_PIN_CONFIG GPIO_49_GPIO49
//
// GPIO54 - GPIO Settings
//
#define HSD_ST_1_2_GPIO_PIN_CONFIG GPIO_54_GPIO54
//
// GPIO50 - GPIO Settings
//
#define HSD_ST_3_4_GPIO_PIN_CONFIG GPIO_50_GPIO50
//
// GPIO74 - GPIO Settings
//
#define CARD_DETECT_GPIO_PIN_CONFIG GPIO_74_GPIO74
//
// GPIO45 - GPIO Settings
//
#define S_CAN1_GPIO_PIN_CONFIG GPIO_45_GPIO45
//
// GPIO44 - GPIO Settings
//
#define S_CAN2_GPIO_PIN_CONFIG GPIO_44_GPIO44
//
// GPIO66 - GPIO Settings
//
#define S_CAN3_GPIO_PIN_CONFIG GPIO_66_GPIO66
//
// GPIO2 - GPIO Settings
//
#define RTC_INT_GPIO_PIN_CONFIG GPIO_2_GPIO2
//
// GPIO55 - GPIO Settings
//
#define SBC_INTB_GPIO_PIN_CONFIG GPIO_55_GPIO55
//
// GPIO64 - GPIO Settings
//
#define SBC_FS0B_GPIO_PIN_CONFIG GPIO_64_GPIO64
//
// GPIO65 - GPIO Settings
//
#define SBC_FS1B_GPIO_PIN_CONFIG GPIO_65_GPIO65
//
// GPIO57 - GPIO Settings
//
#define SBC_FCCU0_GPIO_PIN_CONFIG GPIO_57_GPIO57
//
// GPIO56 - GPIO Settings
//
#define SBC_FCCU1_GPIO_PIN_CONFIG GPIO_56_GPIO56

//
// I2CA -> I2C_RTC Pinmux
//
//
// I2CA_SDA - GPIO Settings
//
#define GPIO_PIN_I2CA_SDA 0
#define I2C_RTC_I2CSDA_GPIO 0
#define I2C_RTC_I2CSDA_PIN_CONFIG GPIO_0_I2CA_SDA
//
// I2CA_SCL - GPIO Settings
//
#define GPIO_PIN_I2CA_SCL 1
#define I2C_RTC_I2CSCL_GPIO 1
#define I2C_RTC_I2CSCL_PIN_CONFIG GPIO_1_I2CA_SCL

//
// SPIA -> RTD_SPI Pinmux
//
//
// SPIA_PICO - GPIO Settings
//
#define GPIO_PIN_SPIA_PICO 32
#define RTD_SPI_SPIPICO_GPIO 32
#define RTD_SPI_SPIPICO_PIN_CONFIG GPIO_32_SPIA_SIMO
//
// SPIA_POCI - GPIO Settings
//
#define GPIO_PIN_SPIA_POCI 33
#define RTD_SPI_SPIPOCI_GPIO 33
#define RTD_SPI_SPIPOCI_PIN_CONFIG GPIO_33_SPIA_SOMI
//
// SPIA_CLK - GPIO Settings
//
#define GPIO_PIN_SPIA_CLK 34
#define RTD_SPI_SPICLK_GPIO 34
#define RTD_SPI_SPICLK_PIN_CONFIG GPIO_34_SPIA_CLK

//
// SPIB -> SBC_SPI Pinmux
//
//
// SPIB_PICO - GPIO Settings
//
#define GPIO_PIN_SPIB_PICO 60
#define SBC_SPI_SPIPICO_GPIO 60
#define SBC_SPI_SPIPICO_PIN_CONFIG GPIO_60_SPIB_SIMO
//
// SPIB_POCI - GPIO Settings
//
#define GPIO_PIN_SPIB_POCI 61
#define SBC_SPI_SPIPOCI_GPIO 61
#define SBC_SPI_SPIPOCI_PIN_CONFIG GPIO_61_SPIB_SOMI
//
// SPIB_CLK - GPIO Settings
//
#define GPIO_PIN_SPIB_CLK 58
#define SBC_SPI_SPICLK_GPIO 58
#define SBC_SPI_SPICLK_PIN_CONFIG GPIO_58_SPIB_CLK
//
// SPIB_PTE - GPIO Settings
//
#define GPIO_PIN_SPIB_PTE 59
#define SBC_SPI_SPIPTE_GPIO 59
#define SBC_SPI_SPIPTE_PIN_CONFIG GPIO_59_SPIB_STEN

//
// SPIC -> SD_SPI Pinmux
//
//
// SPIC_PICO - GPIO Settings
//
#define GPIO_PIN_SPIC_PICO 69
#define SD_SPI_SPIPICO_GPIO 69
#define SD_SPI_SPIPICO_PIN_CONFIG GPIO_69_SPIC_SIMO
//
// SPIC_POCI - GPIO Settings
//
#define GPIO_PIN_SPIC_POCI 70
#define SD_SPI_SPIPOCI_GPIO 70
#define SD_SPI_SPIPOCI_PIN_CONFIG GPIO_70_SPIC_SOMI
//
// SPIC_CLK - GPIO Settings
//
#define GPIO_PIN_SPIC_CLK 71
#define SD_SPI_SPICLK_GPIO 71
#define SD_SPI_SPICLK_PIN_CONFIG GPIO_71_SPIC_CLK

//*****************************************************************************
//
// ADC Configurations
//
//*****************************************************************************
#define myADCA_BASE ADCA_BASE
#define myADCA_RESULT_BASE ADCARESULT_BASE
#define myADCA_SOC0 ADC_SOC_NUMBER0
#define myADCA_FORCE_SOC0 ADC_FORCE_SOC0
#define myADCA_SAMPLE_WINDOW_SOC0 480
#define myADCA_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM4_SOCA
#define myADCA_CHANNEL_SOC0 ADC_CH_ADCIN2_ADCIN3
#define myADCA_SOC1 ADC_SOC_NUMBER1
#define myADCA_FORCE_SOC1 ADC_FORCE_SOC1
#define myADCA_SAMPLE_WINDOW_SOC1 480
#define myADCA_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM4_SOCA
#define myADCA_CHANNEL_SOC1 ADC_CH_ADCIN4_ADCIN5
void myADCA_init();

#define myADCB_BASE ADCB_BASE
#define myADCB_RESULT_BASE ADCBRESULT_BASE
#define myADCB_SOC0 ADC_SOC_NUMBER0
#define myADCB_FORCE_SOC0 ADC_FORCE_SOC0
#define myADCB_SAMPLE_WINDOW_SOC0 480
#define myADCB_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM4_SOCA
#define myADCB_CHANNEL_SOC0 ADC_CH_ADCIN3
#define myADCB_SOC1 ADC_SOC_NUMBER1
#define myADCB_FORCE_SOC1 ADC_FORCE_SOC1
#define myADCB_SAMPLE_WINDOW_SOC1 480
#define myADCB_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM4_SOCA
#define myADCB_CHANNEL_SOC1 ADC_CH_ADCIN8
#define myADCB_SOC2 ADC_SOC_NUMBER2
#define myADCB_FORCE_SOC2 ADC_FORCE_SOC2
#define myADCB_SAMPLE_WINDOW_SOC2 480
#define myADCB_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_EPWM4_SOCA
#define myADCB_CHANNEL_SOC2 ADC_CH_ADCIN2
#define myADCB_SOC3 ADC_SOC_NUMBER3
#define myADCB_FORCE_SOC3 ADC_FORCE_SOC3
#define myADCB_SAMPLE_WINDOW_SOC3 480
#define myADCB_TRIGGER_SOURCE_SOC3 ADC_TRIGGER_EPWM4_SOCA
#define myADCB_CHANNEL_SOC3 ADC_CH_ADCIN9
void myADCB_init();

#define myADCC_BASE ADCC_BASE
#define myADCC_RESULT_BASE ADCCRESULT_BASE
#define myADCC_SOC0 ADC_SOC_NUMBER0
#define myADCC_FORCE_SOC0 ADC_FORCE_SOC0
#define myADCC_SAMPLE_WINDOW_SOC0 480
#define myADCC_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM4_SOCA
#define myADCC_CHANNEL_SOC0 ADC_CH_ADCIN2_ADCIN3
#define myADCC_SOC1 ADC_SOC_NUMBER1
#define myADCC_FORCE_SOC1 ADC_FORCE_SOC1
#define myADCC_SAMPLE_WINDOW_SOC1 480
#define myADCC_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM4_SOCA
#define myADCC_CHANNEL_SOC1 ADC_CH_ADCIN4_ADCIN5
void myADCC_init();

#define myADCD_BASE ADCD_BASE
#define myADCD_RESULT_BASE ADCDRESULT_BASE
#define myADCD_SOC0 ADC_SOC_NUMBER0
#define myADCD_FORCE_SOC0 ADC_FORCE_SOC0
#define myADCD_SAMPLE_WINDOW_SOC0 480
#define myADCD_TRIGGER_SOURCE_SOC0 ADC_TRIGGER_EPWM4_SOCA
#define myADCD_CHANNEL_SOC0 ADC_CH_ADCIN1
#define myADCD_SOC1 ADC_SOC_NUMBER1
#define myADCD_FORCE_SOC1 ADC_FORCE_SOC1
#define myADCD_SAMPLE_WINDOW_SOC1 480
#define myADCD_TRIGGER_SOURCE_SOC1 ADC_TRIGGER_EPWM4_SOCA
#define myADCD_CHANNEL_SOC1 ADC_CH_ADCIN8
#define myADCD_SOC2 ADC_SOC_NUMBER2
#define myADCD_FORCE_SOC2 ADC_FORCE_SOC2
#define myADCD_SAMPLE_WINDOW_SOC2 480
#define myADCD_TRIGGER_SOURCE_SOC2 ADC_TRIGGER_EPWM4_SOCA
#define myADCD_CHANNEL_SOC2 ADC_CH_ADCIN0
#define myADCD_SOC3 ADC_SOC_NUMBER3
#define myADCD_FORCE_SOC3 ADC_FORCE_SOC3
#define myADCD_SAMPLE_WINDOW_SOC3 480
#define myADCD_TRIGGER_SOURCE_SOC3 ADC_TRIGGER_EPWM4_SOCA
#define myADCD_CHANNEL_SOC3 ADC_CH_ADCIN9
#define myADCD_SOC4 ADC_SOC_NUMBER4
#define myADCD_FORCE_SOC4 ADC_FORCE_SOC4
#define myADCD_SAMPLE_WINDOW_SOC4 480
#define myADCD_TRIGGER_SOURCE_SOC4 ADC_TRIGGER_EPWM4_SOCA
#define myADCD_CHANNEL_SOC4 ADC_CH_ADCIN2
#define myADCD_SOC5 ADC_SOC_NUMBER5
#define myADCD_FORCE_SOC5 ADC_FORCE_SOC5
#define myADCD_SAMPLE_WINDOW_SOC5 480
#define myADCD_TRIGGER_SOURCE_SOC5 ADC_TRIGGER_EPWM4_SOCA
#define myADCD_CHANNEL_SOC5 ADC_CH_ADCIN9
void myADCD_init();


//*****************************************************************************
//
// ASYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// CAN Configurations
//
//*****************************************************************************
#define CAN1_BASE CANA_BASE

#define CAN1_MessageObj1_ID 1580
#define CAN1_MessageObj2_ID 1452
#define CAN1_MessageObj3_ID 1581
#define CAN1_MessageObj4_ID 1453
#define CAN1_MessageObj5_ID 1836
#define CAN1_MessageObj6_ID 1837
void CAN1_init();

#define CAN2_BASE CANB_BASE

#define CAN2_MessageObj1_ID 660
#define CAN2_MessageObj2_ID 661
#define CAN2_MessageObj3_ID 662
#define CAN2_MessageObj4_ID 663
#define CAN2_MessageObj5_ID 664
#define CAN2_MessageObj6_ID 665
#define CAN2_MessageObj7_ID 666
#define CAN2_MessageObj8_ID 667
#define CAN2_MessageObj9_ID 668
#define CAN2_MessageObj10_ID 669
#define CAN2_MessageObj11_ID 670
#define CAN2_MessageObj12_ID 671
#define CAN2_MessageObj13_ID 672
#define CAN2_MessageObj14_ID 673
#define CAN2_MessageObj15_ID 674
#define CAN2_MessageObj16_ID 675
void CAN2_init();


//*****************************************************************************
//
// CLA Configurations
//
//*****************************************************************************
#define myCLA0_BASE CLA1_BASE

//
// The following are symbols defined in the CLA assembly code
// Including them in the shared header file makes them global
// and the main CPU can make use of them.
//
__attribute__((interrupt)) void Cla1Task1();
__attribute__((interrupt)) void Cla1Task2();
__attribute__((interrupt)) void Cla1Task3();
__attribute__((interrupt)) void Cla1Task4();
__attribute__((interrupt)) void Cla1Task5();
__attribute__((interrupt)) void Cla1Task6();
__attribute__((interrupt)) void Cla1Task7();
__attribute__((interrupt)) void Cla1Task8();
void myCLA0_init();


//*****************************************************************************
//
// CPUTIMER Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// EPWM Configurations
//
//*****************************************************************************
#define GD_HB_1_BASE EPWM4_BASE
#define GD_HB_1_TBPRD 25000
#define GD_HB_1_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define GD_HB_1_TBPHS 0
#define GD_HB_1_CMPA 1000
#define GD_HB_1_CMPB 1000
#define GD_HB_1_CMPC 0
#define GD_HB_1_CMPD 0
#define GD_HB_1_DBRED 800
#define GD_HB_1_DBFED 800
#define GD_HB_1_TZA_ACTION EPWM_TZ_ACTION_HIGH
#define GD_HB_1_TZB_ACTION EPWM_TZ_ACTION_LOW
#define GD_HB_1_OSHT_SOURCES EPWM_TZ_SIGNAL_OSHT1
#define GD_HB_1_TZ_INTERRUPT_SOURCES EPWM_TZ_INTERRUPT_OST
#define GD_HB_1_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define GD_HB_2_BASE EPWM3_BASE
#define GD_HB_2_TBPRD 2500
#define GD_HB_2_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define GD_HB_2_TBPHS 0
#define GD_HB_2_CMPA 1000
#define GD_HB_2_CMPB 1000
#define GD_HB_2_CMPC 0
#define GD_HB_2_CMPD 0
#define GD_HB_2_DBRED 560
#define GD_HB_2_DBFED 520
#define GD_HB_2_TZA_ACTION EPWM_TZ_ACTION_LOW
#define GD_HB_2_TZB_ACTION EPWM_TZ_ACTION_HIGH
#define GD_HB_2_OSHT_SOURCES EPWM_TZ_SIGNAL_OSHT1
#define GD_HB_2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED
#define FO_HB_1_BASE EPWM12_BASE
#define FO_HB_1_TBPRD 25000
#define FO_HB_1_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define FO_HB_1_TBPHS 0
#define FO_HB_1_CMPA 1000
#define FO_HB_1_CMPB 1000
#define FO_HB_1_CMPC 0
#define FO_HB_1_CMPD 0
#define FO_HB_1_DBRED 560
#define FO_HB_1_DBFED 520
#define FO_HB_1_TZA_ACTION EPWM_TZ_ACTION_LOW
#define FO_HB_1_TZB_ACTION EPWM_TZ_ACTION_HIGH
#define FO_HB_1_INTERRUPT_SOURCE EPWM_INT_TBCTR_PERIOD
#define FO_HB_2_BASE EPWM8_BASE
#define FO_HB_2_TBPRD 25000
#define FO_HB_2_COUNTER_MODE EPWM_COUNTER_MODE_UP_DOWN
#define FO_HB_2_TBPHS 0
#define FO_HB_2_CMPA 1000
#define FO_HB_2_CMPB 1000
#define FO_HB_2_CMPC 0
#define FO_HB_2_CMPD 0
#define FO_HB_2_DBRED 560
#define FO_HB_2_DBFED 520
#define FO_HB_2_TZA_ACTION EPWM_TZ_ACTION_LOW
#define FO_HB_2_TZB_ACTION EPWM_TZ_ACTION_HIGH
#define FO_HB_2_OSHT_SOURCES EPWM_TZ_SIGNAL_OSHT1
#define FO_HB_2_INTERRUPT_SOURCE EPWM_INT_TBCTR_DISABLED

//*****************************************************************************
//
// GPIO Configurations
//
//*****************************************************************************
#define LED1 9
void LED1_init();
#define LED2 8
void LED2_init();
#define LED3 99
void LED3_init();
#define LED4 21
void LED4_init();
#define RTD_CSA 35
void RTD_CSA_init();
#define RTD_CSB 48
void RTD_CSB_init();
#define RTD_MUX_A0 30
void RTD_MUX_A0_init();
#define RTD_MUX_A1 28
void RTD_MUX_A1_init();
#define RTD_MUX_B0 29
void RTD_MUX_B0_init();
#define RTD_MUX_B1 31
void RTD_MUX_B1_init();
#define RTD_DRDYA 40
void RTD_DRDYA_init();
#define RTD_DRDYB 41
void RTD_DRDYB_init();
#define GD_EN1 89
void GD_EN1_init();
#define GD_EN2 88
void GD_EN2_init();
#define ERROR_OUT1 17
void ERROR_OUT1_init();
#define ERROR_OUT2 27
void ERROR_OUT2_init();
#define HALT1 43
void HALT1_init();
#define HALT2 67
void HALT2_init();
#define HALT1_N 47
void HALT1_N_init();
#define HALT2_N 42
void HALT2_N_init();
#define STOP1 46
void STOP1_init();
#define STOP2 133
void STOP2_init();
#define HSD1 53
void HSD1_init();
#define HSD2 52
void HSD2_init();
#define HSD3 51
void HSD3_init();
#define HSD4 49
void HSD4_init();
#define HSD_ST_1_2 54
void HSD_ST_1_2_init();
#define HSD_ST_3_4 50
void HSD_ST_3_4_init();
#define CARD_DETECT 74
void CARD_DETECT_init();
#define S_CAN1 45
void S_CAN1_init();
#define S_CAN2 44
void S_CAN2_init();
#define S_CAN3 66
void S_CAN3_init();
#define RTC_INT 2
void RTC_INT_init();
#define SBC_INTB 55
void SBC_INTB_init();
#define SBC_FS0B 64
void SBC_FS0B_init();
#define SBC_FS1B 65
void SBC_FS1B_init();
#define SBC_FCCU0 57
void SBC_FCCU0_init();
#define SBC_FCCU1 56
void SBC_FCCU1_init();

//*****************************************************************************
//
// I2C Configurations
//
//*****************************************************************************
#define I2C_RTC_BASE I2CA_BASE
#define I2C_RTC_BITRATE 400000
#define I2C_RTC_TARGET_ADDRESS 81
#define I2C_RTC_OWN_ADDRESS 0
#define I2C_RTC_MODULE_CLOCK_FREQUENCY 10000000
void I2C_RTC_init();

//*****************************************************************************
//
// INTERRUPT Configurations
//
//*****************************************************************************

// Interrupt Settings for INT_myCLA01
#define INT_myCLA01 INT_CLA1_1
#define INT_myCLA01_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr1(void);

// Interrupt Settings for INT_myCLA02
#define INT_myCLA02 INT_CLA1_2
#define INT_myCLA02_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr2(void);

// Interrupt Settings for INT_myCLA03
#define INT_myCLA03 INT_CLA1_3
#define INT_myCLA03_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr3(void);

// Interrupt Settings for INT_myCLA04
#define INT_myCLA04 INT_CLA1_4
#define INT_myCLA04_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr4(void);

// Interrupt Settings for INT_myCLA05
#define INT_myCLA05 INT_CLA1_5
#define INT_myCLA05_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr5(void);

// Interrupt Settings for INT_myCLA06
#define INT_myCLA06 INT_CLA1_6
#define INT_myCLA06_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr6(void);

// Interrupt Settings for INT_myCLA07
#define INT_myCLA07 INT_CLA1_7
#define INT_myCLA07_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr7(void);

// Interrupt Settings for INT_myCLA08
#define INT_myCLA08 INT_CLA1_8
#define INT_myCLA08_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP11
extern __interrupt void cla1Isr8(void);

// Interrupt Settings for INT_timer2
#define INT_timer2 INT_TIMER2
extern __interrupt void portTICK_ISR(void);

// Interrupt Settings for INT_myADCA_1
#define INT_myADCA_1 INT_ADCA1
#define INT_myADCA_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myADCA_1_ISR(void);

// Interrupt Settings for INT_myADCB_1
#define INT_myADCB_1 INT_ADCB1
#define INT_myADCB_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myADCB_1_ISR(void);

// Interrupt Settings for INT_myADCC_1
#define INT_myADCC_1 INT_ADCC1
#define INT_myADCC_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myADCC_1_ISR(void);

// Interrupt Settings for INT_myADCD_1
#define INT_myADCD_1 INT_ADCD1
#define INT_myADCD_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP1
extern __interrupt void INT_myADCD_1_ISR(void);

// Interrupt Settings for INT_CAN1_0
#define INT_CAN1_0 INT_CANA0
#define INT_CAN1_0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_CAN1_0_ISR(void);

// Interrupt Settings for INT_CAN1_1
#define INT_CAN1_1 INT_CANA1
#define INT_CAN1_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_CAN1_1_ISR(void);

// Interrupt Settings for INT_CAN2_0
#define INT_CAN2_0 INT_CANB0
#define INT_CAN2_0_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_CAN2_0_ISR(void);

// Interrupt Settings for INT_CAN2_1
#define INT_CAN2_1 INT_CANB1
#define INT_CAN2_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP9
extern __interrupt void INT_CAN2_1_ISR(void);

// Interrupt Settings for INT_GD_HB_1
#define INT_GD_HB_1 INT_EPWM4
#define INT_GD_HB_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP3
extern __interrupt void INT_GD_HB_1_ISR(void);

// Interrupt Settings for INT_GD_HB_2
#define INT_GD_HB_2 INT_EPWM3
#define INT_GD_HB_2_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP3
extern __interrupt void INT_GD_HB_2_ISR(void);

// Interrupt Settings for INT_FO_HB_1
#define INT_FO_HB_1 INT_EPWM12
#define INT_FO_HB_1_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP3
extern __interrupt void INT_FO_HB_1_ISR(void);

// Interrupt Settings for INT_FO_HB_2
#define INT_FO_HB_2 INT_EPWM8
#define INT_FO_HB_2_INTERRUPT_ACK_GROUP INTERRUPT_ACK_GROUP3
extern __interrupt void INT_FO_HB_2_ISR(void);

//*****************************************************************************
//
// IPC Configurations
//
//*****************************************************************************
#define IPC_SYNC IPC_FLAG31
#define IPC_SYNC IPC_FLAG31
#define BOOT_MODE_CPU2 BOOTMODE_BOOT_TO_FLASH_SECTOR0

//*****************************************************************************
//
// MEMCFG Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SPI Configurations
//
//*****************************************************************************
#define RTD_SPI_BASE SPIA_BASE
#define RTD_SPI_BITRATE 1000000
#define RTD_SPI_DATAWIDTH 16
void RTD_SPI_init();
#define SBC_SPI_BASE SPIB_BASE
#define SBC_SPI_BITRATE 1000000
#define SBC_SPI_DATAWIDTH 16
void SBC_SPI_init();
#define SD_SPI_BASE SPIC_BASE
#define SD_SPI_BITRATE 1000000
#define SD_SPI_DATAWIDTH 16
void SD_SPI_init();

//*****************************************************************************
//
// SYNC Scheme Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// SYSCTL Configurations
//
//*****************************************************************************

//*****************************************************************************
//
// Board Configurations
//
//*****************************************************************************
void	Board_init();
void	ADC_init();
void	ASYSCTL_init();
void	CAN_init();
void	CLA_init();
void	CPUTIMER_init();
void	EPWM_init();
void	GPIO_init();
void	I2C_init();
void	INTERRUPT_init();
void	IPC_SYSCFG_init();
void	MEMCFG_init();
void	SPI_init();
void	SYNC_init();
void	SYSCTL_init();
void	PinMux_init();

//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif  // end of BOARD_H definition
