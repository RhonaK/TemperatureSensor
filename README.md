This code reads the temperature from DS18B20 sensor using 1-Wire interface.
Before running this code you first should configure your RPi. Use these steps:

> sudo nano /boot/config.txt

and add these lines at the end of the file
> dtoverlay=w1-gpio-pullup,gpiopin=4

then 
> sudo reboot
> sudo modprobe w1_gpio
> sudo modprobe w1_therm

## To compile this code use:
> make all

## To clean this code use:
> make clean


## To run this code use:
> ./TempTest


### Please update the address according to your sensor and device.
To find the address follow these steps:

> cd /sys/bus/w1/devices
> ls

and you will see something similar to: 
> 28-XXXXXXXXXXXX 
that is your address.
 < 
### This code will show the current temperature in the terminal, also will collect data as it runs. Data are saved in:
> TemperaureData.txt

### To plot the data you can use the python code:
> python3 plotData.py

### Rona Kosumi

