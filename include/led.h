#ifndef LED_H_
#define LED_H_

#include <Arduino.h>

class Led {
	private:
		int _pin;
		bool _inverted, _blink_enabled;
		unsigned long _timer_blink, _time_on, _time_off, _time_current;
	public:
		Led(int pin, bool inverted = false);
		void set(void);
		void reset(void);
		void toggle(void);
		void startBlink(unsigned long time_on, unsigned long time_off);
		void stopBlink(void);
		void loop(void);
};

#endif  /* LED_H_ */