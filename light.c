#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LDR_PIN 29  // GPIO 27
#define R_PIN   23  // GPIO 13 | Red Led pin
#define Y_PIN   24  // GPIO 19 | Yellow Led pin
#define G_PIN   25  // GPIO 26 | Green Led pin
	
uint32_t lightLevel(int pin) {
	uint32_t reading = 0;
	pinMode(LDR_PIN, OUTPUT);
	digitalWrite(LDR_PIN, LOW);
	delay(1000);
	
	pinMode(LDR_PIN, INPUT);
	
	while(digitalRead(LDR_PIN) == LOW) {
		reading++;
	}
    return reading;
}

void main() {

    if(wiringPiSetup() == -1) {
        exit(1);
    }

    pinMode(R_PIN, OUTPUT);
    pinMode(Y_PIN, OUTPUT);
    pinMode(G_PIN, OUTPUT);

    uint32_t reading;
    while(TRUE) {
        reading = lightLevel(LDR_PIN);
        if(reading < 1000) {
            // Yeşil ışık
        }
        else if (reading > 8000) {
            // Sarı ışık
        }
        else {
            // Kırmızı ışık
        }
        printf("%u\n", reading);
    }
}