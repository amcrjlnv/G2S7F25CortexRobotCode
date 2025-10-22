#pragma config(Sensor, dgtl1,  touch1,         sensorTouch)
#pragma config(Motor,  port1,           motor1,        tmotorVex393_HBridge, openLoop)

task main()
{
	clearTimer(T1);
	motor[port1] = 127;
	int lastdir = 127;
	int lasttouch = 0;

	while (true) {
		if (lasttouch == 0 && SensorValue[touch1] == 1) { // Button pressed?
				motor[port1] = 0;
		}
		if (lasttouch == 1 && SensorValue[touch1] == 0) { // Button unpressed?
				lastdir = -lastdir;
				motor[port1] = lastdir * 127;
		}
		lasttouch = SensorValue[touch1];
		delay(1);
	}
}
