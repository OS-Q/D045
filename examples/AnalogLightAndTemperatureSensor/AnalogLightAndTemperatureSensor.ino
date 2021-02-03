
// General settings
#define SKETCH_NAME "LightTemperatureSensor"
#define SKETCH_VERSION "1.0"
#define MY_BAUD_RATE 9600
#define MY_NODE_ID 99

// NRF24 radio settings
#define MY_RADIO_NRF24

/***********************************
* NodeManager configuration
*/

#define NODEMANAGER_SLEEP ON
#define NODEMANAGER_OTA_CONFIGURATION ON

// import NodeManager library (a nodeManager object will be then made available)
#include <MySensors_NodeManager.h>

/***********************************
* Add your sensors
*/

// Add a battery sensor
#include <sensors/SensorBattery.h>
SensorBattery battery;

// Add a LDR sensor
#include <sensors/SensorLDR.h>
SensorLDR ldr(A1);

// Add a thermistor sensor
#include <sensors/SensorThermistor.h>
SensorThermistor thermistor(A0);

/***********************************
* Main Sketch
*/

// before
void before() {

/***********************************
* Configure your sensors
*/

	// set reporting interval for all the sensors to 10 minutes
	nodeManager.setReportIntervalMinutes(10);
	// set sleep interval to 10 minutes
	nodeManager.setSleepMinutes(10);

	// call NodeManager before routine
	nodeManager.before();
}

// presentation
void presentation() {
	// call NodeManager presentation routine
	nodeManager.presentation();
}

// setup
void setup() {
	// call NodeManager setup routine
	nodeManager.setup();
}

// loop
void loop() {
	// call NodeManager loop routine
	nodeManager.loop();
}

#if NODEMANAGER_RECEIVE == ON
// receive
void receive(const MyMessage &message) {
	// call NodeManager receive routine
	nodeManager.receive(message);
}
#endif

#if NODEMANAGER_TIME == ON
// receiveTime
void receiveTime(unsigned long ts) {
	// call NodeManager receiveTime routine
	nodeManager.receiveTime(ts);
}
#endif
