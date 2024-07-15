# esp-led
LED handler for ESP32
Simple control of the logic state (no PWM).

## Examples

Led1 blinking 1 second ON - 1 second OFF
```c++
#include <led.h>

Led Led1(LED_1);    // LED_1 not inverted (1 = ON ; 0 = OFF)

void setup(void) {
    Led1.startBlink(1000,1000);
}

void loop(void) {
    Led1.loop();
}
```

Led2 turned ON with low logic level
```c++
#include <led.h>

Led Led2(LED_2, true);    // LED_1 inverted (1 = OFF ; 0 = ON)

void setup(void) {
    Led2.set();
}

void loop(void) {
    delay(100);
}
```