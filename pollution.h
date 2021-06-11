static const uint8_t D8   = 15;
const int ledPin = D8;    // IRED pin
static const uint8_t D9   = 3;
const int buzzerPin =D9;
const int dustPin = A0;  // dust sensor - node A0 pin

float voltsMeasured = 0; //raw voltage data from sensor
float calcVoltage = 0;   //refined voltage data range (0-5)volts
float dustDensity = 0;   //dust density measured with refrence to refined voltage
char data;               //data received form bluetooth
int num;                 //data mapped 0 to 9

void s_read() //read data from the sensor
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

void s_calculate() // calculate the pollution density
{
  //measure your 5v and change below
  calcVoltage = voltsMeasured * (5.0 / 1024.0); //formula for voltage calculation
  dustDensity = 170 * ( calcVoltage -0.0); //0.0 for calibration

  num = map(dustDensity, 0, 700, 0, 10);// mapping of dust density between 0-10
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
void s_send() //for streaming to bluetooth device
{
  Serial.println(dustDensity);
}

void dangerCheck() //For buzzer 
{
  if (dustDensity >= 220)
  {
    tone(buzzerPin, 800);
    delay(91);
    noTone(buzzerPin);
  }
}
