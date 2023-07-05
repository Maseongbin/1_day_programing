

#include <MsTimer2.h> //MsTimer2 라이브러리: interrupt를 사용하여 일정 주기로 함수 호출

const int led_pin = LED_BUILTIN; //LED_BULLTIN: Arduino 보드에 내장된 LED, 13번과 연결되어 있다.

void flash() //LED를 깜빡이는 동작을 수행하는 함수
{
  static boolean output = HIGH;
  
  digitalWrite(led_pin, output); //연결된 핀에 output값 출력 >>> LED의 상태 제어

  Serial.print("LED: "); // 시리얼 모니터에 출력
  Serial.println(output); // LED 상태 출력
  
  output = !output; //변수의 값 반전 >>> LED의 다음 상태를 결정
}

void setup()
{
  pinMode(led_pin, OUTPUT); // 핀을 출력 모드로 설정

  MsTimer2::set(1000, flash); //1000ms 마다 flash 함수 호출
  MsTimer2::start(); //MsTimer2 interrupt 실행

   Serial.begin(9600); // 시리얼 통신 시작
}
void loop() 
{
  
}
