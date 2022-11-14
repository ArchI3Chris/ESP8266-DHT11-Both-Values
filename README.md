# DHT11 - Temperature and Humidity from DHT11
=============================================


## Origin

This is the Arduino IDE code for the ESP8266 (ESP-12E) to request both, temperature and humidity from the DHT11 sensor. As before the ESP8266 connects to a wireless network and outputs a website (and the values on a separate route). The code is based on the code offered by Bastelbruder with his YouTube Video https://www.youtube.com/embed/23_G6gQVxog:

<iframe width="100%" src="https://www.youtube.com/embed/23_G6gQVxog" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>


## Modifications

In the comments to the video a solution to use the humidity value has been requested. The modification is in the code. The code has been modified to output both values on the route /werte in form of JSON instead of temperature only in plain text on /TempWeb. Also, some improvements have been made to several parts of the Website (HTML, CSS and use of fetch instead of XHR request).


## Notes

This is not final and perfect. This was intended to be an exercise for beginners and still is. This just shows some potential improvements and an extension of the original code.
