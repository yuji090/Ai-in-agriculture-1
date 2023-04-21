#include <DHT.h>                 // Include the DHT library

#define DHT_PIN 2     // DHT11 data pin
#define BUZZER_PIN 3 // Buzzer pin

DHT dht(DHT_PIN, DHT11);   // Initialize DHT11 sensor

void setup(void) {
  Serial.begin(9600);   // Initialize serial communication
  dht.begin();   // Initialize DHT11 sensor
  pinMode(BUZZER_PIN, OUTPUT);   // Set buzzer pin as OUTPUT
}

void loop(void) {
  // Read temperature value in Celsius from DHT11 sensor
  float temperatureC = dht.readTemperature();

  // Print temperature value to serial monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println("°C");

  // If temperature is above 38°C, activate the buzzer
  if (temperatureC > 38) {
    digitalWrite(BUZZER_PIN, HIGH);   // Turn on the buzzer
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Turn off the buzzer
  }

  delay(1000);   // Delay for 1 second
}