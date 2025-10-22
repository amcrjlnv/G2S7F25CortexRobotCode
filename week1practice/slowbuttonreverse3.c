#pragma config(Sensor, dgtl1,  touch1,         sensorTouch)
#pragma config(Motor,  port1,           motor1,        tmotorVex393_HBridge, openLoop)

task main()
{
	motor[motor1] = 127;
	int lastdir = 127;
	int lasttouch = 0;

	while (true) {
		if (lasttouch == 0 && SensorValue[touch1] == 1) {
				motor[motor1] = 0;
		}
		if (lasttouch == 1 && SensorValue[touch1] == 0) {
				lastdir = -lastdir;
				motor[motor1] = lastdir * 127;
		}
		lasttouch = SensorValue[touch1];
		delay(50);
	}
}
