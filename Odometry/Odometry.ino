
#define EncoderAPin 2
#define EncoderBPin 3

const unsigned long width = 100; // 100 ms (10 Hz)

volatile int counter = 0;
volatile int encoderB;

double angle = 0.0;

unsigned long enc_time;
unsigned long enc_time_old;
unsigned long enc_time_diff;

unsigned long previous_Millis = 0;

void Encoder()
{
  enc_time = millis();
  enc_time_diff = enc_time - enc_time_old;

  encoderB = digitalRead(EncoderBPin);

  if (encoderB == LOW) {    // ccw
    counter++;
  }
  else {                    // cw
    counter--;
  }
  enc_time_old = enc_time;
}

void setup()
{
  Serial.begin(115200);
 
  pinMode(EncoderAPin, INPUT_PULLUP);
  pinMode(EncoderBPin, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(EncoderAPin), Encoder, RISING);

}

void loop()
{
  unsigned long current_Millis = millis();

  if (current_Millis - previous_Millis >= width)
  {
   

    previous_Millis = current_Millis;
  }
  Serial.print("Heading_Angle = "); Serial.println(mpu6050.getAngleZ());
  Serial.print("Pulse_counter: "); Serial.println(counter);
  Serial.print("Wheel_trick: "); Serial.println((counter * pulse2m));

}
