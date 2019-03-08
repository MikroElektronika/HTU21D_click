/*
    __htu21d_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__htu21d_driver.h"
#include "__htu21d_hal.c"

/* ------------------------------------------------------------------- MACROS */



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __HTU21D_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* chip i2c address */
const uint8_t _HTU21D_I2C_ADDRESS                    = 0x40;
/* write user register */
const uint8_t _HTU21D_USER_REGISTER_WRITE            = 0xE6;
/* read  user register */
const uint8_t _HTU21D_USER_REGISTER_READ             = 0xE7;
/* write heater control register */
const uint8_t _HTU21D_HEATER_REGISTER_WRITE          = 0x51;
/* read  heater control register */
const uint8_t _HTU21D_HEATER_REGISTER_READ           = 0x11;
/* soft reset */
const uint8_t _HTU21D_SOFT_RESET                     = 0xFE;
/* read 1-st two serial bytes */
const uint8_t _HTU21D_SERIAL1_READ1                  = 0xFA;
/* read 2-nd two serial bytes */
const uint8_t _HTU21D_SERIAL1_READ2                  = 0x0F;
/* read 3-rd two serial bytes */
const uint8_t _HTU21D_SERIAL2_READ1                  = 0xFC;
/* read 4-th two serial bytes */
const uint8_t _HTU21D_SERIAL2_READ2                  = 0xC9;
/* device id SI7013 */
const uint8_t _HTU21D_SI7013_CHIPID                  = 0x0D;
/* device id SI7020 */
const uint8_t _HTU21D_SI7020_CHIPID                  = 0x14;
/* device id SI7021 */
const uint8_t _HTU21D_SI7021_CHIPID                  = 0x15;
/* device id HTU21D/SHT21 */
const uint8_t _HTU21D_CHIPID                         = 0x32;
/* read firmware revision, 1-st part of the command */
const uint8_t _HTU21D_FIRMWARE_READ1                 = 0x84;
/* read firmware revision, 2-nd part of the command */
const uint8_t _HTU21D_FIRMWARE_READ2                 = 0xB8;
/* sensor firmware v1.0 */
const uint8_t _HTU21D_FIRMWARE_V1                    = 0xFF;
/* sensor firmware 2.0 */
const uint8_t _HTU21D_FIRMWARE_V2                    = 0x20;
/* force to read temperature, see */
const uint8_t _HTU21D_FORCE_READ_TEMP                = 0xFE;
/* returns 255, if CRC8 or communication error is occurred */
const uint8_t _HTU21D_ERROR                          = 0xFF;
/* resolution, temperature: 14-Bit & humidity: 12-Bit */
const uint8_t _HTU21D_RES_RH12_TEMP14                = 0x00;
/* resolution, temperature: 12-Bit & humidity: 8-Bit */
const uint8_t _HTU21D_RES_RH8_TEMP12                 = 0x01;
/* resolution, temperature: 13-Bit & humidity: 10-Bit */
const uint8_t _HTU21D_RES_RH10_TEMP13                = 0x80;
/* resolution, temperature: 11-Bit & humidity: 11-Bit */
const uint8_t _HTU21D_RES_RH11_TEMP11                = 0x81;
/* humidity measurement with hold master */
const uint8_t _HTU21D_TRIGGER_HUMD_MEASURE_HOLD      = 0xE5;
/* temperature measurement with no hold master */
const uint8_t _HTU21D_TRIGGER_HUMD_MEASURE_NOHOLD    = 0xF5;
/* temperature measurement with hold master */
const uint8_t _HTU21D_TRIGGER_TEMP_MEASURE_HOLD      = 0xE3;
/* temperature measurement with no hold master */
const uint8_t _HTU21D_TRIGGER_TEMP_MEASURE_NOHOLD    = 0xF3;
/* heater ON */
const uint8_t _HTU21D_ON                             = 0x04;
 /* heater OFF */
const uint8_t _HTU21D_OFF                            = 0xFB;

/* crc8 polynomial for 16bit value, CRC8 -> x^8 + x^5 + x^4 + 1 */
const uint16_t _HTU21D_CRC8_POLYNOMINAL              = 0x1310;


/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __HTU21D_DRV_SPI__

void htu21d_spiDriverInit(T_HTU21D_P gpioObj, T_HTU21D_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __HTU21D_DRV_I2C__

void htu21d_i2cDriverInit(T_HTU21D_P gpioObj, T_HTU21D_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif
#ifdef   __HTU21D_DRV_UART__

void htu21d_uartDriverInit(T_HTU21D_P gpioObj, T_HTU21D_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    // ... power ON
    // ... configure CHIP
}

#endif



/* ----------------------------------------------------------- IMPLEMENTATION */

/* Generic write 8-bit data function */
void htu21d_writeData( uint8_t address, uint8_t writeCommand )
{
    uint8_t buffer[ 2 ];
    buffer[ 0 ] = address;
    buffer[ 1 ] = writeCommand;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 2, END_MODE_STOP );
}

/* Generic read 24-bit data function */
uint32_t htu21d_readData( uint8_t address )
{
    uint8_t writeReg[ 1 ];
    uint8_t readReg[ 3 ];
    uint16_t result;

    writeReg[ 0 ] = address;

    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, writeReg, 1, END_MODE_RESTART );
    hal_i2cRead( _slaveAddress, readReg, 3, END_MODE_STOP );
    
    result = 0x00000000;
    result = readReg[ 0 ];
    result <<= 8;
    result |= readReg[ 1 ];
    result <<= 8;
    result |= readReg[ 2 ];

    return result;
}

/* Soft reset function */
void htu21d_softReset()
{
    uint8_t command[ 1 ];
    command[ 0 ] = _HTU21D_SOFT_RESET;
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, command, 1, END_MODE_STOP );
}

/* Get temperature value function */
float htu21d_getTemperature()
{
    uint8_t buffer[ 3 ];
    uint32_t temperature;
    float result;

    buffer[ 0 ] = _HTU21D_TRIGGER_TEMP_MEASURE_HOLD;
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 1,END_MODE_RESTART);
    hal_i2cRead( _slaveAddress, buffer, 3,END_MODE_STOP);
    
    temperature = 0x00000000;
    temperature = buffer[ 0 ];
    temperature <<= 8;
    temperature |= buffer[ 1 ];
    temperature <<= 8;
    temperature |= buffer[ 2 ];
    
    temperature >>= 8;
    
    temperature = temperature & 0xFFFC;
    
    result = ( -46.85 + ( 175.72 * temperature / 65536.0 ) );

    return result;
}

/* Get humidity value function */
float htu21d_getHumidity()
{
    uint8_t buffer[ 3 ];
    uint32_t humidity;
    float result;

    buffer[ 0 ] = _HTU21D_TRIGGER_HUMD_MEASURE_HOLD;
    hal_i2cStart();
    hal_i2cWrite( _slaveAddress, buffer, 1,END_MODE_RESTART);
    hal_i2cRead( _slaveAddress, buffer, 3,END_MODE_STOP);

    humidity = 0x00000000;
    humidity = buffer[ 0 ];
    humidity <<= 8;
    humidity |= buffer[ 1 ];
    humidity <<= 8;
    humidity |= buffer[ 2 ];

    humidity >>= 8;

    humidity = humidity & 0xFFFC;

    result = ( -6.0 + ( 125.0 * humidity / 65536.0 ) );

    return result;
}



/* -------------------------------------------------------------------------- */
/*
  __htu21d_driver.c

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