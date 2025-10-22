#pragma config(Motor,  port1,           motor1,        tmotorVex393_HBridge, openLoop)

task main()
{
	motor[motor1] = 0;
	int direction = 1;
	int power = 0;
	while (true) { // Would change direction every 2.5-3s
		power += direction;
		if (sgn(power) * power == 127) direction = -direction;
		motor[motor1] = power;
		delay(10);
	}
}
