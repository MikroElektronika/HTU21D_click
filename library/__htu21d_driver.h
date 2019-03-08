/*
    __htu21d_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __htu21d_driver.h
@brief    HTU21D Driver
@mainpage HTU21D Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   HTU21D
@brief      HTU21D Click Driver
@{

| Global Library Prefix | **HTU21D** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Sep 2018.**      |
| Developer             | **Nenad Filipovic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _HTU21D_H_
#define _HTU21D_H_

/** 
 * @macro T_HTU21D_P
 * @brief Driver Abstract type 
 */
#define T_HTU21D_P    const uint8_t*

/** @defgroup HTU21D_COMPILE Compilation Config */              /** @{ */

//  #define   __HTU21D_DRV_SPI__                            /**<     @macro __HTU21D_DRV_SPI__  @brief SPI driver selector */
   #define   __HTU21D_DRV_I2C__                            /**<     @macro __HTU21D_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __HTU21D_DRV_UART__                           /**<     @macro __HTU21D_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup HTU21D_VAR Variables */                           /** @{ */

extern const uint8_t _HTU21D_I2C_ADDRESS;
extern const uint8_t _HTU21D_USER_REGISTER_WRITE;
extern const uint8_t _HTU21D_USER_REGISTER_READ;
extern const uint8_t _HTU21D_HEATER_REGISTER_WRITE;
extern const uint8_t _HTU21D_HEATER_REGISTER_READ;
extern const uint8_t _HTU21D_SOFT_RESET;
extern const uint8_t _HTU21D_SERIAL1_READ1;
extern const uint8_t _HTU21D_SERIAL1_READ2;
extern const uint8_t _HTU21D_SERIAL2_READ1;
extern const uint8_t _HTU21D_SERIAL2_READ2;
extern const uint8_t _HTU21D_SI7013_CHIPID;
extern const uint8_t _HTU21D_SI7020_CHIPID;
extern const uint8_t _HTU21D_SI7021_CHIPID;
extern const uint8_t _HTU21D_CHIPID;
extern const uint8_t _HTU21D_FIRMWARE_READ1;
extern const uint8_t _HTU21D_FIRMWARE_READ2;
extern const uint8_t _HTU21D_FIRMWARE_V1;
extern const uint8_t _HTU21D_FIRMWARE_V2;
extern const uint16_t _HTU21D_CRC8_POLYNOMINAL;
extern const uint8_t _HTU21D_FORCE_READ_TEMP;
extern const uint8_t _HTU21D_ERROR;
extern const uint8_t _HTU21D_RES_RH12_TEMP14;
extern const uint8_t _HTU21D_RES_RH8_TEMP12;
extern const uint8_t _HTU21D_RES_RH10_TEMP13;
extern const uint8_t _HTU21D_RES_RH11_TEMP11;
extern const uint8_t _HTU21D_TRIGGER_HUMD_MEASURE_HOLD;
extern const uint8_t _HTU21D_TRIGGER_HUMD_MEASURE_NOHOLD;
extern const uint8_t _HTU21D_TRIGGER_TEMP_MEASURE_HOLD;
extern const uint8_t _HTU21D_TRIGGER_TEMP_MEASURE_NOHOLD;
extern const uint8_t _HTU21D_ON;
extern const uint8_t _HTU21D_OFF;

                                                                       /** @} */
/** @defgroup HTU21D_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup HTU21D_INIT Driver Initialization */              /** @{ */

#ifdef   __HTU21D_DRV_SPI__
void htu21d_spiDriverInit(T_HTU21D_P gpioObj, T_HTU21D_P spiObj);
#endif
#ifdef   __HTU21D_DRV_I2C__
void htu21d_i2cDriverInit(T_HTU21D_P gpioObj, T_HTU21D_P i2cObj, uint8_t slave);
#endif
#ifdef   __HTU21D_DRV_UART__
void htu21d_uartDriverInit(T_HTU21D_P gpioObj, T_HTU21D_P uartObj);
#endif


/** @defgroup HTU21D_FUNC Driver Functions */                   /** @{ */


/**
 * @brief Generic write 8-bit data function
 *
 * @param[in] address         Register address
 *
 * @param[in] writeCommand    Command to write
 *
 * Function write 8-bit data to HTU21D.
 */
void htu21d_writeData( uint8_t address, uint8_t writeCommand );

/**
 * @brief Generic read 24-bit data function
 *
 * @param[in] address         Register address
 *
 * @return
 * 24-bit data from addressed register from HTU21D
 *
 * Function read 24-bit data from register address of HTU21D.
 */
uint8_t htu21d_readData( uint8_t address );

/**
 * @brief Soft reset function
 *
 * Function soft reset switch sensor OFF & ON
 * all registers & bits except heater bit will set to default.
 *
 * @note
 * takes ~ 15 ms
 * required delay to reset.
 */
void htu21d_softReset();

/**
 * @brief Get temperature value function
 *
 * @return
 * float temperature data degrees Celsius [ ºC ]
 *
 * Function read and calculate temperature
 * in degrees Celsius from the HTU21D sensor.
 */
float htu21d_getTemperature();

/**
 * @brief Get humidity value function
 *
 * @return
 * float humidity data percentage [ % ]
 *
 * Function read and calculate humidity percentage
 * from the HTU21D sensor.
 */
float htu21d_getHumidity();




                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_HTU21D_STM.c
    @example Click_HTU21D_TIVA.c
    @example Click_HTU21D_CEC.c
    @example Click_HTU21D_KINETIS.c
    @example Click_HTU21D_MSP.c
    @example Click_HTU21D_PIC.c
    @example Click_HTU21D_PIC32.c
    @example Click_HTU21D_DSPIC.c
    @example Click_HTU21D_AVR.c
    @example Click_HTU21D_FT90x.c
    @example Click_HTU21D_STM.mbas
    @example Click_HTU21D_TIVA.mbas
    @example Click_HTU21D_CEC.mbas
    @example Click_HTU21D_KINETIS.mbas
    @example Click_HTU21D_MSP.mbas
    @example Click_HTU21D_PIC.mbas
    @example Click_HTU21D_PIC32.mbas
    @example Click_HTU21D_DSPIC.mbas
    @example Click_HTU21D_AVR.mbas
    @example Click_HTU21D_FT90x.mbas
    @example Click_HTU21D_STM.mpas
    @example Click_HTU21D_TIVA.mpas
    @example Click_HTU21D_CEC.mpas
    @example Click_HTU21D_KINETIS.mpas
    @example Click_HTU21D_MSP.mpas
    @example Click_HTU21D_PIC.mpas
    @example Click_HTU21D_PIC32.mpas
    @example Click_HTU21D_DSPIC.mpas
    @example Click_HTU21D_AVR.mpas
    @example Click_HTU21D_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __htu21d_driver.h

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */