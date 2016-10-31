/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#ifndef Button_h
#define Button_h
#include "Arduino.h"

class Button
{
	public:
		Button(uint8_t pin);
		Button(uint8_t pin, uint32_t delay);

		void begin(uint8_t mode);
		bool read();
		bool toggled();
		bool pressed();
		bool released();
		bool has_changed();
		bool isPressed();
	private:
		uint8_t  _pin;
		uint16_t _delay;
		bool     _state;
		bool     _has_changed;
		uint32_t _ignore_until;
		bool _pressed;
		bool _released;
};

#endif
