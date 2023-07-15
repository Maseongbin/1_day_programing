const int encoderPinA = 2;
const int encoderPinB = 3;

volatile int count = 0;
volatile int encoderStateB;

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
  Serial.print("A: ");
  Serial.print(1);
  Serial.print("  B: ");
  Serial.println(encoderStateB);
  Serial.write('\t');
  Serial.println();  

  Serial.print("Count: ");
  Serial.println(count);
}

void handleEncoderInterrupt() 
{
  encoderStateB = digitalRead(encoderPinB);

  if (encoderStateB == LOW) 
  {
    count++;
  }
  else if(encoderStateB == HIGH)
  {
    count--; 
  }
  else
  {
    
  }
  
  
}
