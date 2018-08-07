#include <Servo.h>

//Joystick pins
int analog_x = A0;
int analog_y = A1;

//Horizontal + vertical values
int x;
int y;

//Servos
Servo serv1;
Servo serv2;

//Start position
int serv1_pos=90;
int serv2_pos=90;

void setup ( )
{
	Serial.begin (4800);

	pinMode (analog_x, INPUT);
	pinMode (analog_y, INPUT);

	serv1.write (serv1_pos);
	serv2.write (serv2_pos);

	//Attach servo 1/2 to pins 6/7
	serv1.attach (6);
	serv2.attach (7);
}

void loop ( )
{
	x = analogRead (analog_x);
	y = analogRead (analog_y);
	
	int mvspd = 20; //Servo movespeed

	//Joystick rest = +- 512
	//adjust delay to inc/dec servo speed

	if (x < 400 && serv1_pos > 10)
	{
		serv1_pos = serv1_pos - mvspd;
		serv1.write ( serv1_pos );
		delay (50);
	}
	
	if (x > 600 && serv1_pos < 180)
	{	
		serv1_pos = serv1_pos + mvspd;
		serv1.write (serv1_pos);
		delay (50);
	}

	if (y < 400 && serv2_pos > 10)
	{
	    serv2_pos = serv2_pos - mvspd;
	    serv2.write (serv2_pos);
	    delay (50);
	}

	if (y > 600 && serv2_pos < 180)
	{
	    serv2_pos = serv2_pos + mvspd;
	    serv2.write(serv2_pos);
	    delay (50);
	}
}
