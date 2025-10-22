#pragma config(Motor,  port1,           motor1,        tmotorVex393_HBridge, openLoop)

task main()
{
	clearTimer(T1);
	motor[port1] = 0;
	int direction = 1;
	int power = 0;
	while (true) { // Would change direction ever 2.5-3s
		power += direction;
		if (sgn(power) * power == 127) direction = -direction;
		motor[port1] = power;
		delay(10);
	}
}
