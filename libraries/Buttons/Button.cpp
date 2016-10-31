/*
	Button - a small library for Arduino to handle button debouncing
	
	MIT licensed.
*/

#include "Button.h"
#include <Arduino.h>

Button::Button(uint8_t pin)
{
	_pin = pin;
	_ignore_until = 0;
	_has_changed = false;
	_delay = 500;
}

Button::Button(uint8_t pin, uint32_t delay) : Button(pin)
{
	_delay = delay;
}

void Button::begin(uint8_t mode)
{
	pinMode(_pin, mode);
	if(mode == INPUT_PULLUP)
	{
		_state = HIGH;
		_pressed = LOW;
		_released = HIGH;
	}
	if(mode == INPUT)
	{
		_state = LOW;
		_pressed = HIGH;
		_released = LOW;
	}
}

// 
// public methods
// 

bool Button::read()
{
	// ignore pin changes until after this delay time
	if (_ignore_until > millis())
	{
		// ignore any changes during this period
	}
	
	// pin has changed 
	else if (digitalRead(_pin) != _state)
	{
		_ignore_until = millis() + _delay;
		_state = !_state;
		_has_changed = true;
	}
	
	return _state;
}

// has the button been toggled from on -> off, or vice versa
bool Button::toggled()
{
	read();
	return has_changed();
}

// mostly internal, tells you if a button has changed after calling the read() function
bool Button::has_changed()
{
	if (_has_changed == true)
	{
		_has_changed = false;
		return true;
	}
	return false;
}

// has the button gone from off -> on
bool Button::pressed()
{
	return (read() == _pressed && has_changed() == true) ? true : false;
}

// has the button gone from on -> off
bool Button::released()
{
	return (read() == _released && has_changed() == true) ? true : false;
}

bool Button::isPressed()
{
	return (read() == _pressed) ? true : false; 
}
