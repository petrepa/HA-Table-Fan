# Smart/MQTT Table Fan

## Why
For a period it was suddenly extremely warm outside, and therefore warm inside my apartment. I figured that buying a table fan would be the cheapest solution to cool me down, but I could not have a normal table fan. It had to be smart, or able to become smart, with the help of automations. Using [Home Assistant](https://github.com/petrepa/Home-AssistantConfig) to controll this, but you can use this with any MQTT service you would like to automate it.
![Home Assistant UI](https://github.com/petrepa/MQTT-Table-Fan/blob/master/mqtt_fan_photos/HA.png)

## Build
Built this using:
* [Table Fan](https://www.clasohlson.com/no/Bordvifte/36-6575)
  * The cheapest table fan I could find (149 NOK at the time), which had to speed settings
* [NodeMCU](http://www.nodemcu.com/index_en.html) V3
* [Relays](https://www.gearbest.com/5v-relay-_gear/)
* Phone Charger
  * Regular phone charger I took apart. Took away the USB ports and soldered the 5V directly on the NodeMCU.
![components](https://github.com/petrepa/MQTT-Table-Fan/blob/master/mqtt_fan_photos/components.jpg)

### Build process
This is the buttons I had to replace with the relays:
![buttons](https://github.com/petrepa/MQTT-Table-Fan/blob/master/mqtt_fan_photos/buttons.jpg)

How I planned the components placement in the fan:
![layout](https://github.com/petrepa/MQTT-Table-Fan/blob/master/mqtt_fan_photos/component_layout.jpg)

Where I drilled hole to fasten the relays:
![relayholder](https://github.com/petrepa/MQTT-Table-Fan/blob/master/mqtt_fan_photos/relayholder.jpg)

Everything ended up fitting within the fan and closed up perfectly.
![closed](https://github.com/petrepa/MQTT-Table-Fan/blob/master/mqtt_fan_photos/closed.jpg)

Finished product:
![Assembled](https://github.com/petrepa/MQTT-Table-Fan/blob/master/mqtt_fan_photos/assembled.jpg)

I plan to later on make a cover for the holes where the buttons used to be, just to make the product a bit more polished. Maybe find a proper way to mount the fan in the roof or something too.

## Code
Wrote the code super quick, so there is definetly room for improvements, and I highly encourage you make some! 
But if you want to use what I wrote, you can check it our [here](https://github.com/petrepa/Dooropener/blob/master/dooropener.ino)!
