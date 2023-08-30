

const int THUMB_SENSOR_PIN = A0;
const float VCC = 4.98;    // Measured voltage of Ardunio 5V line
const float R_DIV = 300.0; // Measured resistance of 3.3k resistor

const float STRAIGHT_RESISTANCE = 37300.0; // resistance when straight
const float BEND_RESISTANCE = 90000.0;     // resistance at 90 deg

void setup()
{
    Serial.begin(9600);
    pinMode(THUMB_SENSOR_PIN, INPUT);
}

float getRegistance(float sensorValue)
{
    float flexV = sensorValue * VCC / 1023.0;
    float flexR = R_DIV * (VCC / flexV - 1.0);

    return flexR;
}

float getAngle(float registance)
{
    float angle = map(registance, STRAIGHT_RESISTANCE, BEND_RESISTANCE, 0, 90.0);

    return angle;
}

void loop()
{
    float thumbSensor = analogRead(THUMB_SENSOR_PIN);

    Serial.println(String(thumbSensor));
    Serial.println(String(getRegistance(thumbSensor)) + "ohms");
    Serial.println(String(getAngle(getRegistance(thumbSensor))) + "degrees");
    delay(500);
}