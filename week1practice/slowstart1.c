#pragma config(Motor,  port1,           motor1,        tmotorVex393_HBridge, openLoop)

task main()
{
	clearTimer(T1);
	motor[motor1] = 0;
	while (time1[T1] < 10000) {
		motor[motor1] = time1[T1] * 127 / 10000;
		delay(1);
	}
	motor[motor1] = 127;
}
