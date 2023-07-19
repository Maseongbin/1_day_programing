
#include <LSM303.h>
#include <Wire.h>

#define EncoderAPin 2
#define EncoderBPin 3
#define pulse2_m 0.000488

LSM303 compass;

const unsigned long width = 100; 

volatile int counter = 0;

volatile int encoderB;

double angle = 0.0;

unsigned long current_time;
unsigned long time_old;
unsigned long time_different;

unsigned long previous_Millis = 0;

void Encoder()
{
  current_time = millis();
  time_different = current_time - time_old;

  encoderB = digitalRead(EncoderBPin);

  if (encoderB == LOW) 
  {
    counter++;
  }
  else 
  {                 
    counter--;
  }
  time_old = current_time;
}

void setup()
{
  Serial.begin(115200);

  pinMode(EncoderAPin, INPUT_PULLUP);
  pinMode(EncoderBPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(EncoderAPin), Encoder, RISING);
  
  Wire.begin(); //IMU initiallize
  compass.init();
  compass.enableDefault();

   /*
  Calibration values; the default values of +/-32767 for each axis
  lead to an assumed magnetometer bias of 0. Use the Calibrate example
  program to determine appropriate values for your particular unit.
  */
  compass.m_min = (LSM303::vector<int16_t>){-32767, -32767, -32767};
  compass.m_max = (LSM303::vector<int16_t>){+32767, +32767, +32767};
}

void loop()
{
  unsigned long current_Millis = millis();

  if (current_Millis - previous_Millis >= width)
  {
    previous_Millis = current_Millis;
  }

  Serial.print("Pulse_counter: "); 
  Serial.println(counter);
  Serial.print("Wheel_tick: "); 
  Serial.println((counter * pulse2m));

}
