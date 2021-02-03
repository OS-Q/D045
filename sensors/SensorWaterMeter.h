
#ifndef SensorWaterMeter_h
#define SensorWaterMeter_h

/*
	SensorWaterMeter
*/

#include "SensorPulseMeter.h"

class SensorWaterMeter: public SensorPulseMeter {
public:
	SensorWaterMeter(int8_t pin, uint8_t child_id = 0): SensorPulseMeter(pin, child_id) {
		_name = "WATER";
		children.get()->setFormat(DOUBLE);
		children.get()->setPresentation(S_WATER);
		children.get()->setType(V_VOLUME);
		children.get()->setDescription(_name);
		setPulseFactor(1000);
	};

	// what to do when receiving an interrupt
	void onInterrupt() {
		// increment the accumulated value
		children.get()->setValue(1 / _pulse_factor);
	};

	// what to do as the main task when receiving a message
	void onReceive(MyMessage* message) {
		Child* child = getChild(message->sensor);
		if (child == nullptr) return;
		if (message->getCommand() == C_REQ && message->type == child->getType()) {
			// send the accumulated value so far
			children.get()->sendValue();
		}
	};
};
#endif
