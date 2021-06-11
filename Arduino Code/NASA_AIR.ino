#include "7-seg.h"
#include "pollution.h"
#include "reg.h"

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  define_segment_pins(12, 11, 10, 9, 8, 7, 6, 5);
  int i = 0;
}

void loop()
{
  s_read();
  s_calculate();
  next_data(dustDensity);
  //s_print();
  s_send();
  dangerCheck();
  s_disp(num, 0);
  delay(1500);
  s_disp(n_num, 1);
  delay(1500);
}
