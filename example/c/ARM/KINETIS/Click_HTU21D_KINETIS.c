/*
Example for HTU21D Click

    Date          : Sep 2018.
    Author        : Nenad Filipovic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes I2C and LOG structures.
- Application Initialization - Initialization driver enable's - I2C,
     soft reset switch OFF and ON the HTU21D sensor,
     hold ( required ) after reset 100 [ ms ] and start write log.
- Application Task - (code snippet) This is a example which demonstrates the use of HTU21D Click board.
     Measured temperature and humidity data from the HDC1000 sensor.
     Convert temperature data to degrees Celsius [ ºC ] and
     humidity data to percentarg [ % ].
     Results are being sent to the Usart Terminal where you can track their changes.
     All data logs on usb uart for aproximetly every 3 sec.

Additional Functions :

- UART
- Conversions

*/

#include "Click_HTU21D_types.h"
#include "Click_HTU21D_config.h"


float temperature;
float humidity;
char logText[50];

void systemInit()
{
    mikrobus_i2cInit( _MIKROBUS1, &_HTU21D_I2C_CFG[0] );
    mikrobus_logInit( _MIKROBUS2, 9600 );
    Delay_100ms();
}

void applicationInit()
{
    htu21d_i2cDriverInit( (T_HTU21D_P)&_MIKROBUS1_GPIO, (T_HTU21D_P)&_MIKROBUS1_I2C, _HTU21D_I2C_ADDRESS );

    // Reset sensor
    htu21d_softReset();
    Delay_100ms();

    mikrobus_logWrite( "---------------------------", _LOG_LINE );
    mikrobus_logWrite( "           HTU21D          ", _LOG_LINE );
    mikrobus_logWrite( "---------------------------", _LOG_LINE );
}

void applicationTask()
{
    temperature = htu21d_getTemperature();

    humidity = htu21d_getHumidity();

    mikrobus_logWrite( " Temperature : ", _LOG_TEXT );
    FloatToStr( temperature, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( " °C", _LOG_LINE );

    mikrobus_logWrite( " Humidity    : ", _LOG_TEXT );
    FloatToStr( humidity, logText );
    mikrobus_logWrite( logText, _LOG_TEXT );
    mikrobus_logWrite( " %", _LOG_LINE );

    mikrobus_logWrite( "---------------------------", _LOG_LINE );

    Delay_1sec();
    Delay_1sec();
    Delay_1sec();
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}