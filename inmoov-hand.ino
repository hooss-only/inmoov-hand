#include <Servo.h>


int THUMB_SENSOR_PIN = A0;
int INDEX_SENSOR_PIN = A1;
int MIDDLE_SENSOR_PIN = A2;
int RING_SENSOR_PIN = A3;
int BABY_SENSOR_PIN = A4;

int value;

float angleAdjustment = 1;

Servo THUMB_MOTOR;
Servo INDEX_MOTOR;
Servo MIDDLE_MOTOR;
Servo RING_MOTOR;
Servo BABY_MOTOR;


void setup() {
  THUMB_MOTOR.attach(2);
  INDEX_MOTOR.attach(3);
  MIDDLE_MOTOR.attach(4);
  RING_MOTOR.attach(5);
  BABY_MOTOR.attach(6);
  Serial.begin(9600);
  pinMode(THUMB_SENSOR_PIN, INPUT);
  pinMode(INDEX_SENSOR_PIN, INPUT);
  pinMode(MIDDLE_SENSOR_PIN, INPUT);
  pinMode(RING_SENSOR_PIN, INPUT);
  pinMode(BABY_SENSOR_PIN, INPUT);
}


void loop() {
  float thumbSensor = analogRead(THUMB_SENSOR_PIN);
  float indexSensor = analogRead(INDEX_SENSOR_PIN);
  float middleSensor = analogRead(MIDDLE_SENSOR_PIN);
  float ringSensor = analogRead(RING_SENSOR_PIN);
  float babySensor = analogRead(BABY_SENSOR_PIN);

  Serial.println(thumbSensor);
  
  THUMB_MOTOR.write(1023 - (thumbSensor * angleAdjustment));
  INDEX_MOTOR.write(1023 - (indexSensor * angleAdjustment));
  MIDDLE_MOTOR.write(1023 - (middleSensor * angleAdjustment));
  RING_MOTOR.write(1023 - (ringSensor * angleAdjustment));
  BABY_MOTOR.write(1023 - (babySensor * angleAdjustment));
}
