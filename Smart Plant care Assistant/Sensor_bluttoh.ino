#include <Wire.h>
#include <Adafruit_BH1750.h>
#include <Adafruit_BME280.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SOIL_MOISTURE_PIN 34  // LM393 analog output
Adafruit_BH1750 lightMeter;
Adafruit_BME280 bme;

BLEServer *pServer = NULL;
BLECharacteristic *pCharacteristic = NULL;
bool deviceConnected = false;

#define SERVICE_UUID "12345678-1234-5678-1234-56789abcdef0"
#define CHARACTERISTIC_UUID "abcdef12-3456-789a-bcde-f0123456789a"

// BLE Server Callbacks
class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    deviceConnected = true;
  };
  void onDisconnect(BLEServer* pServer) {
    deviceConnected = false;
  }
};

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  if (!lightMeter.begin()) {
    Serial.println("BH1750 not found");
  }
  if (!bme.begin(0x76)) {
    Serial.println("BME280 not found");
  }

  // Setup BLE
  BLEDevice::init("SmartPlantSensor");
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |
                      BLECharacteristic::PROPERTY_NOTIFY
                    );
  pCharacteristic->addDescriptor(new BLE2902());
  pService->start();
  pServer->getAdvertising()->start();
}

void loop() {
  float lux = lightMeter.readLightLevel();
  float temperature = bme.readTemperature();
  float pressure = bme.readPressure() / 100.0F;
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);

  String data = "L:" + String(lux) + " T:" + String(temperature) + " P:" + String(pressure) + " S:" + String(soilMoisture);
  pCharacteristic->setValue(data.c_str());
  pCharacteristic->notify();

  Serial.println(data);
  delay(2000);
}
