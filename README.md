# DHT11 - Temperature and Humidity from DHT11


## Origin

This is the Arduino IDE code for the ESP8266 (ESP-12E) to request both, temperature and humidity from the DHT11 sensor. As before the ESP8266 connects to a wireless network and outputs a website (and the values on a separate route). The code is based on the code offered by Bastelbruder with his YouTube Video https://www.youtube.com/watch?v=23_G6gQVxog:

<a href="https://www.youtube.com/watch?v=23_G6gQVxog" target="_blank"><img src="https://img.youtube.com/vi/23_G6gQVxog/0.jpg" style="width: 100%"></a>


## Modifications

In the comments to the video a solution to use the humidity value has been requested. The modification is in the code. The code has been modified to output both values on the route /werte (values) in form of JSON instead of temperature only in plain text on /TempWeb. Also, some improvements have been made to several parts of the Website (HTML, CSS and use of fetch instead of XHR request).


## Notes

This is not final and perfect. This was intended to be an exercise for beginners and still is. This just shows some potential improvements and an extension of the original code.


## Use

The DHT11 in my case has 4 pins. Looking at it from the front (grid side) with pins at the bottom, left to right the pins are power input, data, non-connected and ground. I've obviously connected ground to the G pin on my ESP-12E (USB connect at the bottom, right-hand side second from the bottom), the D1 pin for the data connection (right-hand side, second from top).

The power input for the DHT11 is a bit tricky. There have been discussions about the correct voltage. Also, some ESP boards don't seem to provide the 5V direct output (VV or so on my ESP-12E, left-hand side, third from top). I've found two different specs statements. One says, the input voltage should be 3-5V and the other says, 3.3 to 5.5V. First potentially being vague and second being more accurate? Also, if it says 3.3V, you probably get like 3.28V or so? I've got 2 different types of boards. One has the 5V ouput, the other doesn't. So, I went with 5V. If you don't have it, there is a good chance it works with 3.3V too. Maybe check the values in case you are not sure.

Don't forget to replace SSID and password with the access data of your own wireless network in the code. Once you've uploaded, you'll find the IP address for the website in the serial monitor output in your Arduino IDE.
