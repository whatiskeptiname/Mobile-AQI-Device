const int dustPin = A5;  // dust sensor - Arduino A5 pin
const int ledPin = 2;    // IRED pin - 2
const int buzzerPin = 3 ; //buzzer pin - 3

float voltsMeasured = 0; //raw voltage data from sensor
float calcVoltage = 0;   //refined voltage data range (0-5)volts
float dustDensity = 0;   //dust density measured with refrence to refined voltage
char data;               //data received form bluetooth
int num;                 //data mapped 0 to 9

void s_read()
{
  digitalWrite(ledPin, LOW); //   power on the LED
  delayMicroseconds(300);

  voltsMeasured = analogRead(dustPin); // read the dust value

  delayMicroseconds(40);
  digitalWrite(ledPin, HIGH); // turn the LED off
  delayMicroseconds(9680);

  if (Serial.available())
  {
    data = Serial.read();
    Serial.println(data);
  }
}

void s_calculate()
{
  //measure your 5v and change below
  calcVoltage = voltsMeasured * (5.0 / 1024.0);
  dustDensity = 170 * ( calcVoltage - 0.3);

  num = map(dustDensity, 0, 600, 0, 10);
}

void s_print()
{
  Serial.println("GP2Y1010AU0F readings");
  Serial.print("Raw Signal Value = ");
  Serial.println(voltsMeasured);
  Serial.print("Voltage = ");
  Serial.println(calcVoltage);
  Serial.print("Dust Density = ");
  Serial.println(dustDensity); // ug/m3
  Serial.println("");
}
void s_send()
{
  Serial.println(dustDensity);
}

void dangerCheck()
{
  if (dustDensity >= 220)
  {
    tone(buzzerPin, 800);
    delay(91);
    noTone(buzzerPin);
  }
}
