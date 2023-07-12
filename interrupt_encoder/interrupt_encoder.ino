const int encoderPinA = 2;
const int encoderPinB = 3;

volatile int count = 0;
volatile int encoderStateB;

unsigned long time_present;
unsigned long time_odd;
unsigned long time_different;

void setup() 
{
  Serial.begin(115200);
  Serial1.begin(115200);    
  pinMode(encoderPinA, INPUT_PULLUP);
  pinMode(encoderPinB, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(encoderPinA), handleEncoderInterrupt, RISING);
}

void loop() 
{
  Serial.println("A: 1");
  
  Serial.print("B: ");
  Serial.println(encoderStateB);

  Serial.print("Count: ");
  Serial.println(count);

  Serial.print("Time_different: ");
  Serial.println(time_different);
  Serial.println(" ");
}

void handleEncoderInterrupt() 
{
  time_present = millis();
  time_different = time_present - time_odd;

  encoderStateB = digitalRead(encoderPinB);

  if (encoderStateB == LOW) 
  {
    count++;
  }
  else
  {
    count--; 
  }

  time_odd = time_present;
  
}
