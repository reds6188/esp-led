#include "led.h"

Led::Led(int pin, bool inverted) {
	_pin = pin;
	_inverted = inverted

	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, (_inverted ? HIGH : LOW);
}

void Led::set(void) {
	digitalWrite(_pin, (_inverted ? LOW : HIGH));
}

void Led::reset(void) {
	digitalWrite(_pin, (_inverted ? HIGH : LOW));
}

void Led::toggle(void) {
	digitalWrite(_pin, !digitalRead(_pin));
}

void Led::startBlink(unsigned long time_on, unsigned long time_off) {
	_blink_enabled = true;
	_time_on = time_on;
	_time_off = time_off;
	_time_current = _time_on;
	_timer_blink = millis();
	set();
}

void Led::stopBlink(void) {
	_blink_enabled = false;
	reset();
}

void Led::loop(void) {
	if(_blink_enabled && ((millis() - _timer_blink) > _time_current)) {
		_timer_blink = millis();
		if(digitalRead(_pin) != _inverted) {	// ON state
			_time_current = _time_off;
			reset();
		}
		else {									// OFF state
			_time_current = _time_on;
			set();
		}
	}
}