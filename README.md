![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# HTU21D Click

---

- **CIC Prefix**  : HTU21D
- **Author**      : Nenad Filipovic
- **Verison**     : 1.0.0
- **Date**        : Sep 2018.

---

### Software Support

We provide a library for the HTU21D Click on our [LibStock](https://libstock.mikroe.com/projects/view/1133/htu21d-click-example) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library covers all the necessary functions to control HTU21D Click board. 
Library performs the communication with the device via I2C driver by writting to registers and by reading from registers.
Library have generic write and read function, soft reset function, get temperature and humidity data from register. 
Function who gets temperature and humidity also converts temperature data to degree Celsius [ °C ] and humidity value to percentage [ % ]
from the HTU21D Click sensor.

Key functions :

- ``` void htu21d_writeData( uint8_t address, uint8_t writeCommand ) ``` - Generic write 8-bit data function
- ``` float htu21d_getTemperature() ``` - Read temperature value function
- ``` float htu21d_getHumidity() ``` - Read humidity value function

**Examples Description**

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


```.c

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

```



The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1133/htu21d-click-example) page.

Other mikroE Libraries used in the example:

- I2C
- UART
- Conversions

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
---
