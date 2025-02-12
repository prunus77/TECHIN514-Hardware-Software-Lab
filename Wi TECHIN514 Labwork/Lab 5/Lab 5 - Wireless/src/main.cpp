#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 5; // In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks : public BLEAdvertisedDeviceCallbacks {
    void onResult(BLEAdvertisedDevice advertisedDevice) {
        Serial.printf("Advertised Device: %s \n", advertisedDevice.toString().c_str());
    }
};

void setup() {
    Serial.begin(115200);
    Serial.println("Scanning...");

    BLEDevice::init("");
    pBLEScan = BLEDevice::getScan(); // Create new scan
    pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
    pBLEScan->setActiveScan(true); // Active scan uses more power but gets results faster
    pBLEScan->setInterval(100);
    pBLEScan->setWindow(99);  // Must be less than or equal to setInterval value
}

void loop() {
    Serial.println("Starting BLE scan...");
    
    // Corrected: Dereference the pointer to match non-pointer type
    BLEScanResults scanResults = *pBLEScan->start(scanTime, false);

    Serial.print("Devices found: ");
    Serial.println(scanResults.getCount()); // Using scanResults directly

    Serial.println("Scan done!");

    pBLEScan->clearResults();  // Delete results from BLEScan buffer to release memory

    delay(10000);
}