# DHT11 - Temperature and Humidity from DHT11
=============================================


## Origin

This is the Arduino IDE code for the ESP8266 (ESP-12E) to request both, temperature and humidity from the DHT11 sensor. As before the ESP8266 connects to a wireless network and outputs a website (and the values on a separate route). The code is based on the code offered by Bastelbruder with his YouTube Video https://www.youtube.com/watch?v=23_G6gQVxog:

<a href="https://www.youtube.com/watch?v=23_G6gQVxog" target="_blank"><img src="https://img.youtube.com/vi/23_G6gQVxog/0.jpg" style="width: 100%"></a>


## Modifications

In the comments to the video a solution to use the humidity value has been requested. The modification is in the code. The code has been modified to output both values on the route /werte in form of JSON instead of temperature only in plain text on /TempWeb. Also, some improvements have been made to several parts of the Website (HTML, CSS and use of fetch instead of XHR request).


## Notes

This is not final and perfect. This was intended to be an exercise for beginners and still is. This just shows some potential improvements and an extension of the original code.


## Use

DHT11 needs 5V input, ground and a data connection to the ESP8266. In my case on the ESP-12E the I've used the G pin for ground (USB connect at the bottom, right hand side second from the bottom), the D1 pin for the data connection (right hand, second from top) and for the 5V input the VV pin (or what ever letters those are,Left side, third from top). In my case the sensor has 4 pins. Pins at the bottom looking at it from the front (grid side), the pins are 5V input, data, not connected and ground. If there are only 3 pins, it should be the same without the non-connected. Don't forget to replace SSID and password for your own wireless network. Once you've uploaded, you'll find the IP address for the website in the serial monitor output in your Arduino IDE.

It's worth mentioning: some boards actually don't seem to provide the 5V output, that you need for the DHT11.
