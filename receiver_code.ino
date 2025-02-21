#include <RH_ASK.h> // FOR AMPLITUDE SHIFT KEYING LIB
#include <SPI.h> // SERIAL PERIPHERAL COMMUNICATION
#include <TM1637Display.h> // LIBRARY FOR 4-DIGIT DISPLAY

RH_ASK rf_driver;

// DEFINING PINS
#define size_of_received_string 10
#define range 200
int buzzerPin = 7;
int relayPin = 8;
int redLED = 4;
int greenLED = 2;
int dt = 1000;

// TM1637 DISPLAY PINS
#define CLK 5  // Clock pin
#define DIO 6  // Data pin
TM1637Display display(CLK, DIO);

void setup() {
    rf_driver.init(); // RF DRIVER INITIALIZED
    pinMode(buzzerPin, OUTPUT);
    pinMode(relayPin, OUTPUT);
    pinMode(redLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    Serial.begin(9600);
    
    display.setBrightness(7); // Set brightness level (0-7)
    display.clear(); // Clear the display
    
    if (!rf_driver.init()) {
        Serial.println("RF driver initialization failed!");
    } else {
        Serial.println("RF receiver ready. Waiting for signal....");
    }
}

void loop() {
    uint8_t buf[size_of_received_string];
    uint8_t buflen = sizeof(buf);
    
    if (rf_driver.recv(buf, &buflen)) {
        // Store received data as a string
        String receivedData = "";
        for (uint8_t i = 0; i < buflen; i++) {
            receivedData += (char)buf[i];
        }

        // Print received string
        Serial.print("Received data (as string): ");
        Serial.println(receivedData);

        // Convert to integer
        int numberReceived = receivedData.toInt();
        Serial.print("Converted to integer: ");
        Serial.println(numberReceived);
        
        // Display number on 4-digit 7-segment display
        display.showNumberDec(numberReceived);
        
        // Control LED, buzzer, and relay based on received value
        if (numberReceived > range) {
            digitalWrite(redLED, HIGH);
            digitalWrite(greenLED, LOW);
            digitalWrite(buzzerPin, HIGH);
            digitalWrite(relayPin, HIGH);
        } else {
            digitalWrite(redLED, LOW);
            digitalWrite(greenLED, HIGH);
            digitalWrite(buzzerPin, LOW);
            digitalWrite(relayPin, LOW);
        }
        
        delay(dt);
    }
}
