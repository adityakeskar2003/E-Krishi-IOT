#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHT_PIN 2

const int npkSensorPin = A0;
const int moistureSensorPin = A1;
const int phSensorPin = A2;
DHT dht(DHT_PIN, DHT22);


void setup() {
  Serial.begin(9600);
  // Initialize the DHT sensor
  dht.begin();
}

void loop() {
  
  int npkValue = analogRead(npkSensorPin);
  int moistureValue = analogRead(moistureSensorPin);

  // Read temperature and humidity data
  float temperature = dht.readTemperature(); // in Celsius
  float humidity = dht.readHumidity();       // in percentage

  // Read the analog voltage from the pH sensor
  int pHValue = analogRead(phSensorPin);
  // Convert the analog reading to pH value (if needed)
  float phValue = map(pHValue, 0, 1023, 0, 14); // Map the reading to pH 0-14 scale
  
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    delay(1000);
    return;

  // Convert the analog reading to a voltage (if needed)
  float voltage = (float)npkValue * (5.0 / 1023.0); // Assuming a 5V reference voltage
  // Map the sensor value to a moisture level
  int moistureLevel = map(sensorValue, 0, 1023, 0, 100); // 0-100% moisture

  // Print the sensor value and voltage to the serial monitor
  Serial.print("NPK Sensor Value: ");
  Serial.println(npkValue);
  Serial.print("Voltage (V): ");
  Serial.println(voltage);

  // Print the sensor value and moisture level to the serial monitor
  Serial.print(" Moisture Sensor Value: ");
  Serial.println(moistureValue);
  Serial.print("Moisture Level (%): ");
  Serial.println(moistureLevel);

  // Print temperature and humidity to the serial monitor
  Serial.print("Temperature (C): ");
  Serial.println(temperature);
  Serial.print("Humidity (%): ");
  Serial.println(humidity);

// Print the sensor value and pH value to the serial monitor
  Serial.print("pH Sensor Value: ");
  Serial.println(pHValue);
  Serial.print("pH Value: ");
  Serial.println(phValue, 2); // Display pH value with 2 decimal places

  delay(1000); 
}