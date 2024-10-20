#include <SoftwareSerial.h>  // For GSM module communication

const int tempSensorPin = A0;      
const int heartRateSensorPin = A1; 
const int gsmTxPin = 7;            
const int gsmRxPin = 8;            
const int buzzerPin = 6;           

const float tempThreshold = 38.0;  
const int heartRateLow = 60;       
const int heartRateHigh = 100;     

SoftwareSerial gsm(gsmTxPin, gsmRxPin); 

float temperature;
int heartRate;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(tempSensorPin, INPUT);
  pinMode(heartRateSensorPin, INPUT);
  Serial.println("Healthcare System Initialized");
}

void loop() {
  temperature = getTemperature();
  heartRate = getHeartRate();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Heart Rate: ");
  Serial.print(heartRate);
  Serial.println(" BPM");
  
  if (temperature > tempThreshold || heartRate < heartRateLow || heartRate > heartRateHigh) {
    alertEmergency();
  }
  
  delay(5000);  
}

float getTemperature() {
  int tempReading = analogRead(tempSensorPin);
  float voltage = tempReading * (5.0 / 1023.0);
  float tempC = voltage * 100;
  return tempC;
}

int getHeartRate() {
  int heartRateReading = analogRead(heartRateSensorPin);
  int bpm = map(heartRateReading, 0, 1023, 50, 120); 
  return bpm;
}

void alertEmergency() {
  Serial.println("Emergency Detected!");

  digitalWrite(buzzerPin, HIGH);
  delay(500);
  digitalWrite(buzzerPin, LOW);

  gsm.print("AT+CMGF=1\r");
  delay(1000);
  gsm.print("AT+CMGS=\"+1234567890\"\r");  
  delay(1000);
  
  gsm.print("EMERGENCY ALERT!\nTemp: ");
  gsm.print(temperature);
  gsm.print(" °C\nHeart Rate: ");
  gsm.print(heartRate);
  gsm.println(" BPM");

  delay(1000);
  gsm.write(26); 
  delay(5000);

  Serial.println("SMS Sent!");
}
