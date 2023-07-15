#include <MsTimer2.h>
int check = 2;

unsigned long time_current;
unsigned long time_old;
unsigned long time_differnet;

void timer()
{
  time_current = millis();
  time_differnet = time_current - time_old;
  
  digitalWrite(check, HIGH);
  digitalWrite(check, LOW);

  time_old = time_current;
}

void setup()
{
  Serial.begin(115200);
  pinMode(check, OUTPUT);

  MsTimer2::set(50, timer);
  MsTimer2::start();
}

void loop()
{
  Serial.print("Time_differnet: ");
  Serial.println(time_differnet);
}
