#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <BH1750.h>

#define SOIL_MOISTURE_ANALOG_PIN 4  // Analog pin for soil moisture sensor

Adafruit_BME280 bme;
BH1750 lightMeter;

void setup() {
    Serial.begin(115200);
    Wire.begin(6, 7); // SDA on GPIO6, SCL on GPIO7

    // Initialize BH1750
    if (!lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
        Serial.println("Error initializing BH1750!");
    }

    // Initialize BME280
    if (!bme.begin(0x76)) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
}

void loop() {
    float temperature = bme.readTemperature();
    float pressure = bme.readPressure() / 100.0F;  // Convert to hPa
    float humidity = bme.readHumidity();
    float lux = lightMeter.readLightLevel();
    int soilMoisture = analogRead(SOIL_MOISTURE_ANALOG_PIN);

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" hPa");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    Serial.print("Light Intensity: ");
    Serial.print(lux);
    Serial.println(" lx");

    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);

    Serial.println("-----------------------------");
    delay(2000);
}
