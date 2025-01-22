#include <Arduino.h>
 
const int VOUT1_PIN = 1; // analog 0

const int VOUT2_PIN = 2; // analog 1
 
void setup() {

    Serial.begin(115200); // Start serial communication
    adcAttachPin(VOUT1_PIN); // Attach VOUT1_PIN for ADC input

    adcAttachPin(VOUT2_PIN); // Attach VOUT2_PIN for ADC input

    analogSetAttenuation(ADC_11db); // Set ADC attenuation to measure voltages up to 3.3V

}
 
void loop() {

    int adc1 = analogRead(VOUT1_PIN); // Read ADC value from VOUT1_PIN

    int adc2 = analogRead(VOUT2_PIN); // Read ADC value from VOUT2_PIN

    // Convert ADC readings to voltage (assuming 3.3V reference voltage)

    float voltage1 = (adc1 / 4095.0) * 3.3;

    float voltage2 = (adc2 / 4095.0) * 3.3;

    // Output voltage readings to Serial Monitor

    Serial.print("VOUT1: ");

    Serial.print(voltage1);

    Serial.println(" V (Voltage)");

    Serial.print("VOUT2: ");

    Serial.print(voltage2);

    Serial.println(" V (Voltage)");

    Serial.println(""); // Add an empty line for readability

    delay(1000); // Delay for 1 second before repeating the loop

}
 