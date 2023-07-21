#include <LSM303.h>
#include <Wire.h>
#include <math.h>

#define EncoderAPin 2
#define EncoderBPin 3
#define pulse2m 0.000488

#define RAD2DEG(x) (x * 180 / M_PI)
#define DEG2RAD(x) (x / 180 * M_PI)

const unsigned long width = 100;

volatile int counter = 0;
volatile int encoderB;

double angle = 0.0;
double angle_old = 0.0;
double angle_diff = 0.0;

double distance = 0.0;
double encoder_current;
double encoder_old;
double odometry_x = 0.0; 
double odometry_y = 0.0; 

unsigned long enc_time;
unsigned long enc_time_old;
unsigned long enc_time_diff;

unsigned long previousMillis = 0;

bool flag = 0;

// pulse:410

LSM303 compass;

void Encoder()
{
  enc_time = millis();
  enc_time_diff = enc_time - enc_time_old;

  encoderB = digitalRead(EncoderBPin);

  if (encoderB == HIGH)
  { // ccw
    counter++;
  }
  else
  { // cw
    counter--;
  }
  enc_time_old = enc_time;

  encoder_current = counter;
  encoder_old = encoder_current;
  distance = encoder_current - encoder_old;
}

void Odometry()
{
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= width)
  {
    compass.read();

    double heading_angle = atan2(compass.a.x, compass.a.y);
    angle_diff = heading_angle - angle_old;
    angle_old = heading_angle;

    double L = counter * pulse2m;

    double delta_theta = DEG2RAD(angle_diff);

    double r = L / delta_theta;

    double delta_x, delta_y;
    if (angle_diff >= 0)
    {
      delta_x = r * sin(delta_theta);
      delta_y = r - (r * cos(delta_theta));
    }
    else
    {
      delta_x = r * sin(fabs(delta_theta));
      delta_y = -(r - (r * cos(fabs(delta_theta))));
    }

    odometry_x += delta_x;
    odometry_y += delta_y;

    previousMillis = currentMillis;
  }
}

void setup()
{
  Serial.begin(115200);
  Wire.begin();
  compass.init();

  pinMode(EncoderAPin, INPUT_PULLUP);
  pinMode(EncoderBPin, INPUT_PULLUP);

  compass.enableDefault();

  attachInterrupt(digitalPinToInterrupt(EncoderAPin), Encoder, RISING);
}

void loop()
{
 
  Serial.print("Heading_Angle = ");
  Serial.print(RAD2DEG(angle_old)); 
  Serial.print(" deg, Delta_Angle = ");
  Serial.print(RAD2DEG(angle_diff)); 
  Serial.print(" deg, Pulse_counter: ");
  Serial.print(counter);
  Serial.print(", Wheel_tick: ");
  Serial.print(counter * pulse2m);
  Serial.print(", Distance: ");
  Serial.print(distance);
  Serial.print(", Odometry X: ");
  Serial.print(odometry_x);
  Serial.print(", Odometry Y: ");
  Serial.println(odometry_y);
}
